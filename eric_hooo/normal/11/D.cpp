#include <bits/stdc++.h>
using namespace std;

long long dp[20][530010];
int a[20][20];
int cnt[1000010];

int main(){
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i < (1 << n); i++){
		cnt[i] = cnt[i - (i & -i)] + 1;
	}
	for (int i = 0; i < m; i++){
		int u, v; scanf("%d%d", &u, &v);
		u--, v--;
		a[u][v] = a[v][u] = 1;
	}
	long long ans = 0;
	for (int i = n - 1; i >= 0; i--){
		for (int j = 0; j < i; j++){
			for (int mask = 0; mask < (1 << i); mask++){
				dp[j][mask] = 0;
			}
		}
		for (int j = 0; j < i; j++){
			if (a[i][j]) dp[j][1 << j] = 1;
		}
		for (int mask = 0; mask < (1 << i); mask++){
			for (int j = 0; j < i; j++){
				if (!dp[j][mask]) continue;
				for (int k = 0; k < i; k++){
					if ((mask >> k & 1) || !a[k][j]) continue;
					dp[k][mask | 1 << k] += dp[j][mask];
				}
			}
		}
		int old = ans;
		for (int j = 0; j < i; j++){
			if (!a[j][i]) continue;
			for (int mask = 0; mask < (1 << i); mask++){
				if (cnt[mask] > 1) ans += dp[j][mask];
			}
		}
	}
	printf("%I64d\n", ans / 2);
	return 0;
}