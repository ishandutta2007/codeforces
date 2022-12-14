#include<iostream>
#include<cstdio>
#define MN 2000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int m,n,f[MN+5][MN+5];
int main()
{
	m=read();n=read();f[0][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) 
			for(int k=j;k<=m;k+=j)
				f[i][k]=(f[i][k]+f[i-1][j])%mod;
	int ans=0;
	for(int i=1;i<=m;++i) ans=(ans+f[n][i])%mod;
	printf("%d\n",ans);
	return 0;
}