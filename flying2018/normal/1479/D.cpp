#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#define N 300010
#define M N*60
#define ull unsigned long long
using namespace std;
ull c[N],val[M];
int a[N],root[M],ls[M],rs[M],tot;
void insert(int &u,int pre,int l,int r,int p)
{
    u=++tot;ls[u]=ls[pre];rs[u]=rs[pre];val[u]=val[pre]^c[p];
    if(l==r) return;
    int mid=(l+r)>>1;
    if(p<=mid) insert(ls[u],ls[pre],l,mid,p);
    else insert(rs[u],rs[pre],mid+1,r,p);
}
int answer(int u1,int u2,int u3,int u4,int l,int r)
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(val[ls[u1]]^val[ls[u2]]^val[ls[u3]]^val[ls[u4]]) return answer(ls[u1],ls[u2],ls[u3],ls[u4],l,mid);
    else return answer(rs[u1],rs[u2],rs[u3],rs[u4],mid+1,r);
}
int qry(int u1,int u2,int u3,int u4,int l,int r,int L,int R)
{
    if((val[u1]^val[u2]^val[u3]^val[u4])==0) return -1;
    if(L<=l && r<=R) return answer(u1,u2,u3,u4,l,r);
    int mid=(l+r)>>1,t=0;
    if(L<=mid) if((t=qry(ls[u1],ls[u2],ls[u3],ls[u4],l,mid,L,R))!=-1) return t;
    if(R>mid) if((t=qry(rs[u1],rs[u2],rs[u3],rs[u4],mid+1,r,L,R))!=-1) return t;
    return -1;
}
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
int fa[N],dep[N],siz[N],son[N];
void dfs1(int u,int p)
{
    fa[u]=p;
    dep[u]=dep[fa[u]]+1;siz[u]=1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        dfs1(v,u);
        if(siz[v]>siz[son[u]]) son[u]=v;
        siz[u]+=siz[v];
    }
}
int nid[N],id[N],top[N],tt,n;
void dfs2(int u,int topp)
{
    top[u]=topp;nid[id[u]=++tt]=u;
    if(son[u]) dfs2(son[u],topp);
    for(int i=head[u];i;i=nxt[i]) if(to[i]!=son[u] && to[i]!=fa[u]) dfs2(to[i],to[i]);
}
int lca(int u,int v)
{
    for(;top[u]!=top[v];u=fa[top[u]]) if(dep[top[u]]<dep[top[v]]) swap(u,v);
    return dep[u]<dep[v]?u:v;
}
void solve(int u)
{
    insert(root[u],root[fa[u]],1,n,a[u]);
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==fa[u]) continue;
        solve(v);
    }
}
int main()
{
    srand(time(0));
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) c[i]=((ull)rand()<<32|(ull)rand())^(101926+rand());
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs1(1,0);dfs2(1,1);
    solve(1);
    for(int i=1;i<=m;i++)
    {
        int x,y,l,r;
        scanf("%d%d%d%d",&x,&y,&l,&r);
        int c=lca(x,y),d=fa[c];
        printf("%d\n",qry(root[x],root[y],root[c],root[d],1,n,l,r));
    }
    return 0;
}