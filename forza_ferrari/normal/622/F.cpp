#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=1000000007;
int n,k,fac[1000011],sum[1000011][2],ans,tot;
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
signed main()
{
    scanf("%lld%lld",&n,&k);
    fac[0]=1;
    for(register int i=1;i<=k+2;++i)
        fac[i]=fac[i-1]*i%mod;
    sum[0][0]=sum[k+3][1]=1;
    for(register int i=1;i<=k+2;++i)
        sum[i][0]=sum[i-1][0]*((n-i+mod)%mod)%mod;
    for(register int i=k+2;i;--i)
        sum[i][1]=sum[i+1][1]*((n-i+mod)%mod)%mod;
    for(register int i=1;i<=k+2;++i)
    {
        tot=(tot+pw(i,k))%mod;
        ans=(ans+tot*sum[i-1][0]%mod*sum[i+1][1]%mod*pw(((k-i)&1? mod-fac[i-1]:fac[i-1])%mod*fac[k+2-i]%mod,mod-2)%mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}