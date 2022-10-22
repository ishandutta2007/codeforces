#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 300010
using namespace std;
vector<int>g[N];
int fa[N],top[N],son[N],siz[N],dep[N];
void dfs0(int u,int p)
{
    fa[u]=p;siz[u]=1;dep[u]=dep[p]+1;
    for(int v:g[u]) if(v!=p)
    {
        dfs0(v,u),siz[u]+=siz[v];
        if(siz[son[u]]<siz[v]) son[u]=v;
    }
}
void dfs1(int u,int topp)
{
    top[u]=topp;
    if(son[u]) dfs1(son[u],topp);
    for(int v:g[u]) if(v!=fa[u] && v!=son[u]) dfs1(v,v);
}
int lca(int x,int y)
{
    for(;top[x]!=top[y];x=fa[top[x]]) if(dep[top[x]]<dep[top[y]]) swap(x,y);
    return dep[x]<dep[y]?x:y;
}
int f[N],d[N];
int find(int x){return x==f[x]?f[x]:(f[x]=find(f[x]));}
bool merge(int x,int y)
{
    x=find(x);y=find(y);
    if(x==y) return false;
    f[x]=y;return true;
}
int a[N],b[N],col[N];
void dfs(int u,int p)
{
    for(int v:g[u]) if(v!=p)
        dfs(v,u),col[u]^=col[v];
}
int ton[N],tp;
int main()
{
    int t=1;
    while(t --> 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1,u,v;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            if(merge(u,v)) g[u].push_back(v),g[v].push_back(u);
        }
        dfs0(1,0);dfs1(1,1);
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++) scanf("%d%d",&a[i],&b[i]),col[a[i]]^=1,col[b[i]]^=1;
        dfs(1,0);
        bool hv=false;
        for(int i=1;i<=n;i++) if(col[i]){hv=true;break;}
        if(hv)
        {
            puts("NO");
            int c=0;
            for(int i=2;i<=n;i++) d[i]+=col[i],d[fa[i]]+=col[i];
            for(int i=1;i<=n;i++) c+=d[i]&1;
            printf("%d\n",c/2);
            return 0;
        }
        puts("YES");
        for(int i=1;i<=q;i++)
        {
            int x=a[i],y=b[i],l=lca(x,y),dis=dep[x]+dep[y]-2*dep[l];
            printf("%d\n",dis+1);
            tp=0;
            for(;x!=l;x=fa[x]) printf("%d ",x);
            for(;y!=l;y=fa[y]) ton[++tp]=y;
            ton[++tp]=l;
            while(tp) printf("%d ",ton[tp--]);
            puts("");
        }
    }
    return 0;
}