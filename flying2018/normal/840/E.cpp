#include<iostream>
#include<cstdio>
#include<cstring>
#define N 50010
#define B 256
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
int f[N][B],dep[N],fa[N],ffa[N],w[N];
void dfs(int u,int p)
{
    fa[u]=p;
    dep[u]=dep[p]+1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        dfs(v,u);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        int u=i;
        for(int j=0;j<B && u;j++,u=fa[u]) f[i][(B-1)^((w[u]^j)>>8)]=max(f[i][(B-1)^((w[u]^j)>>8)],(w[u]^j)|((B-1)<<8));
        ffa[i]=u;
        for(int j=0;j<8;j++)
            for(int k=0;k<B;k++)
            if(f[i][k^(1<<j)]) f[i][k]=max(f[i][k],f[i][k^(1<<j)]^(1<<(j+8)));
    }
    while(m --> 0)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int ans=w[u]^(dep[v]-dep[u]),x=v;
        for(int i=0;dep[u]<=dep[ffa[x]];i++,x=ffa[x]) ans=max(ans,f[x][i]);
        for(;dep[u]<=dep[x];x=fa[x]) ans=max(ans,(dep[v]-dep[x])^w[x]);
        printf("%d\n",ans);
    }
    return 0;
}