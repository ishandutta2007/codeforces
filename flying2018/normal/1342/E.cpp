#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
#define mod 998244353
using namespace std;
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
int fac[N],inv[N];
int C(int a,int b){return 1ll*fac[a]*inv[b]%mod*inv[a-b]%mod;}
int main()
{
	int n;
	ll k;
	scanf("%d%lld",&n,&k);
	if(k>n){puts("0");return 0;}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	int ans=0;
	k=n-k;
	for(int i=1;i<=k;i++) ans=(ans+(((k-i)&1)?-1ll:1ll)*C(k,i)*ksm(i,n)%mod+mod)%mod;
	printf("%lld\n",1ll*ans*C(n,k)%mod*(k==n?1:2)%mod);
	return 0;
}