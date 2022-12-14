#include<iostream>
#include<cstdio>
#include<cmath>
#define MX 10000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[105][MX+5],from[105][MX+5],n,m,b[MX+5],r[105],c[105];
inline int sqr(int x){return x*x;}
int main()
{
	f[0][0]=1;
	for(int i=1;i<=100;++i) b[i*i]=1;
	for(int i=1;i<=100;++i)
		for(int j=0;j<=MX;++j) if(f[i-1][j])
			for(int k=1;k<=100;++k)	if(j+k*k<=MX) f[i][j+k*k]=1,from[i][j+k*k]=k;
	n=read();m=read();
	for(int j=1;j<=MX;++j) if(b[j]&&f[n][j])
	{
		for(int k=n,l=j;k;l-=sqr(from[k--][l])) r[k]=from[k][l];	
		break;
	}
	for(int j=1;j<=MX;++j) if(b[j]&&f[m][j])
	{
		for(int k=m,l=j;k;l-=sqr(from[k--][l])) c[k]=from[k][l];	
		break;
	}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=m;++j)
			printf("%d ",r[i]*c[j]);
	return 0;
}