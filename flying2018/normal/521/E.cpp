#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
int fa[N],dep[N];
int res[N],tot;
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(;dep[x]!=dep[y];x=fa[x]);for(;x!=y;x=fa[x],y=fa[y]);
    return x;
}
void print(){printf("%d",tot); for(int i=1;i<=tot;i++) printf(" %d",res[i]); puts("");tot=0;}
void get_pa(int x,int y){for(;x!=y;x=fa[x]) res[++tot]=x; res[++tot]=y;}
void work(int a,int x,int b,int y)
{
    if(dep[x]>dep[y]) swap(a,b),swap(x,y);
    int l=lca(a,b);
    puts("YES");
    get_pa(l,y),reverse(res+1,res+tot+1);print();
    get_pa(y,x),get_pa(a,l);print();
    res[++tot]=y;get_pa(b,l);print();
}
bool vis[N],in[N];
int s1[N],s2[N];
void dfs(int u,int p)
{
    fa[u]=p;
    dep[u]=dep[p]+1;
    in[u]=vis[u]=true;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        if(!vis[v]) dfs(v,u);
        else if(in[v])
        {
            for(int x=u;x!=v;x=fa[x])
            if(s1[x]){work(s1[x],s2[x],u,v);exit(0);} 
            else s1[x]=u,s2[x]=v;
        }
    }
    in[u]=false;
} 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++)
    if(!vis[i]) dfs(i,0);
    puts("NO");
    return 0;
}