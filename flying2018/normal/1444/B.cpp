#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300010
#define mod 998244353
using namespace std;
int fac[N],inv[N];
int ksm(int a,int b=mod-2)
{
    int r=1;
    for(;b;b>>=1)
    {
        if(b&1) r=1ll*r*a%mod;
        a=1ll*a*a%mod;
    }
    return r;
}
int C(int a,int b){return a<b?0:1ll*fac[a]*inv[b]%mod*inv[a-b]%mod;}
int a[N],_2[N];
int main()
{
    int n;
    scanf("%d",&n);n*=2;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=ksm(fac[n]);
    for(int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    _2[0]=1;
    for(int i=1;i<=n;i++) _2[i]=_2[i-1]*2ll%mod;
    int ans=0;
	for(int i=1;i<=n/2;i++)
		ans=(ans-a[i]+mod)%mod;
	for(int i=n/2+1;i<=n;i++)
		ans=(ans+a[i])%mod;
	ans=1ll*ans*C(n,n/2)%mod;
    printf("%d\n",ans);
    return 0;
}