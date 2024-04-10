#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
#define mod 1000000007
using namespace std;
int fac[N],inv[N],f[N],s;
int main()
{
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    fac[0]=fac[1]=f[0]=1,inv[1]=1;
    for(int i=2;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod,inv[i]=(mod-1ll*(mod/i)*inv[mod%i]%mod)%mod;
    for(int i=1;i<=n;i++)
    {
        s=(1ll*s+f[i-1]-(i<=k?0:f[i-k-1])+mod)%mod;
        f[i]=1ll*s*inv[i]%mod;
    }
    ans=fac[n];
    for(int i=0;i<n;i++) ans=(ans-1ll*fac[n-1]*f[i]%mod+mod)%mod;
    printf("%d\n",ans);
    return 0;
}