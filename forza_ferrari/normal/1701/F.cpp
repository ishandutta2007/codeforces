#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int lim=2e5;
int n,m,minn[200001<<2],tag[200001<<2],cnt[200001<<2];
long long sum[200001<<2],ans;
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
    minn[k]=min(minn[ls(k)],minn[rs(k)]);
    cnt[k]=cnt[ls(k)]+cnt[rs(k)];
    sum[k]=sum[ls(k)]*(minn[ls(k)]==minn[k])+sum[rs(k)]*(minn[rs(k)]==minn[k]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        sum[ls(k)]+=1ll*tag[k]*cnt[ls(k)];
        sum[rs(k)]+=1ll*tag[k]*cnt[rs(k)];
        tag[ls(k)]+=tag[k];
        tag[rs(k)]+=tag[k];
        tag[k]=0;
    }
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        minn[k]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update1(int nl,int nr,int l,int r,int k,int p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        sum[k]+=1ll*p*cnt[k];
        tag[k]+=p;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update1(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update1(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query1(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return 0;
    if(l>=nl&&r<=nr)
        return (minn[k]==0)*sum[k];
    push_down(k);
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query1(nl,nr,l,mid,ls(k));
    if(nr>mid)
        res+=query1(nl,nr,mid+1,r,rs(k));
    return res;
}
inline int query2(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return 0;
    if(l>=nl&&r<=nr)
        return cnt[k];
    push_down(k);
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query2(nl,nr,l,mid,ls(k));
    if(nr>mid)
        res+=query2(nl,nr,mid+1,r,rs(k));
    return res;
}
inline void update2(int node,int l,int r,int k)
{
    if(l==r)
    {
        minn[k]^=1;
        cnt[k]^=1;
        if(minn[k]==0)
        {
            sum[k]=query2(node+1,min(node+m,lim),1,lim,1);
            ans+=1ll*sum[k]*(sum[k]-1)/2+query1(max(node-m,1ll),node-1,1,lim,1);
            update1(max(node-m,1ll),node-1,1,lim,1,1);
        }
        else
        {
            update1(max(node-m,1ll),node-1,1,lim,1,-1);
            ans-=1ll*sum[k]*(sum[k]-1)/2+query1(max(node-m,1ll),node-1,1,lim,1);
            sum[k]=0;
        }
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(node<=mid)
        update2(node,l,mid,ls(k));
    else
        update2(node,mid+1,r,rs(k));
    push_up(k);
}
signed main()
{
    n=read(),m=read();
    build(1,1,lim);
    for(int i=1;i<=n;++i)
    {
        int x=read();
        update2(x,1,lim,1);
        cout<<ans<<'\n';
    }
    return 0;
}