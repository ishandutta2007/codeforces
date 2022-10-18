#include<iostream>
#include<cstdio>
using namespace std;
const int mod=31607;
int n,a[31][31],dp[22][1<<21],ans;
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
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            a[i][j]=1ll*a[i][j]*pw(10000,mod-2)%mod;
        }
    for(int i=1;i<=n;++i)
    {
        dp[i][0]=1;
        for(int s=1;s<1<<n;++s)
            dp[i][s]=1ll*dp[i][s^(s&-s)]*a[__builtin_ctz(s)+1][i]%mod;
    }
    for(int s=0;s<1<<n;++s)
        for(int x=0;x<2;++x)
            for(int y=0;y<2;++y)
            {
                int l=0,r=n-1,sum=1;
                for(int i=1;i<=n;++i)
                {
                    sum=1ll*sum*((dp[i][s|(x<<l)|(y<<r)]-dp[i][(1<<n)-1]+mod)%mod)%mod;
                    ++l;
                    --r;
                }
                ans=(ans+1ll*((__builtin_popcount(s)+x+y)&1? mod-1:1)*sum%mod)%mod;
            }
    cout<<(1-ans+mod)%mod<<'\n';
    return 0;
}