#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int t,n,m,dfn[200001],d[200001],a[200001],tot,node;
bool vis[200001];
vector<pair<int,int> > v[200001];
vector<int> g[200001];
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
    return (dfn[x.first]>dfn[node])^(dfn[y.first]>dfn[node])? dfn[x.first]>dfn[node]:dfn[x.first]<dfn[y.first];
}
inline void topo()
{
    queue<int> q;
    for(int i=1;i<=m;++i)
        if(!d[i])
            q.emplace(i);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        cout<<k<<" ";
        for(int i:g[k])
            if(!--d[i])
                q.emplace(i);
    }
    cout<<'\n';
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].emplace_back(y,i);
        v[y].emplace_back(x,i);
    }
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            tot=0;
            for(int j=i;!vis[j];j=a[j])
            {
                vis[j]=1;
                dfn[j]=++tot;
            }
        }
    for(int i=1;i<=n;++i)
    {
        node=i;
        sort(v[i].begin(),v[i].end(),cmp);
        for(int j=0;j<(int)v[i].size()-1;++j)
        {
            g[v[i][j].second].emplace_back(v[i][j+1].second);
            ++d[v[i][j+1].second];
        }
    }
    topo();
    return 0;
}