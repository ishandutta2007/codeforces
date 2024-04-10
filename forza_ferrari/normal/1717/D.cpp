#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
int n,m,fac[100001],inv[100001];
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
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    cin>>n>>m;
    if(m>=n)
        cout<<pw(2,n)<<'\n';
    else
    {
        fac[0]=inv[0]=1;
        int ans=0;
        for(int i=1;i<=n;++i)
            fac[i]=1ll*fac[i-1]*i%mod;
        inv[n]=pw(fac[n],mod-2);
        for(int i=n-1;i>=1;--i)
            inv[i]=1ll*inv[i+1]*(i+1)%mod;
        for(int i=0;i<=m;++i)
            ans=(ans+c(n,i))%mod;
        cout<<ans<<'\n';
    }
    return 0;
}