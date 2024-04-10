#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=1000000007;
int t,n,m,k,fac[1000001],inv[1000001];
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
    if(x<y)
        return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<=1000000;++i)
        fac[i]=fac[i-1]*i%mod;
    inv[1000000]=pw(fac[1000000],mod-2);
    for(int i=999999;i;--i)
        inv[i]=inv[i+1]*(i+1)%mod;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        if(n==m)
        {
            cout<<k*n%mod<<'\n';
            continue;
        }
        int ans=0;
        for(int i=1;i<=m;++i)
            ans=(ans+fac[n-i-1]*inv[m-i]%mod*i%mod*pw(pw(2,n-i),mod-2)%mod)%mod;
        cout<<ans*k%mod*inv[n-m-1]%mod<<'\n';
    }
    return 0;
}