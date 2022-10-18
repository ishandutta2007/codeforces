#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,h[100001<<1],d[100001<<1],maxn[100001<<3][2],ans[100001<<3];
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
    maxn[k][0]=max(maxn[ls(k)][0],maxn[rs(k)][0]);
    maxn[k][1]=max(maxn[ls(k)][1],maxn[rs(k)][1]);
    ans[k]=max(max(ans[ls(k)],ans[rs(k)]),maxn[ls(k)][0]+maxn[rs(k)][1]);
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        maxn[k][0]=h[l]+h[l]-d[l];
        maxn[k][1]=h[l]+h[l]+d[l];
        ans[k]=h[l]<<1;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline pair<int,pair<int,int> > query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return {ans[k],{maxn[k][0],maxn[k][1]}};
    int mid=(l+r)>>1;
    pair<int,pair<int,int> > res={0,{0,0}};
    if(nr<=mid)
        return query(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query(nl,nr,mid+1,r,rs(k));
    pair<int,pair<int,int> > ql=query(nl,nr,l,mid,ls(k)),qr=query(nl,nr,mid+1,r,rs(k));
    return {max(max(ql.first,qr.first),ql.second.first+qr.second.second),{max(ql.second.first,qr.second.first),max(ql.second.second,qr.second.second)}};
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>d[i+1];
        if(i!=n)
            d[i+n+1]=d[i+1];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>h[i];
        h[i+n]=h[i];
    }
    for(int i=2;i<=n+n;++i)
        d[i]+=d[i-1];
    build(1,1,n+n);
    while(m--)
    {
        int x,y;
        cin>>y>>x;
        --y,++x;
        if(y==0)
            y=n;
        if(x>n)
            x=1;
        if(x>y)
            y+=n;
        cout<<query(x,y,1,n+n,1).first<<'\n';
    }
    return 0;
}