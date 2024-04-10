#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<signal.h>
#include<cstring>
using namespace std;
const int p=1000000007;
long long n;
int k,ans;
int inv[123];
int F[55][55][10110];
int exp(int a,int b,int c)
{
	int d=1;
	while (b)
	{
		if (b&1) d=1LL*d*a%c;
		b>>=1;a=1LL*a*a%c;
	}
	return d;
}
int f(int lim,int now,int k)
{
	if (F[lim][now][k]!=0) return F[lim][now][k];
	if (k==1) return inv[now+1];
	int res=0;
	for (int i=lim;i<=now;i++)
		res=(res+f(lim,i,k-1))%p;
	res=1LL*res*inv[now+1]%p;
	F[lim][now][k]=res;
	return res;
}
int main()
{
	scanf("%I64d%d",&n,&k);
	int res=1;
	inv[1]=1;for (int i=2;i<=100;i++) inv[i]=-1LL*inv[p%i]*(p/i)%p;
	for (int i=2;1LL*i*i<=n;i++)
	if (n%i==0)
	{
		int c=0,inv=exp(i,p-2,p),ans=0;
		int u=1;
		while (n%i==0) n/=i,c++,u=1LL*u*i%p;
		for (int j=c;j>=0;j--)
		{
			ans=(ans+1LL*u*f(j,c,k))%p;
			u=1LL*u*inv%p;
		}
	//	printf("%d %d\n",ans,s);
		res=1LL*res*ans%p;
	}
	if (n!=1)
	{
		res=1LL*res*(f(0,1,k)%p+1LL*n%p*f(1,1,k)%p)%p;
	}
	if (res<0) res+=p;
	printf("%d\n",res);
	return 0;
}