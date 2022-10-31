#include<cstdio>
#include<iostream>
using namespace std;
const int N=2010;
int n,m;
int v[N],u[N];
double f[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x]=1;u[y]=1;
	}
	int n1=n,n2=n;
	for (int i=1;i<=n;i++) n1-=v[i],n2-=u[i];
	for (int i=0;i<=n1;i++)
	for (int j=0;j<=n2;j++)
	if (i||j)
	{
		int k=n*(i+j)-i*j;
		if (i) f[i][j]+=i*(n-j)*f[i-1][j];
		if (j) f[i][j]+=(n-i)*j*f[i][j-1];
		if (i&&j) f[i][j]+=i*j*f[i-1][j-1];
		f[i][j]+=n*n;
		f[i][j]/=k;
	}
	printf("%.6lf\n",f[n1][n2]);
	return 0;
}