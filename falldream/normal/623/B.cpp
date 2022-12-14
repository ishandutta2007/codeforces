#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 1000000
#define ll long long 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int num=0,n,a,b,s[MN+5];
long long ans=1e18,f[MN+5],g[MN+5],h[MN+5];

void Calc(int t,ll v)
{
	memset(f,40,sizeof(f));
	memset(g,40,sizeof(g));
	memset(h,40,sizeof(h));
	f[1]=v;
	for(int i=2;i<=n;++i) 
	{
		ll add;
		if(s[i]%t==0) add=-a;
		else if((s[i]+1)%t==0||(s[i]-1)%t==0) add=b-a;
		else add=1e18;
		g[i]=min(g[i],min(g[i-1],f[i-1]));	
		f[i]=min(f[i],f[i-1]+add);
		h[i]=min(h[i],min(g[i-1],h[i-1])+add);
	}
	ans=min(ans,min(min(f[n],g[n]),h[n]));
}

void Solve(int x,ll V)
{
	if(x==1) return;
	for(int i=2;i<=100000;++i) if(x%i==0)
	{
		Calc(i,V); 
		while(x%i==0) x/=i;
	} 
	if(x>1) Calc(x,V);
}

int main()
{
	n=read();a=read();b=read();
	for(int i=1;i<=n;++i) s[i]=read();
	Solve(s[1]+1,1LL*a*(n-1)+b);
	Solve(s[1],1LL*a*(n-1));
	Solve(s[1]-1,1LL*a*(n-1)+b);
	for(int i=1,j=n;i<j;++i,--j) swap(s[i],s[j]);
	Solve(s[1]+1,1LL*a*(n-1)+b);
	Solve(s[1],1LL*a*(n-1));
	Solve(s[1]-1,1LL*a*(n-1)+b);
	printf("%lld",ans);
	return 0;
}