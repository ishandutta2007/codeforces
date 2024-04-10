#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200,inf=1000000000;
int n,k,s;
int a[N];
int f[N][N*N],g[N][N*N];
int main()
{
	scanf("%d%d%d",&n,&k,&s);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (s>=n*(n-1)/2)
	{
		sort(a+1,a+1+n);
		int ans=0;
		for (int i=1;i<=k;i++) ans+=a[i];
		printf("%d\n",ans);
		return 0;
	}
	s+=k*(k+1)/2;
	for (int j=0;j<=k;j++)
	for (int l=0;l<=s;l++)
		f[j][l]=inf;
	f[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=k;j++)
		for (int l=0;l<=s;l++)
		{
			g[j][l]=inf;
			g[j][l]=min(g[j][l],f[j][l]);
			if (j>=1&&l>=i) 
			g[j][l]=min(g[j][l],f[j-1][l-i]+a[i]);
		}
		for (int j=0;j<=k;j++)
		for (int l=0;l<=s;l++)
			f[j][l]=g[j][l];
	}
	int ans=inf;
	for (int l=0;l<=s;l++) ans=min(ans,f[k][l]);
	printf("%d\n",ans);
	return 0;
}