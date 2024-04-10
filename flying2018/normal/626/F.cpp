#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 210
#define M 1010
#define ll long long
#define mod 1000000007
using namespace std;
int v[N];
int f[N][N][M];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	sort(v+1,v+n+1);
	for(int i=0;i<n;i++) v[i]=v[i+1]-v[i];
	f[0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=m-v[i]*j;k++)
			{
				f[i+1][j][k+v[i]*j]=(f[i+1][j][k+v[i]*j]+1ll*f[i][j][k]*(j+1)%mod)%mod;
				f[i+1][j+1][k+v[i]*j]=(f[i+1][j+1][k+v[i]*j]+f[i][j][k])%mod;
				if(j) f[i+1][j-1][k+v[i]*j]=(f[i+1][j-1][k+v[i]*j]+1ll*f[i][j][k]*j%mod)%mod;
			}
	int ans=0;
	for(int i=0;i<=m;i++) ans=(ans+f[n][0][i])%mod;
	printf("%d\n",ans);
	return 0;
}