#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,ans,sum[200001],x[200001],y[200001],dp[200001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int w;
        cin>>x[i]>>y[i]>>w;
        int pos=upper_bound(x+1,x+i,y[i])-x;
        dp[i]=(x[i]-y[i]+(sum[i-1]-sum[pos-1]+mod)%mod)%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
        if(w)
            ans=(ans+dp[i])%mod;
    }
    cout<<(ans+x[n]+1)%mod<<'\n';
    return 0;
}