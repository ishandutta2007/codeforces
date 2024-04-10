#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=1000000007;
int t,n,m,k,dp[2001][2001];
double f[2001][2001];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        for(int i=0;i<=n;++i)
            for(int j=0;j<=m;++j)
                f[i][j]=dp[i][j]=1ll<<60;
        f[0][0]=dp[0][0]=0;
        for(int i=1;i<=n;++i)
            for(int j=0;j<=m;++j)
            {
                if(!j)
                {
                    dp[i][j]=dp[i-1][j];
                    f[i][j]=f[i-1][j];
                }
                else
                {
                    double tmp=(f[i-1][j]-f[i-1][j-1])*0.5;
                    int x=0;
                    if(tmp<0)
                        x=0;
                    else if(tmp>k)
                        x=k;
                    else
                        x=(dp[i-1][j]-dp[i-1][j-1]+mod)%mod*((mod+1)>>1)%mod;
                    if(tmp<0)
                        tmp=0;
                    if(tmp>k)
                        tmp=k;
                    if(f[i-1][j-1]+tmp<f[i-1][j]-tmp)
                    {
                        f[i][j]=f[i-1][j-1]+tmp;
                        dp[i][j]=(dp[i-1][j-1]+x)%mod;
                    }
                    else
                    {
                        f[i][j]=f[i-1][j]-tmp;
                        dp[i][j]=(dp[i-1][j]-x+mod)%mod;
                    }
                }
            }
        cout<<dp[n][m]<<'\n';
    }
    return 0;
}