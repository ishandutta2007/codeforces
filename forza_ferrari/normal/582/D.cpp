#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n,m,dp[3501][3501][2][2],len,ans;
long long a[3501];
string s;
int main()
{
    cin>>n>>m>>s;
    len=1;
    for(int i=0;i<s.size();++i)
    {
        for(int j=1;j<=len;++j)
            a[j]*=10;
        a[1]+=s[i]^48;
        for(int j=1;j<=len;++j)
        {
            a[j+1]+=a[j]/n;
            a[j]%=n;
            if(a[len+1])
                ++len;
        }
    }
    reverse(a+1,a+len+1);
    dp[0][0][0][0]=1;
    for(int i=1;i<=len;++i)
        for(int j=0;j<=i;++j)
        {
            dp[i][j][0][0]=(1ll*(a[i]+1)*dp[i-1][j][0][0]%mod+1ll*(n-a[i]-1)*dp[i-1][j][0][1])%mod;
            dp[i][j][1][0]=((1ll*a[i]*(a[i]+1)/2%mod*dp[i-1][j][0][0]%mod+1ll*a[i]*((n<<1)-a[i]-1)/2%mod*dp[i-1][j][0][1]%mod)%mod+(1ll*n*(n+1)/2%mod*dp[i-1][j][1][0]%mod+1ll*n*(n-1)/2%mod*dp[i-1][j][1][1]%mod)%mod)%mod;
            dp[i][j+1][0][1]=(1ll*a[i]*dp[i-1][j][0][0]%mod+1ll*(n-a[i])*dp[i-1][j][0][1]%mod)%mod;
            dp[i][j+1][1][1]=((1ll*a[i]*(a[i]-1)/2%mod*dp[i-1][j][0][0]%mod+1ll*a[i]*((n<<1)-a[i]+1)/2%mod*dp[i-1][j][0][1]%mod)%mod+(1ll*n*(n-1)/2%mod*dp[i-1][j][1][0]%mod+1ll*n*(n+1)/2%mod*dp[i-1][j][1][1]%mod)%mod)%mod;
        }
    for(int i=m;i<=len;++i)
        ans=(ans+(dp[len][i][0][0]+dp[len][i][1][0])%mod)%mod;
    cout<<ans<<'\n';
    return 0;
}