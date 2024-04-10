#include<bits/stdc++.h>
using namespace std;
const int N=2005,mod=1e9+7;
int f[N][N],t,n,m,k;
int main()
{
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<i;j++)
			f[i][j]=1ll*(f[i-1][j-1]+f[i-1][j])*(mod+1)/2%mod;
		f[i][i]=i;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		int v=1ll*k*f[n][m]%mod;
		printf("%d\n",v);
	}
	return 0;
}