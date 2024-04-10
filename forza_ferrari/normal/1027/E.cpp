#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m,dp[505][505],ans;
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
int main()
{
    cin>>n>>m;
    dp[1][1]=1;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<i;++j)
            for(int k=i-j;k<i;++k)
                dp[i][j]=(dp[i][j]+dp[k][min(k,j)])%mod;
        dp[i][i]=(dp[i][i]+dp[i][i-1]+1)%mod;
    }
    for(int i=n;i>=1;--i)
        dp[n][i]=(dp[n][i]-dp[n][i-1]+mod)%mod;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n&&i*j<m;++j)
            ans=(ans+2ll*dp[n][i]%mod*dp[n][j]%mod)%mod;
    cout<<ans<<'\n';
    return 0;
}