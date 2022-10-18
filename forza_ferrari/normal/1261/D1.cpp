#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
const int mod=998244353;
int n,k,a[2001],b[2001],ans,dp[2001][4005];
signed main()
{
    cin>>n>>k;
    for(register int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[i==1? n:i-1]=a[i];
    }
    dp[0][n+1]=1;
    for(register int i=1;i<=n;++i)
    {
        for(register int j=0;j<=n+n+1;++j)
                dp[i][j]=dp[i-1][j]*(k-2*(a[i]!=b[i]))%mod;
        if(a[i]!=b[i])
            for(register int j=0;j<=n+n+1;++j)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }
        if(i==n)
            for(register int j=n+2;j<=n+n+1;++j)
                ans=(ans+dp[i][j])%mod;
    }
    cout<<ans<<endl;
    return 0;
}