#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=1000000007;
int t,n,k,dp[101][1001],fac[1001],inv[1001],ans;
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
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
inline int c(int x,int y)
{
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
    dp[0][0]=fac[0]=inv[0]=1;
    for(register int i=1;i<=100;++i)
        for(register int j=i*(i+1)/2;j<=1000;++j)
            dp[i][j]=(dp[i][j-i]+dp[i-1][j-i])%mod;
    for(register int i=1;i<=1000;++i)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=pw(fac[i],mod-2);
    }
    t=read();
    while(t--)
    {
        n=read(),k=read();
        ans=0;
        for(register int i=k*(k+1)/2;i<=n;++i)
            ans=(ans+fac[k]*c(n-i+k,k)%mod*dp[k][i]%mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}