#include<iostream>
#include<cstdio>
using namespace std;
int n,mod,dp[401][401],fac[401],inv[401],p[401];
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
int main()
{
    cin>>n>>mod;
    p[0]=dp[1][1]=fac[0]=inv[0]=1;
    for(int i=1;i<=n;++i)
    {
        fac[i]=1ll*fac[i-1]*i%mod;
        p[i]=2ll*p[i-1]%mod;
    }
    for(int i=2;i<=n;++i)
        dp[i][i]=2ll*dp[i-1][i-1]%mod;
    inv[n]=pw(fac[n],mod-2);
    for(int i=n-1;i>=1;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    for(int i=2;i<=n;++i)
        for(int j=1;j<i;++j)
            for(int k=1;k<j;++k)
                dp[i][j]=(dp[i][j]+1ll*dp[i-k-1][j-k]*p[k-1]%mod*c(j,k)%mod)%mod;
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=(ans+dp[n][i])%mod;
    cout<<ans<<'\n';
    return 0;
}