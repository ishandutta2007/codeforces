#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
struct edge
{
    int nxt,to;
}e[100001<<1];
struct edges
{
    int x,y;
}v[100001];
int n,m,tot,cnt,id[100001],dep[100001],fa[100001],s[100001],son[100001],top[100001],h[100001];
bool ans[100001<<2],w[100001];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
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
    ans[k]=ans[ls(k)]&&ans[rs(k)];
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        ans[k]=w[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
void update(int pos,int l,int r,int k,bool p)
{
    if(l==r)
    {
        ans[k]=p;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        update(pos,l,mid,ls(k),p);
    else
        update(pos,mid+1,r,rs(k),p);
    push_up(k);
}
bool query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return ans[k];
    bool res=1;
    int mid=(l+r)>>1;
    if(nl<=mid)
        res=res&&query(nl,nr,l,mid,ls(k));
    if(nr>mid)
        res=res&&query(nl,nr,mid+1,r,rs(k));
    return res;
}
void dfs1(int k,int f,int deep)
{
    fa[k]=f;
    s[k]=1;
    dep[k]=deep;
    int maxson=-1;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k,deep+1);
        s[k]+=s[e[i].to];
        if(s[e[i].to]>maxson)
        {
            maxson=s[e[i].to];
            son[k]=e[i].to;
        }
    }
}
void dfs2(int k,int t)
{
    id[k]=++cnt;
    w[cnt]=1;
    top[k]=t;
    if(!son[k])
        return;
    dfs2(son[k],t);
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==fa[k]||e[i].to==son[k])
            continue;
        dfs2(e[i].to,e[i].to);
    }
}
inline int q(int x,int y)
{
    int res=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        if(!query(id[top[x]],id[x],1,n,1)/*||!w[id[top[x]]]*/)
            return -1;
        res+=id[x]-id[top[x]]+1;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    if(!query(id[x]+1,id[y],1,n,1))
        return -1;
    res+=id[y]-id[x];
    return res;
}
signed main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        v[i].x=read(),v[i].y=read();
        add(v[i].x,v[i].y);
        add(v[i].y,v[i].x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    m=read();
    while(m--)
    {
        int opt=read(),x,y;
        if(opt==1)
        {
            x=read();
            if(dep[v[x].x]>dep[v[x].y])
                swap(v[x].x,v[x].y);
            update(id[v[x].y],1,n,1,1);
            //w[max(id[v[x].x],id[v[x].y])]=1;
        }
        if(opt==2)
        {
            x=read();
            if(dep[v[x].x]>dep[v[x].y])
                swap(v[x].x,v[x].y);
            update(id[v[x].y],1,n,1,0);
            //w[max(id[v[x].x],id[v[x].y])]=0;
        }
        if(opt==3)
        {
            x=read(),y=read();
            printf("%lld\n",q(x,y));
        }
    }
    return 0;
}