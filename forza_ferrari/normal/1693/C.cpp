#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,dis[200001],d[200001];
bool vis[200001];
vector<int> v[200001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
inline void dijkstra()
{
    for(int i=1;i<n;++i)
        dis[i]=0x3f3f3f3f;
    q.emplace(0,n);
    while(!q.empty())
    {
        pair<int,int> k=q.top();
        q.pop();
        if(vis[k.second])
            continue;
        vis[k.second]=1;
        for(auto i:v[k.second])
        {
            if(!vis[i]&&dis[i]>dis[k.second]+d[i])
            {
                dis[i]=dis[k.second]+d[i];
                q.emplace(dis[i],i);
            }
            --d[i];
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        v[y].emplace_back(x);
        ++d[x];
    }
    dijkstra();
    cout<<dis[1]<<'\n';
    return 0;
}