#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,a[100001],ans[100001<<2][21];
bool tag[100001<<2][21];
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
    for(int i=0;i<=20;++i)
        ans[k][i]=ans[ls(k)][i]+ans[rs(k)][i];
}
inline void push_down(int k,int l,int r)
{
    int mid=(l+r)>>1;
    for(int i=0;i<=20;++i)
        if(tag[k][i])
        {
            ans[ls(k)][i]=mid-l+1-ans[ls(k)][i];
            ans[rs(k)][i]=r-mid-ans[rs(k)][i];
            tag[ls(k)][i]^=1;
            tag[rs(k)][i]^=1;
            tag[k][i]=0;
        }
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        for(int i=0;i<=20;++i)
            ans[k][i]=a[l]>>i&1;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        for(int i=0;i<=20;++i)
            if(p>>i&1)
            {
                ans[k][i]=r-l+1-ans[k][i];
                tag[k][i]^=1;
            }
        return;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
    {
        int res=0;
        for(int i=0;i<=20;++i)
            res+=ans[k][i]*(1<<i);
        return res;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query(nl,nr,l,mid,ls(k));
    if(nr>mid)
        res+=query(nl,nr,mid+1,r,rs(k));
    return res;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    m=read();
    build(1,1,n);
    while(m--)
    {
        int opt=read(),l=read(),r=read();
        if(opt==1)
            cout<<query(l,r,1,n,1)<<'\n';
        if(opt==2)
            update(l,r,1,n,1,read());
    }
    return 0;
}