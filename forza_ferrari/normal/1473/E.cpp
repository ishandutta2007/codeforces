#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
struct edge
{
    int nxt,to,weight;
}e[200001<<5];
int n,m,tot,h[200001<<2],dis[200001<<2];
bool vis[200001<<2];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
inline void dijkstra()
{
    for(int i=1;i<=n;++i)
        dis[i]=dis[i+n]=dis[i+2*n]=dis[i+3*n]=1e18;
    dis[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.emplace(0,1);
    while(!q.empty())
    {
        pair<int,int> k=q.top();
        q.pop();
        if(vis[k.second])
            continue;
        vis[k.second]=1;
        for(int i=h[k.second];i;i=e[i].nxt)
            if(!vis[e[i].to]&&dis[e[i].to]>dis[k.second]+e[i].weight)
            {
                dis[e[i].to]=dis[k.second]+e[i].weight;
                q.emplace(dis[e[i].to],e[i].to);
            }
    }
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read(),w=read();
        for(int j=0;j<4;++j)
        {
            add(x+j*n,y+j*n,w);
            add(y+j*n,x+j*n,w);
        }
        add(x,y+n,0);
        add(y,x+n,0);
        add(x,y+2*n,w<<1);
        add(y,x+2*n,w<<1);
        add(x,y+3*n,w);
        add(y,x+3*n,w);
        add(x+n,y+3*n,w<<1);
        add(y+n,x+3*n,w<<1);
        add(x+2*n,y+3*n,0);
        add(y+2*n,x+3*n,0);
    }
    dijkstra();
    for(int i=2;i<=n;++i)
        cout<<dis[i+3*n]<<" ";
    cout<<'\n';
    return 0;
}