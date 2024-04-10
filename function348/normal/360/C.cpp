#include<cstdio>
#include<iostream>
using namespace std;
const int N=2010,p=1000000007;
int n,k;
char s[N];
int f[N][N],g[N][N];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	f[0][0]=1;g[0][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=k;j++)
	{
		f[i][j]=1LL*g[i-1][j]*(s[i]-'a')%p;
		for (int l=0;(1+l)*(n-i+1)<=j&&i-l-1>=0;l++)
			f[i][j]=(f[i][j]+1LL*f[i-l-1][j-(1+l)*(n-i+1)]*('z'-s[i]))%p;
		g[i][j]=(g[i-1][j]+f[i][j])%p;
	}
	int ans=g[n][k];
	printf("%d\n",ans);
	return 0;
}