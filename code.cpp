#include<bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 5;
vector<pair<int,long long> >adj[MaxN];
vector<int> d;

void diji(int source,int n)
{
    d.assign(n,INT_MAX);
    d[source] = 0;
    queue<pair<int,int>> q;
    q.push({source,0});

    while(!q.empty()){
        int u = q.front().first;
        int w = q.front().second;

        if(u == n) break;

        int sizz = adj[u].size();

        for(int i=0;i<sizz;i++){
            int to = adj[u][i].first;
            int we = adj[u][i].second;

            if(d[to] > d[u]+we){
                d[to] = d[u]+we;
                q.push({to,d[to]});
            }
        }
        q.pop();
    }
}

int main()
{
    int n;
    cin>>n;

    int m;
    cin>>m;

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    int source;
    cin>>source;
    diji(source,n);

    printf("\n printing the shortest paths that has been calculated with diji algo\n");
    for(int i=0;i<n;i++){
        cout<<source<<" --> "<<i<<" = "<<d[i]<<endl;
    }
    cout<<endl;
}
