#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,a[100001],maxn[100001<<2],sum[100001<<2];
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
    sum[k]=sum[ls(k)]+sum[rs(k)];
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=maxn[k]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update1(int nl,int nr,int l,int r,int k,int p)
{
    if(maxn[k]<p)
        return;
    if(l==r)
    {
        sum[k]=maxn[k]=sum[k]%p;
        return;
    }
    int mid=(l+r)>>1;
    if(nl<=mid)
        update1(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update1(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline void update2(int node,int l,int r,int k,int p)
{
    if(l==r)
    {
        sum[k]=maxn[k]=p;
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update2(node,l,mid,ls(k),p);
    else
        update2(node,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return sum[k];
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query(nl,nr,l,mid,ls(k));
    if(nr>mid)
        res+=query(nl,nr,mid+1,r,rs(k));
    return res;
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    build(1,1,n);
    while(m--)
    {
        int opt=read(),l=read(),r=read();
        if(opt==1)
            cout<<query(l,r,1,n,1)<<'\n';
        if(opt==2)
            update1(l,r,1,n,1,read());
        if(opt==3)
            update2(l,1,n,1,r);
    }
    return 0;
}