#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,p[200001],dp[200001],sum[200001];
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
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i];
        p[i]=1ll*p[i]*pw(100,mod-2)%mod;
    }
    sum[0]=dp[0]=1;
    for(int i=1;i<=n;++i)
    {
        dp[i]=(1+1ll*(1-p[i]+mod)%mod*pw(p[i],mod-2)%mod*sum[i-1]%mod)%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
    }
    cout<<(sum[n]-1+mod)%mod<<'\n';
    return 0;
}