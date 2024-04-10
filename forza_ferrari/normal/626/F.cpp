#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n,m,dp[201][201][1001],a[201],d[201],ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
        d[i]=a[i]-a[i-1];
    dp[0][0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=n;++j)
            for(int k=0;k<=m;++k)
            {
                if(k>=j*d[i])
                    dp[i][j][k]=1ll*(j+1)*dp[i-1][j][k-j*d[i]]%mod;
                if(j<n&&k>=(j+1)*d[i])
                    dp[i][j][k]=(dp[i][j][k]+1ll*(j+1)*dp[i-1][j+1][k-(j+1)*d[i]]%mod)%mod;
                if(j>0&&k>=(j-1)*d[i])
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k-(j-1)*d[i]])%mod;
            }
    for(int i=0;i<=m;++i)
        ans=(ans+dp[n][0][i])%mod;
    cout<<ans<<'\n';
    return 0;
}