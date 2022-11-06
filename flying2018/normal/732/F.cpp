#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 500010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt=1;
int mk[N<<1];
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
vector<int>g[N];
int dfn[N],low[N],idx,msz,mr;
bool vis[N],in[N];
int st[N],tp;
void solve(int u,int p)
{
    dfn[u]=low[u]=++idx;
    st[++tp]=u;
    in[u]=true;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        if(!dfn[v])
        {
            solve(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(in[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        int v=0,sz=0;
        while(1)
        {
            v=st[tp--];
            in[v]=false;++sz;
            if(v==u) break;
        }
        if(sz>msz) mr=u,msz=sz;
    }
}
void dfs(int u)
{
    vis[u]=true;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(vis[v]){mk[i^1]=true,mk[i]=false;continue;}
        if(low[v]!=low[u]) mk[i]=true,mk[i^1]=false;
        else mk[i^1]=true,mk[i]=false;
        dfs(v);
    }
}
int x[N],y[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        add(x[i],y[i]),add(y[i],x[i]);
    }
    solve(1,0);
    dfs(mr);
    printf("%d\n",msz);
    for(int i=1;i<=m;i++)
    if(mk[i*2]) printf("%d %d\n",y[i],x[i]);
    else printf("%d %d\n",x[i],y[i]);
    return 0;
}