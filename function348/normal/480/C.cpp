#include<cstdio>
#include<iostream>
using namespace std;
const int N=5010;
typedef long long LL;
int f[N][N],g[N][N];
int n,a,b,k;
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	int mo=1000000007;
	f[0][a]=1;
	for (int i=a;i<=n;i++) g[0][i]=1;
	for (int i=1;i<=k;i++)
	for (int j=1;j<=n;j++)
	if (j<b)
	{
		int p=(b+j-1)/2;
		f[i][j]=(g[i-1][p]-f[i-1][j])%mo;
		g[i][j]=(g[i][j-1]+f[i][j])%mo;
	}
	else if (j==b)
	{
		f[i][j]=0;g[i][j]=g[i][j-1];
	}else
	if (j>b)
	{
		int p=(b+j+2)/2;
		f[i][j]=(g[i-1][n]-g[i-1][p-1])%mo;
		f[i][j]=(f[i][j]-f[i-1][j])%mo;
		g[i][j]=(g[i][j-1]+f[i][j])%mo;
	}
	g[k][n]=(g[k][n]+mo)%mo;
	printf("%d\n",g[k][n]);
	return 0;
}