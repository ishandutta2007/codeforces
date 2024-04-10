#include<cstdio>
#include<iostream>
using namespace std;
const int p=1000000007;
int n,m,x;
int f[2][400][400];
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	if (n>m)
	{
		printf("0\n");
		return 0;
	}
	f[0][0][0]=1;
	for (int i=1;i<=m;i++)
	{
		int c=i&1;
		for (int j=0;j<=n;j++)
		for (int k=0;k<=j;k++)
		{
			int now=0;
			if (i!=x) now=f[c^1][j][k];
			if (j) now=(now+f[c^1][j-1][k])%p;
			if (k&&i!=x) now=(now+f[c^1][j][k-1])%p;
			if (j&&k) now=(now+f[c^1][j-1][k-1])%p;
			f[c][j][k]=now;
		}
	}
	int ans=f[m&1][n][n];
	for (int i=1;i<=n;i++) ans=1LL*ans*i%p;
	printf("%d\n",ans);
	return 0;
}