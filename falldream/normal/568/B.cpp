#include<iostream>
#include<cstdio>
#define mod 1000000007
#define MN 4000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int C[MN+5][MN+5],n,f[MN+5],ans=0;
int main()
{
	n=read();
	for(int i=0;i<=n;++i) C[i][0]=1;
	for(int i=1;i<=n;++i)for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	f[0]=1;
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=i;++j)
			f[i]=(f[i]+1LL*C[i-1][j-1]*f[i-j])%mod;
	for(int i=0;i<n;++i) ans=(ans+1LL*C[n][i]*f[i])%mod;
	printf("%d\n",ans);
	return 0;
}