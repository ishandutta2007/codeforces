#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to;
}e[200001];
vector<int> v[200001];
int n,m,tot,h[200001],dis[200001],p,node[200001],maxn,minn;
bool vis[200001];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dijkstra()
{
    queue<pair<int,int> > q;
    q.push(make_pair(0,node[p]));
    while(!q.empty())
    {
        pair<int,int> k=q.front();
        q.pop();
        if(vis[k.second])
            continue;
        vis[k.second]=1;
        dis[k.second]=k.first;
        for(register int i=h[k.second];i;i=e[i].nxt)
            if(!vis[e[i].to])
                q.push(make_pair(k.first+1,e[i].to));
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(y,x);
        v[x].push_back(y);
    }
    scanf("%d",&p);
    for(register int i=1;i<=p;++i)
        scanf("%d",&node[i]);
    dijkstra();
    for(register int i=1;i<p;++i)
        if(dis[node[i]]!=dis[node[i+1]]+1)
        {
            ++minn;
            ++maxn;
        }
        else
            for(register int j=0;j<(int)(v[node[i]].size());++j)
                if(v[node[i]][j]!=node[i+1]&&dis[node[i]]==dis[v[node[i]][j]]+1)
                {
                    ++maxn;
                    break;
                }
    printf("%d %d\n",minn,maxn);
    return 0;
}