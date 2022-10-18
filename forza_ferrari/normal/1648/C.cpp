#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[200001],b[200001],cnt[200001],sum,ans,val[200001<<2];
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
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
    val[k]=(val[ls(k)]+val[rs(k)])%mod;
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        val[k]=cnt[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int node,int l,int r,int k)
{
    if(l==r)
    {
        --cnt[l];
        val[k]=cnt[l];
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls(k));
    else
        update(node,mid+1,r,rs(k));
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return 0;
    if(l>=nl&&r<=nr)
        return val[k];
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res=(res+query(nl,nr,l,mid,ls(k)))%mod;
    if(nr>mid)
        res=(res+query(nl,nr,mid+1,r,rs(k)))%mod;
    return res;
}
signed main()
{
    cin>>n>>m;
    sum=1;
    for(int i=1;i<=n;++i)
    {
        sum=sum*i%mod;
        cin>>a[i];
        ++cnt[a[i]];
        sum=sum*pw(cnt[a[i]],mod-2)%mod;
    }
    for(int i=1;i<=m;++i)
        cin>>b[i];
    build(1,1,2e5);
    bool flag=1;
    for(int i=1;i<=min(n,m);++i)
    {
        ans=(ans+1ll*sum*query(1,b[i]-1,1,2e5,1)%mod*pw(n-i+1,mod-2)%mod)%mod;
        if(!cnt[b[i]])
        {
            flag=0;
            break;
        }
        sum=sum*pw(n-i+1,mod-2)%mod*cnt[b[i]]%mod;
        update(b[i],1,2e5,1);
    }
    if(flag&&n<m)
        ans=(ans+1)%mod;
    cout<<ans<<'\n';
    return 0;
}