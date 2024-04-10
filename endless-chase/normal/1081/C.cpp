#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long dp[2222][2222];
const long long mod=998244353;
int main()
{
	cin>>n>>m>>k;
	dp[1][1]=m;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=k+1;j++)
		{
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*(long long)(m-1))%mod;
		}
	}
	printf("%lld\n",dp[n][k+1]);
	return 0;
}