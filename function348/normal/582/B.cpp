#include<cstdio>
#include<iostream>
using namespace std;
const int N=110;
int n,t;
int a[N];
int f[N][N],g[N][N],ans[N][N],c[N][N];
void pluss(int a[][N],int b[][N])
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		c[i][j]=-10000000;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	for (int k=1;k<=n;k++)
		c[i][k]=max(c[i][k],a[i][j]+b[j][k]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		a[i][j]=c[i][j];
}
int main()
{
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		f[i][j]=g[i][j]=ans[i][j]=-10000000;
		
	for (int i=1;i<=n;i++) f[i][i]=1;
	for (int j=2;j<=n;j++)
	for (int i=1;i<=n-j+1;i++)
	if (a[i]<=a[i+j-1])
	{
		for (int k=i;k<i+j-1;k++)
		if (a[k]<=a[i+j-1])
			f[i][i+j-1]=max(f[i][i+j-1],f[i][k]+1);
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	for (int k=1;k<=j;k++)
	if (a[k]>=a[i]) g[i][j]=max(g[i][j],f[k][j]);
	
	for (int i=1;i<=n;i++) ans[i][i]=0;

	while (t)
	{
		if (t&1) pluss(ans,g);
		t>>=1;pluss(g,g);
	}
	int res=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		res=max(res,ans[i][j]);
	printf("%d\n",res);
	return 0;
}