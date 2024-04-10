#include<iostream>
#include<cstdio>
#include<map> 
#define MN 5000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,K,a,b,f[MN+5][MN+5],c[MN+5][MN+5];
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
inline int abs(int x){return x<0?-x:x;}
int main()
{
	n=read();a=read();b=read();K=read();
	for(int i=a;i<=n;++i) f[0][i]=1;
	for(int i=1;i<=K;++i)
	{
		for(int j=1;j<=n;++j) if(j!=b) 
		{
			int dis=abs(b-j),l=max(1,j-dis+1),r=min(n,j+dis-1),v=(f[i-1][j]-f[i-1][j-1]+mod)%mod;
			R(c[i][l],v);R(c[i][j],mod-v);
			R(c[i][j+1],v);R(c[i][r+1],mod-v);	
		}	
		for(int j=1;j<=n;++j) R(c[i][j],c[i][j-1]),f[i][j]=(f[i][j-1]+c[i][j])%mod;
	}
	printf("%d\n",f[K][n]);
	return 0;
}