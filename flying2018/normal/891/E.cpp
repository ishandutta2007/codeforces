#include<iostream>
#include<cstdio>
#include<cstring>
#define N 5010
#define mod 1000000007
using namespace std;
int f[N],a[N],c[N],fac[N],inv[N],res[N];
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
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	c[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++) res[j]=1ll*c[j]*a[i]%mod;
		for(int j=n;j;j--) c[j]=(res[j]-c[j-1]+mod)%mod;
		c[0]=res[0];
	}
	int ans=1;
	for(int i=1;i<=n;i++) ans=1ll*ans*a[i]%mod;
	for(int i=0;i<=min(n,k);i++)
	{
		int r=1;
		for(int j=k;j>=k-i+1;j--) r=1ll*r*j%mod;
		ans=(ans-1ll*r*c[i]%mod*ksm(ksm(n,i))%mod+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}