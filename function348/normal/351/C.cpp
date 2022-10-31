#include<cstdio>
#include<iostream>
using namespace std;
const int N=50,inf=2100000000;
int a[N],b[N];
int c[N][N],d[N][N],tmp[N][N],f[N][N];
int n,m,p;
void mult(int a[][N],int b[][N])
{
	for (int i=0;i<=m;i++)
	for (int j=0;j<=m;j++)
		tmp[i][j]=inf;
	for (int i=0;i<=m;i++)
	for (int j=0;j<=m;j++)
	for (int k=0;k<=m;k++)
	if (0LL+a[i][j]+b[j][k]<tmp[i][k])
		tmp[i][k]=a[i][j]+b[j][k];
	for (int i=0;i<=m;i++)
	for (int j=0;j<=m;j++)
		a[i][j]=tmp[i][j];
}
int main()
{
	scanf("%d%d",&n,&p);
	m=n*2;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int k=0;k<=n*2;k++)
	{
		for (int j=0;j<=n*2;j++)
			f[0][j]=inf;
		f[0][k]=0;
		for (int i=1;i<=n;i++)
		for (int j=0;j<=n*2;j++)
		{
			f[i][j]=inf;
			if (j    ) f[i][j]=min(f[i][j],f[i-1][j-1]+a[i]);
			if (j<n*2) f[i][j]=min(f[i][j],f[i-1][j+1]+b[i]);
		}
		for (int i=0;i<=n*2;i++) c[k][i]=f[n][i];
	}
	for (int i=0;i<=m;i++)
	for (int j=0;j<=m;j++)
		d[i][j]=inf;
	for (int i=0;i<=m;i++) d[i][i]=0;
	while (p)
	{
		if (p&1) mult(d,c);
		p>>=1;mult(c,c);
	}
	printf("%d\n",d[0][0]);
	return 0;
}