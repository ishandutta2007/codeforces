#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=1000000007;
int n,m,q,a[5001],p[5001],dp[5001][5001],ans;
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&q);
    for(register int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        dp[i][0]=1;
    }
    for(register int j=1;j<=m;++j)
        for(register int i=1;i<=n;++i)
            dp[i][j]=(dp[i-1][j-1]+dp[i+1][j-1])%mod;
    for(register int i=1;i<=n;++i)
        for(register int j=0;j<=m;++j)
            p[i]=(p[i]+dp[i][j]*dp[i][m-j]%mod)%mod;
    for(register int i=1;i<=n;++i)
        ans=(ans+p[i]*a[i]%mod)%mod;
    while(q--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        ans=(ans-p[x]*a[x]%mod+p[x]*y%mod+mod)%mod;
        a[x]=y;
        printf("%lld\n",ans);
    }
    return 0;
}