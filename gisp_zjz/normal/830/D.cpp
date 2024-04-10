#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll dp[505][505],n,s;

int main()
{
    scanf("%d",&n);
    dp[1][1]=1; dp[1][0]=1;
    for (int i=2;i<=n;i++)
    {
        for (int j=0;j<=n;j++)
            for (int k=0;k<=n-j;k++)
            {
                s=dp[i-1][j]*dp[i-1][k]%mod;
                dp[i][j+k]+=s*(j*2+k*2+1);
                dp[i][j+k+1]+=s;
                dp[i][j+k-1]+=s*(j+k)*(j+k-1);
            }
        for (int j=1;j<=n;j++) dp[i][j]%=mod;
    }
    cout << dp[n][1] << endl;
}