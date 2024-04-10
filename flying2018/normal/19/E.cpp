#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define D 21
using namespace std;
int nxt[N<<1],to[N<<1],id[N<<1],head[N],cnt;
void add(int u,int v,int id1){nxt[++cnt]=head[u];to[cnt]=v;id[cnt]=id1;head[u]=cnt;}
int f[N][D],rfa[N],dep[N];
bool vis[N];
void dfs(int u,int fa)
{
    vis[u]=true;
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;(1<<i-1)<=dep[u];i++)
    f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==fa) continue;
        rfa[v]=id[i];
        dfs(v,u);
    }
}
int lca(int x,int y)
{
    for(int i=D-1;i>=0;i--)
    {
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
        if(dep[f[y][i]]>=dep[x]) y=f[y][i];
    }
    if(x==y) return x;
    for(int i=D-1;i>=0;i--)
    if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
struct road{
    int x,y,id;
}w[N];
int fa[N];
int find(int x){return x==fa[x]?fa[x]:(fa[x]=find(fa[x]));}
int ids,od,dt[N];
int ans[N],tot;
int dfs2(int u)
{
    vis[u]=false;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==f[u][0]) continue;
        dt[u]+=dfs2(v);
    }
    return dt[u];
}
int main()
{
    int n,m,k=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int hx=find(x),hy=find(y);
        if(hx==hy) w[++k]=(road){x,y,i};
        else
        {
            add(x,y,i),add(y,x,i);
            fa[hx]=hy;
        }
    }
    for(int i=1;i<=n;i++)
    if(!vis[i]) dfs(i,0);
    for(int i=1;i<=k;i++)
    {
        int x=w[i].x,y=w[i].y,d=lca(x,y);
        int l=dep[x]+dep[y]-2*dep[d];
        if(l&1) dt[x]--,dt[y]--,dt[d]+=2;
        else ++od,ids=w[i].id,dt[x]++,dt[y]++,dt[d]-=2;
    }
    for(int i=1;i<=n;i++)
    if(vis[i]) dfs2(i);
    if(!od) for(int i=1;i<=m;i++) ans[++tot]=i;
    else for(int i=1;i<=n;i++) if(dt[i]==od) ans[++tot]=rfa[i];
    if(od==1) ans[++tot]=ids;
    sort(ans+1,ans+tot+1);
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++) printf("%d ",ans[i]); 
    return 0;
}