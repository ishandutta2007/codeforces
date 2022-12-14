#include<iostream>
#include<cstdio>
#define MN 300
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,T,a[MN+5],f[MN+5],F[MN+5],num[MN+5];
int main()
{
	n=read();T=read();
	for(int i=1;i<=n;++i) ++num[a[i]=read()];
	if(T<=2000)
	{
		int ans=0;
		for(int i=1;i<=n*T;++i)
		{
			int x=a[(i-1)%n+1];
			for(int j=x;j;--j) f[x]=max(f[x],f[j]+1);
			ans=max(ans,f[x]); 
		}
		return 0*printf("%d\n",ans);
	}
	for(int i=1;i<=1000*n;++i)
	{
		int x=a[(i-1)%n+1];
		for(int j=x;j;--j) f[x]=max(f[x],f[j]+1);
	}
	for(int i=1;i<=1000*n;++i)
	{
		int x=a[n-(i-1)%n];
		for(int j=x;j<=300;++j) F[x]=max(F[x],F[j]+1);
	}
	int ans=0;
	for(int i=1;i<=300;++i) f[i]=max(f[i],f[i-1]);
	for(int i=300;i;--i) F[i]=max(F[i],F[i+1]);
	for(int i=1;i<=300;++i) ans=max(ans,f[i]+F[i]+(T-2000)*num[i]);
	printf("%d\n",ans);
	return 0;
}