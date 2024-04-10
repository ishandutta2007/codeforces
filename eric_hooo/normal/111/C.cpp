#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int cnt[100];
int dp[50][100][100];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	if (n < m) swap(n, m);
	cnt[0] = 0;
	for (int i = 1; i < (1 << m); i++){
		cnt[i] = cnt[i & (i - 1)] + 1;
	}
	memset(dp, INF, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < (1 << m); j++){
			for (int k = 0; k < (1 << m); k++){
				if (dp[i][j][k] == INF) continue;
				for (int t = 0; t < (1 << m); t++){
					if (i && (j | t) != (1 << m) - 1) continue;
					int nt = (k | t | t << 1 | t >> 1) & (1 << m) - 1;
					dp[i + 1][nt][t] = min(dp[i + 1][nt][t], dp[i][j][k] + cnt[t]);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < (1 << m); i++){
		ans = min(ans, dp[n][(1 << m) - 1][i]);
	}
	printf("%d\n", n * m - ans);
	return 0;
}