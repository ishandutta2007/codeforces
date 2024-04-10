#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int mod=1000000007;
int t,l,r,ans;
long long dp[5000001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
int main()
{
    t=read(),l=read(),r=read();
    int sum=1;
    for(int i=1;i<=r;++i)
        dp[i]=(1ll*i*(i-1))>>1;
    for(int i=1;i<=r;++i)
    {
        for(int j=i<<1;j<=r;j+=i)
            dp[j]=min(dp[j],dp[i]+((1ll*j*(j/i-1))>>1));
        if(i>=l)
        {
            ans=(ans+1ll*dp[i]%mod*sum%mod)%mod;
            sum=1ll*sum*t%mod;
        }
    }
    cout<<ans<<'\n';
    return 0;
}