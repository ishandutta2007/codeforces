#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
int n,ans,cnt,p[100001],phi[100001],inv[100001];
bool prime[100001];
inline int Mod(int x)
{
    return x>=mod? x-mod:x;
}
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
inline int lcm(int x,int y)
{
    return 1ll*x*y%mod*inv[gcd(x,y)]%mod;
}
inline void sieve()
{
    prime[1]=phi[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!prime[i])
        {
            p[++cnt]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=cnt&&i*p[j]<=n;++j)
        {
            prime[i*p[j]]=1;
            if(i%p[j]==0)
            {
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
            phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
}
int main()
{
    cin>>n;
    inv[1]=1;
    for(int i=2;i<=n;++i)
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    sieve();
    for(int i=1;i<=n;++i)
        for(int j=i+i;j<n;j+=i)
            ans=Mod(ans+1ll*lcm(i,n-j)*phi[j/i]%mod);
    cout<<ans<<'\n';
    return 0;
}