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
int n,a[MN+5],s[MN+5],rt=0,sum=0;
int main()
{
	n=read();
	for(int i=0;i<=n;++i) a[i]=read();
	for(int i=0;i<n;++i) if(a[i+1]>1&&a[i]>1) rt=1;
	if(!rt) return 0*puts("perfect");s[0]=a[0];
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	puts("ambiguous");
	for(int i=0;i<=n;++i) 
		for(int j=1;j<=a[i];++j) printf("%d ",i?s[i-1]:0);
	puts("");
	for(int i=0;i<=n;++i) for(int j=1;j<=a[i];++j)
	{
		if(j==1)  printf("%d ",i?s[i-1]:0);
		else printf("%d ",i?(i>1?s[i-2]+1:1):0); 
	}
	return 0;
}