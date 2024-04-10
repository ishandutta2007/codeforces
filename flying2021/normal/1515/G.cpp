#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define N 200010
using namespace std;
int nxt[N<<1],to[N<<1],len[N<<1],head[N],cnt;
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
void add(int u,int v,int w)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;len[cnt]=w;
    head[u]=cnt;
}
int dfn[N],low[N],tt;
int ton[N],tp;
bool in[N];
int id[N];
vector<int>g[N];
void dfs(int u)
{
    dfn[u]=low[u]=++cnt;
    ton[++tp]=u;in[u]=true;
    for(int v:g[u])
        if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
        else if(in[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        id[u]=u;in[u]=false;
        for(int p=ton[tp--];p!=u;p=ton[tp--]) id[p]=u,in[p]=false;
    }
}
ll w[N];bool vis[N];
void solve(int u,ll &res)
{
    vis[u]=true;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(id[v]!=id[u]) continue;
        if(vis[v]) res=gcd(res,llabs(w[u]-w[v]+len[i]));
        else w[v]=w[u]+len[i],solve(v,res);
    }
}
ll res[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(v);
        add(u,v,w),add(v,u,-w);
    }
    for(int i=1;i<=n;i++)
    if(!dfn[i]) dfs(i);
    for(int i=1;i<=n;i++)
    if(id[i]==i) solve(i,res[i]);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
    // if(id[i]==i)printf("%d:%d ",id[i],res[id[i]]);puts("");
    while(q --> 0)
    {
        int v,s,t;scanf("%d%d%d",&v,&s,&t);
        if(s==0){puts("YES");continue;}
        if((t-s)%gcd(res[id[v]],t)) puts("NO");
        else puts("YES");
    }
    return 0;
}