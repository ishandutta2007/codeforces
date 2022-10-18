#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int t,n,dp[61][2],c[61][61];
int main()
{
    c[0][0]=dp[2][0]=1;
    for(int i=1;i<=60;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    for(int i=4;i<=60;i+=2)
    {
        dp[i][0]=(c[i-1][i/2-1]+dp[i-2][1])%mod;
        dp[i][1]=((c[i][i/2]-dp[i][0]+mod)%mod-1+mod)%mod;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n][0]<<" "<<dp[n][1]<<" 1\n";
    }
    return 0;
}