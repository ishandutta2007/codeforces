#include <bits/stdc++.h>

using namespace std;

int n,m;
int num[1005][1005];
int a[1005][1005];
int b[1005][1005];
int c[1005][1005];
int d[1005][1005];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j] = max(a[i-1][j],a[i][j-1])+num[i][j];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j] = max(b[i+1][j],b[i][j-1])+num[i][j];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			c[i][j] = max(c[i+1][j],c[i][j+1])+num[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			d[i][j] = max(d[i-1][j],d[i][j+1])+num[i][j];
		}
	}
	int res=0;
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<m;j++)
		{
			int tot=0;
			tot = max(tot,a[i-1][j]+b[i][j-1]+c[i+1][j]+d[i][j+1]);
			tot = max(tot,a[i][j-1]+b[i+1][j]+c[i][j+1]+d[i-1][j]);
			res = max(res,tot);
		}
	}
	printf("%d\n",res);
}