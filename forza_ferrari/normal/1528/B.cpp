#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,dp[1000001],sum,val[1000001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i)
            ++val[j];
    for(int i=1;i<=n;++i)
    {
        dp[i]=(sum+val[i])%mod;
        sum=(sum+dp[i])%mod;
    }
    cout<<dp[n]<<'\n';
    return 0;
}