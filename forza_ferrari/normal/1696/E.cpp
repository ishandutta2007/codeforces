#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int ans,n,fac[400001],inv[400001];
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
inline int c(int x,int y)
{
    if(x<y||x<0||y<0)
        return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    cin>>n;
    fac[0]=inv[0]=1;
    for(int i=1;i<=400000;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[400000]=pw(fac[400000],mod-2);
    for(int i=399999;i>=1;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    for(int i=0;i<=n;++i)
    {
        int x;
        cin>>x;
        ans=(ans+c(i+x,i+1))%mod;
    }
    cout<<ans<<'\n';
    return 0;
}