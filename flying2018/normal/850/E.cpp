#include<iostream>
#include<cstdio>
#include<cstring>
#define N 21
#define M 1<<N
#define ll long long
#define mod 1000000007
#define inv2 (mod+1)/2
using namespace std;
int f[M],g[M];
void fwt(int f[],int n,int opt)
{
	for(int l=1;l<n;l<<=1)
		for(int i=0;i<n;i+=l<<1)
			for(int j=0;j<l;j++)
			{
				int x=f[i+j],y=f[i+j+l];
				f[i+j]=(x+y)%mod;
				f[i+j+l]=(x-y+mod)%mod;
				if(opt==-1) f[i+j]=1ll*f[i+j]*inv2%mod,f[i+j+l]=1ll*f[i+j+l]*inv2%mod;
			}
}
char str[M];
int _2[N+5];
int main()
{
	int n;
	scanf("%d%s",&n,str);
	int m=1<<n;
	_2[0]=1;
	for(int i=1;i<=N;i++) _2[i]=1ll*_2[i-1]*2%mod;
	for(int i=0;i<m;i++) f[i]=str[i]-'0';
	for(int i=0;i<m;i++) g[i]=f[i^(m-1)];
	fwt(f,m,1);
	fwt(g,m,1);
	for(int i=0;i<m;i++) f[i]=1ll*f[i]*g[i]%mod;
	fwt(f,m,-1);
	int ans=0;
	for(int i=0;i<m;i++) ans=(ans+1ll*f[i]*_2[__builtin_popcountll(i)]%mod)%mod;
	printf("%lld\n",1ll*ans*3%mod);
	return 0;
}