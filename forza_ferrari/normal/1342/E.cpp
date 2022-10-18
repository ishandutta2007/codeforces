#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=998244353;
int n,k,ans,fac[200001],inv[200001];
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
    cin>>n>>k;
    if(k>=n)
    {
        puts("0");
        return 0;
    }
    k=n-k;
    fac[0]=inv[0]=1;
    for(register int i=1;i<=n;++i)
        fac[i]=fac[i-1]*i%mod;
    inv[n]=pw(fac[n],mod-2);
    for(register int i=n-1;i;--i)
        inv[i]=inv[i+1]*(i+1)%mod;
    for(register int i=0;i<=k;++i)
        ans=(ans+((k-i)&1? mod-1:1)*c(k,i)%mod*pw(i,n)%mod)%mod;
    ans=ans*inv[k]%mod;
    cout<<ans*fac[k]%mod*c(n,k)%mod*(n-k? 2:1)%mod<<endl;
    return 0;
}