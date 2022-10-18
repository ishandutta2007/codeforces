#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
const int mod0=998244853,mod1=998244353;
struct edge
{
    int nxt,to,weight;
}e[100001];
int n,m,s,t,h[100001],tot,dis[2][100001],cnt[100001][2][2],sum[2];
struct element
{
    int x,y,w;
}a[100001];
bool vis[100001];
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
inline void dijkstra(int id,int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    for(int i=1;i<=n;++i)
    {
        dis[id][i]=1e18;
        vis[i]=0;
    }
    q.emplace(0,s);
    dis[id][s]=0;
    cnt[s][id][0]=cnt[s][id][1]=1;
    while(!q.empty())
    {
        pair<int,int> k=q.top();
        q.pop();
        if(vis[k.second])
            continue;
        vis[k.second]=1;
        for(int i=h[k.second];i;i=e[i].nxt)
            if(!vis[e[i].to])
            {
                if(dis[id][e[i].to]>dis[id][k.second]+e[i].weight)
                {
                    dis[id][e[i].to]=dis[id][k.second]+e[i].weight;
                    cnt[e[i].to][id][0]=cnt[k.second][id][0];
                    cnt[e[i].to][id][1]=cnt[k.second][id][1];
                    q.emplace(dis[id][e[i].to],e[i].to);
                }
                else if(dis[id][e[i].to]==dis[id][k.second]+e[i].weight)
                {
                    cnt[e[i].to][id][0]=(cnt[e[i].to][id][0]+cnt[k.second][id][0])%mod0;
                    cnt[e[i].to][id][1]=(cnt[e[i].to][id][1]+cnt[k.second][id][1])%mod1;
                }
            }
    }
}
signed main()
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i].x>>a[i].y>>a[i].w;
        add(a[i].x,a[i].y,a[i].w);
    }
    dijkstra(0,s);
    sum[0]=cnt[t][0][0];
    sum[1]=cnt[t][0][1];
    tot=0;
    for(int i=1;i<=n;++i)
        h[i]=0;
    for(int i=1;i<=m;++i)
        add(a[i].y,a[i].x,a[i].w);
    dijkstra(1,t);
    for(int i=1;i<=m;++i)
    {
        if(dis[0][a[i].x]+a[i].w+dis[1][a[i].y]==dis[0][t])
        {
            if(1ll*cnt[a[i].x][0][0]*cnt[a[i].y][1][0]%mod0==sum[0]&&1ll*cnt[a[i].x][0][1]*cnt[a[i].y][1][1]%mod1==sum[1])
                cout<<"YES\n";
            else
                if(a[i].w==1)
                    cout<<"NO\n";
                else
                    cout<<"CAN 1\n";
        }
        else
        {
            int val=dis[0][a[i].x]+a[i].w+dis[1][a[i].y]-dis[0][t]+1;
            if(a[i].w>val)
                cout<<"CAN "<<val<<'\n';
            else
                cout<<"NO\n";
        }
    }
    return 0;
}