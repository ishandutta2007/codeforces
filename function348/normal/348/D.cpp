#include<cstdio>
#include<iostream>
using namespace std;
const int N=3010,p=1000000007;
int n,m;
int a[N][N],f[N][N];
int dp(int x1,int y1,int x2,int y2)
{
	if (x1>x2||y1>y2) return 0;
	for (int i=x1;i<=x2;i++)
	for (int j=y1;j<=y2;j++)
	{
		f[i][j]=0;
		if (a[i][j]) continue;
		if (i==x1&&j==y1) f[i][j]=1;
		if (i>x1) f[i][j]=(f[i][j]+f[i-1][j])%p;
		if (j>y1) f[i][j]=(f[i][j]+f[i][j-1])%p;
	}
	return f[x2][y2];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		char ch;
		while ((ch=getchar())<=32);
		a[i][j]=ch=='#';
	}
	int ans=(1LL*dp(1,2,n-1,m)*dp(2,1,n,m-1)-1LL*dp(1,2,n,m-1)*dp(2,1,n-1,m))%p;
	ans=(ans+p)%p;
	printf("%d\n",ans);
	return 0;
}