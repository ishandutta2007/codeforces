#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
#define ll long long
#define N 2010
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
int pw[N],ipw[N];
int f[N],g[N][N],s[N];
int main()
{
	int n,p,b;
	scanf("%d%d%d",&n,&p,&b);p=1ll*p*ksm(b)%mod;
	pw[0]=ipw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*p%mod,ipw[i]=1ll*ipw[i-1]*(1-p+mod)%mod;
	g[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		g[i][0]=1;
		for(int j=1;j<=n;j++)
		g[i][j]=(1ll*pw[i-j]*g[i-1][j-1]%mod+1ll*ipw[j]*g[i-1][j]%mod)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=1;
		for(int j=1;j<=i-1;j++)
		s[i]=(s[i]-1ll*s[j]*g[i][j]%mod+mod)%mod;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		f[i]=(f[i]+1ll*s[j]*g[i][j]%mod*(1ll*f[j]+f[i-j]+1ll*j*(i-j)%mod+1ll*j*(j-1)/2%mod)%mod)%mod;
		f[i]=1ll*(f[i]+1ll*s[i]*(1ll*i*(i-1)/2%mod)%mod)*ksm((1-s[i]+mod)%mod)%mod;
	}
	printf("%d",f[n]);
	return 0;
}