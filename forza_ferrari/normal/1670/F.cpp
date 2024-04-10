#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=1000000007;
int n,l,r,val,dp[71][1001],c[1001][1001];
inline int calc(int maxn)
{
    for(int i=0;i<=60;++i)
        for(int j=0;j<=n;++j)
            dp[i][j]=0;
    dp[61][0]=1;
    for(int i=60;~i;--i)
        for(int j=0;j<=n;++j)
            if(dp[i+1][j])
            {
                int lim=(j<<1)+(maxn>>i&1);
                if(val>>i&1)
                    for(int k=1;k<=min(n,lim);k+=2)
                        dp[i][min(n,lim-k)]=(dp[i][min(n,lim-k)]+dp[i+1][j]*c[n][k]%mod)%mod;
                else
                    for(int k=0;k<=min(n,lim);k+=2)
                        dp[i][min(n,lim-k)]=(dp[i][min(n,lim-k)]+dp[i+1][j]*c[n][k]%mod)%mod;
            }
    int res=0;
    for(int i=0;i<=n;++i)
        res=(res+dp[0][i])%mod;
    return res;
}
signed main()
{
    cin>>n>>l>>r>>val;
    c[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    cout<<(calc(r)-calc(l-1)+mod)%mod<<'\n';
    return 0;
}