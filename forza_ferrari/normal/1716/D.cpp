#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m,dp[2][200001],ans[200001],now;
int main()
{
    cin>>n>>m;
    dp[0][0]=1;
    for(int i=m,sum=m;sum<=n;++i,sum+=i)
    {
        now^=1;
        for(int j=0;j<=n;++j)
            dp[now][j]=0;
        for(int j=i;j<=n;++j)
        {
            dp[now][j]=(dp[now^1][j-i]+dp[now][j-i])%mod;
            ans[j]=(ans[j]+dp[now][j])%mod;
        }
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}