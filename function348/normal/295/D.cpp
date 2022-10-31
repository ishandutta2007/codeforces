#include<cstdio>
#include<iostream>
using namespace std;
const int N=2010,p=1000000007;
int n,m,ans;
int f[N][N],g[N][N],s[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=2;j<=m;j++)
	{
		if (i==1)  f[i][j]=1;
		else f[i][j]=(1LL*(j+1)*s[i-1][j]-g[i-1][j])%p;
		g[i][j]=(g[i][j-1]+1LL*f[i][j]*j)%p;
		s[i][j]=(s[i][j-1]+f[i][j])%p;
	}
	for (int i=1;i<=n;i++)
	for (int j=2;j<=m;j++)
		g[i][j]=(g[i-1][j]+f[i][j])%p;
	for (int i=1;i<=n;i++)
	for (int j=2;j<=m;j++)
	{
		int k2=g[n-i+1][j];
		int k1=f[i][j];
		ans=(ans+1LL*k1*k2%p*(m-j+1))%p;
	}
	printf("%d\n",ans);
	return 0;
}