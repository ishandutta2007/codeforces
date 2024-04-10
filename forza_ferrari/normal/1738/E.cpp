#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
const int mod=998244353,lim=1e5;
int t,n,a[100005],ans,fac[100001],inv[100001];
map<int,int> mp;
bool flag;
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
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int c(int x,int y)
{
    if(x<y||x<0||y<0)
        return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<=lim;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[lim]=pw(fac[lim],mod-2);
    for(int i=lim-1;i>=1;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    t=read();
    while(t--)
    {
        mp.clear();
        ans=1;
        n=read();
        for(int i=1;i<=n;++i)
        {
            a[i]=read()+a[i-1];
            if(i<n)
                ++mp[a[i]];
        }
        for(int i=1;(a[i]<<1)<a[n];++i)
            if(a[i]!=a[i+1]&&mp.count(a[i])&&mp.count(a[n]-a[i]))
                ans=1ll*ans*c(mp[a[i]]+mp[a[n]-a[i]],mp[a[i]])%mod;
        if(a[n]&1^1)
            ans=1ll*ans*pw(2,mp[a[n]>>1])%mod;
        cout<<ans<<'\n';
    }
    return 0;
}