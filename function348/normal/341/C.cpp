#include<cstdio>
#include<iostream>
using namespace std;
const int N=2010,p=1000000007;
int n;
int a[N],v[N],f[N][N*2];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if (a[i]!=-1) v[a[i]]=1;
	}
	int k1=0,m=0;
	for (int i=1;i<=n;i++)
	if (a[i]==-1)
	{
		if (v[i]) m++;else k1++;
	}
	n=k1;
	f[0][1]=1;
	for (int i=2;i<=n+m;i++) f[0][i]=1LL*f[0][i-1]*i%p;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n+m;j++)
		{
			if (i>=2) f[i][j]=(f[i][j]+1LL*(i-1)*f[i-2][j+1])%p;
			f[i][j]=(f[i][j]+1LL*j*f[i-1][j])%p;
		}
	}
	printf("%d\n",f[n][m]);
	return 0;
}