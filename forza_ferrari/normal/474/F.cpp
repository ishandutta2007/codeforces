#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100001],g[100001<<2],minn[100001<<2],cnt[100001<<2];
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
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
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
    g[k]=gcd(g[ls(k)],g[rs(k)]);
    minn[k]=min(minn[ls(k)],minn[rs(k)]);
    cnt[k]=(minn[k]==minn[ls(k)]? cnt[ls(k)]:0)+(minn[k]==minn[rs(k)]? cnt[rs(k)]:0);
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        g[k]=minn[k]=a[l];
        cnt[k]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline int query1(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return g[k];
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query1(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query1(nl,nr,mid+1,r,rs(k));
    return gcd(query1(nl,nr,l,mid,ls(k)),query1(nl,nr,mid+1,r,rs(k)));
}
inline pair<int,int> query2(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return {minn[k],cnt[k]};
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query2(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query2(nl,nr,mid+1,r,rs(k));
    pair<int,int> ql=query2(nl,nr,l,mid,ls(k)),qr=query2(nl,nr,mid+1,r,rs(k));
    return {min(ql.first,qr.first),(ql.first<=qr.first? ql.second:0)+(qr.first<=ql.first? qr.second:0)};
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    build(1,1,n);
    m=read();
    while(m--)
    {
        int l=read(),r=read();
        pair<int,int> tmp=query2(l,r,1,n,1);
        if(query1(l,r,1,n,1)%tmp.first)
            cout<<r-l+1<<'\n';
        else
            cout<<r-l+1-tmp.second<<'\n';
    }
    return 0;
}