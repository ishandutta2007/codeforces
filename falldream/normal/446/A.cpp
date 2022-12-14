#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5],f[MN+5],g[MN+5],ans=0;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),f[i]=(a[i]>a[i-1]?f[i-1]:0)+1; 
	for(int i=n;i;--i) g[i]=(a[i]<a[i+1]?g[i+1]:0)+1;
	for(int i=1;i<=n;++i)
	{
		ans=max(ans,max(f[i-1],g[i+1])+1);
		if(a[i+1]>=a[i-1]+2) ans=max(ans,f[i-1]+g[i+1]+1);	
	}
	printf("%d\n",ans);
	return 0;
}