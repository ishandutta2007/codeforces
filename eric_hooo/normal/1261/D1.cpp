#include <bits/stdc++.h>
using namespace std;

const int base = 2000;
const int mod = 998244353;

int a[100010];
int dp[2010][4010];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main () {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[n + 1] = a[1];
	dp[1][base] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 2 * base; j++) {
			if (!dp[i][j]) continue;
			int val = dp[i][j];
			if (a[i] == a[i + 1]) add(dp[i + 1][j], 1ll * val * k % mod);
			else add(dp[i + 1][j], 1ll * val * (k - 2) % mod), 
				 add(dp[i + 1][j + 1], val), add(dp[i + 1][j - 1], val);
		}
	}
	int ans = 0;
	for (int i = base + 1; i <= 2 * base; i++) {
		add(ans, dp[n + 1][i]);
	}
	printf("%d\n", ans);
	return 0;
}