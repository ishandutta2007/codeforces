#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
struct edge
{
    int nxt,to;
}e[1000001<<1];
int n,m,tot,a[1000005],h[1000005],dfn[1000005],cnt,s[1000005],maxn[1000005<<2],tag[1000005<<2];
stack<int> t;
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
    maxn[k]=max(maxn[ls(k)],maxn[rs(k)]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        maxn[ls(k)]+=tag[k];
        maxn[rs(k)]+=tag[k];
        tag[ls(k)]+=tag[k];
        tag[rs(k)]+=tag[k];
        tag[k]=0;
    }
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        maxn[k]=-1e9;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update1(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
    {
        ++maxn[k];
        ++tag[k];
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update1(nl,nr,l,mid,ls(k));
    if(nr>mid)
        update1(nl,nr,mid+1,r,rs(k));
    push_up(k);
}
inline void update2(int node,int l,int r,int k,int p)
{
    if(l==r)
    {
        maxn[k]=p;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(node<=mid)
        update2(node,l,mid,ls(k),p);
    else
        update2(node,mid+1,r,rs(k),p);
    push_up(k);
}
inline void dfs(int k)
{
    s[k]=1;
    dfn[k]=++cnt;
    for(int i=h[k];i;i=e[i].nxt)
    {
        dfs(e[i].to);
        s[k]+=s[e[i].to];
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        while(!t.empty()&&a[t.top()]<a[i])
        {
            add(i,t.top());
            t.pop();
        }
        t.push(i);
    }
    while(!t.empty())
    {
        add(n+1,t.top());
        t.pop();
    }
    dfs(n+1);
    build(1,1,n+1);
    for(int i=1;i<m;++i)
    {
        update2(dfn[i],1,n+1,1,0);
        update1(dfn[i],dfn[i]+s[i]-1,1,n+1,1);
    }
    for(int i=m;i<=n;++i)
    {
        update2(dfn[i],1,n+1,1,0);
        update1(dfn[i],dfn[i]+s[i]-1,1,n+1,1);
        cout<<maxn[1]<<' ';
        update2(dfn[i-m+1],1,n+1,1,-1e9);
    }
    cout<<'\n';
    return 0;
}