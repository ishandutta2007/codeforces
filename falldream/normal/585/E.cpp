#include<iostream>
#include<cstdio>
#define MN 500000
#define MX 10000000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool b[MX+5];
int n,a[MN+5],num[MX+5],mu[MX+5],s[MX/5],nn,ans=0,pw[MN+5];
int main()
{
	n=read();pw[0]=1;
	for(int i=1;i<=n;++i) ++num[a[i]=read()],pw[i]=2*pw[i-1]%mod;
	for(register int i=1;i<=MX>>1;++i) for(register int j=i<<1;j<=MX;j+=i) num[i]+=num[j];
	for(int i=2;i<=MX;++i)
	{
		if(!b[i]) s[++nn]=i,mu[i]=1;
		for(int j=1;s[j]*i<=MX;++j)
		{
			b[s[j]*i]=1;
			if(i%s[j]==0) break;
			else mu[s[j]*i]=mod-mu[i];
		}
	}
	for(int i=2;i<=MX;++i) 
		if(num[i]) ans=(ans+1LL*mu[i]*(pw[num[i]]-1)%mod*(n-num[i])%mod)%mod;
	printf("%d\n",ans);
	return 0;
}