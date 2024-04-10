#include<iostream>
#include<cstdio>
using namespace std;
struct edge
{
    int nxt,to;
}e[100001<<1];
int n,m,tot,h[100001],dep[100001],fa[100001],s[100001],son[100001],dfn[100001],cnt,w[100001],top[100001],minn[100001<<2],val[100001<<2],ans[100001<<2],sum[100001<<2];
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
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void push_up(int k)
{
    minn[k]=min(minn[ls(k)],minn[rs(k)]);
    sum[k]=min(sum[ls(k)],sum[rs(k)]);
    val[k]=max(val[ls(k)],val[rs(k)]);
    ans[k]=min(ans[ls(k)],ans[rs(k)]);
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=minn[k]=1e9;
        val[k]=w[l];
        ans[k]=minn[k]-val[k];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update1(int node,int l,int r,int k,int p)
{
    if(l==r)
    {
        minn[k]=min(minn[k],p);
        ans[k]=minn[k]-val[k];
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update1(node,l,mid,ls(k),p);
    if(node>mid)
        update1(node,mid+1,r,rs(k),p);
    push_up(k);
}
inline void update2(int node,int l,int r,int k,int p)
{
    if(l==r)
    {
        sum[k]=min(sum[k],p);
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update2(node,l,mid,ls(k),p);
    else
        update2(node,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query1(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return ans[k];
    int mid=(l+r)>>1,res=1e9;
    if(nl<=mid)
        res=min(res,query1(nl,nr,l,mid,ls(k)));
    if(nr>mid)
        res=min(res,query1(nl,nr,mid+1,r,rs(k)));
    return res;
}
inline int query2(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return sum[k];
    int mid=(l+r)>>1,res=1e9;
    if(nl<=mid)
        res=min(res,query2(nl,nr,l,mid,ls(k)));
    if(nr>mid)
        res=min(res,query2(nl,nr,mid+1,r,rs(k)));
    return res;
}
inline void up(int x,int p)
{
    update2(dfn[x],1,n,1,p);
    while(x)
    {
        update1(dfn[x],1,n,1,p);
        x=fa[top[x]];
    }
}
inline int q(int x)
{
    int res=query2(dfn[x],dfn[x]+s[x]-1,1,n,1)-(dep[x]<<1);
    while(x)
    {
        res=min(res,query1(dfn[top[x]],dfn[x],1,n,1));
        x=fa[top[x]];
        if(son[x])
            res=min(res,query2(dfn[son[x]],dfn[son[x]]+s[son[x]]-1,1,n,1)-(dep[x]<<1));
    }
    return res;
}
inline void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    fa[k]=f;
    s[k]=1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k,deep+1);
        s[k]+=s[e[i].to];
        if(s[e[i].to]>s[son[k]])
            son[k]=e[i].to;
    }
}
inline void dfs2(int k,int t)
{
    top[k]=t;
    dfn[k]=++cnt;
    w[cnt]=dep[k]<<1;
    if(!son[k])
        return;
    dfs2(son[k],t);
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==fa[k]||e[i].to==son[k])
            continue;
        dfs2(e[i].to,e[i].to);
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    up(1,dep[1]);
    while(m--)
    {
        int opt=read(),x=read();
        if(opt==1)
            up(x,dep[x]);
        if(opt==2)
            cout<<q(x)+dep[x]<<'\n';
    }
    return 0;
}