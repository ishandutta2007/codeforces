#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 1<<20
#define mod 1000000007
#define ll long long
using namespace std;
ll f[N];
int val[N];
void fwt(ll f[],int lim,int opt)
{
	for(int l=2;l<=lim;l<<=1)
		for(int p=0;p<lim;p+=l)
			for(int i=p;i<p+(l>>1);i++)
			{
				if(opt==1) f[i]=(f[i]+f[(l>>1)+i])%mod;
				else f[i]=(f[i]-f[(l>>1)+i]+mod)%mod;
			}
}
ll _2[N];
int main()
{
	int n,maxn=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
		f[val[i]]++;
		maxn=max(maxn,val[i]);
	}
	int lim=1;
	while(lim<=maxn) lim<<=1;
	_2[0]=1;
	for(int i=1;i<=n;i++) _2[i]=_2[i-1]*2%mod;
	fwt(f,lim,1);
	for(int i=0;i<=lim;i++) f[i]=_2[f[i]];
	fwt(f,lim,-1);
	if(f[0]==_2[n]) printf("%lld",f[0]-1);
	else printf("%lld",f[0]);
	return 0;
}