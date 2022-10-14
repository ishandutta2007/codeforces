// Codeforces Beta Round #14
// Problem E -- Camels
#include <cstdio>
#include <cstring>

using namespace std;

int n, t, dp[20][4][4][11][11];

int main()
{
	scanf("%d%d", &n, &t);
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i != 4; ++ i)
		for(int j = 0; j != 4; ++ j)
			dp[1][i][j][0][0] = i != j;
	for(int i = 2; i != n; ++ i)
		for(int j = 0; j != 4; ++ j)
			for(int k = 0; k != 4; ++ k)
				for(int l = 0; l <= t; ++ l)
					for(int m = 0; m <= t; ++ m)
						for(int o = 0; o != 4; ++ o)
							dp[i][k][o][l + (j < k && k > o)][m + (j > k && k < o)] += k == o? 0: dp[i - 1][j][k][l][m];
	int ans = 0;
	for(int i = 0; i != 4; ++ i)
		for(int j = 0; j != 4; ++ j)
			ans += dp[n - 1][i][j][t][t - 1];
	printf("%d\n", ans);
	return 0;
}