#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
const int mod=1000000007;
int t,n,dp[2][2005][4001],ans;
string a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        a=" "+a;
        b=" "+b;
        for(int i=0;i<=n+1;++i)
            for(int j=0;j<=n+n;++j)
                dp[0][i][j]=dp[1][i][j]=0;
        dp[0][0][n]=dp[1][n+1][n]=1;
        for(int i=2;i<=n;i+=2)
        {
            if(a[i]!='?')
                a[i]=((a[i]-'0')^1)+'0';
            if(b[i]!='?')
                b[i]=((b[i]-'0')^1)+'0';
        }
        for(int i=1;i<=n;++i)
            for(int j=0;j<=n+n;++j)
                if(dp[0][i-1][j])
                {
                    if(a[i]!='1'&&b[i]!='1')
                        dp[0][i][j]=(dp[0][i][j]+dp[0][i-1][j])%mod;
                    if(a[i]!='0'&&b[i]!='0')
                        dp[0][i][j]=(dp[0][i][j]+dp[0][i-1][j])%mod;
                    if(a[i]!='1'&&b[i]!='0')
                        dp[0][i][j-1]=(dp[0][i][j-1]+dp[0][i-1][j])%mod;
                    if(a[i]!='0'&&b[i]!='1')
                        dp[0][i][j+1]=(dp[0][i][j+1]+dp[0][i-1][j])%mod;
                }
        for(int i=n;i>=1;--i)
            for(int j=0;j<=n+n;++j)
                if(dp[1][i+1][j])
                {
                    if(a[i]!='1'&&b[i]!='1')
                        dp[1][i][j]=(dp[1][i][j]+dp[1][i+1][j])%mod;
                    if(a[i]!='0'&&b[i]!='0')
                        dp[1][i][j]=(dp[1][i][j]+dp[1][i+1][j])%mod;
                    if(a[i]!='1'&&b[i]!='0')
                        dp[1][i][j-1]=(dp[1][i][j-1]+dp[1][i+1][j])%mod;
                    if(a[i]!='0'&&b[i]!='1')
                        dp[1][i][j+1]=(dp[1][i][j+1]+dp[1][i+1][j])%mod;
                }
        ans=0;
        for(int i=1;i<=n;++i)
            for(int j=0;j<=n+n;++j)
                ans=(ans+1ll*dp[0][i][j]*dp[1][i+1][n+n-j]%mod*abs(j-n)%mod)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}