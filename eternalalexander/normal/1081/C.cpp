#include <bits/stdc++.h>

const long long mod=998244353;
long long dp[2005][2005]={0};

int n, m, k;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	dp[1][1]=m; k++;
	for (int i=2;i<=n;++i) {
		for (int j=0;j<=k;++j) {
			dp[i][j]=dp[i-1][j];
			if (j>0) dp[i][j]=(dp[i][j]+dp[i-1][j-1]*(m-1))%mod;
		//	std::cout<<dp[i][j]<<" ";
		}//std::cout<<std::endl;
	}std::cout<<dp[n][k];
	return 0;
}