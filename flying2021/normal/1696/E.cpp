#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000010,mod=1000000007;
int ksm(int a,int b=mod-2)
{
    int r=1;
    for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) r=1ll*r*a%mod;
    return r;
}
int fac[N],inv[N];
void init(int n=N-10)
{
    for(int i=fac[0]=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=ksm(fac[n]);
    for(int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int a[N];
int main()
{
    init();
    int n;scanf("%d",&n);
    for(int i=0;i<=n;i++) scanf("%d",&a[i]),--a[i];
    int ans=0;
    for(int i=0;i<=n;i++) ans=(ans+C(i+a[i]+1,a[i]))%mod;
    printf("%d\n",ans);
    return 0;
}