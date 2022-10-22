#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

char s[1010][1010];
int a[260][260], f[260], g[260];
int dp[260];

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < 4 * n + 1; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x = i * 4 - 4, y = j * 4 - 4;
			int cnt = 0;
			for (int xx = x + 1; xx <= x + 3; xx++) {
				for (int yy = y + 1; yy <= y + 3; yy++) {
					cnt += s[xx][yy] == 'O';
				}
			}
			if (cnt == 0 || cnt == 1 || cnt == 4 || cnt == 5) a[i][j] = 0;
			else if (cnt == 2 || cnt == 3) a[i][j] = s[x + 1][y + 1] == 'O' ? -1 : 1;
			else a[i][j] = s[x + 1][y + 2] == 'O' ? -1 : 1;
		}
	}
	if (n % 2 == 0) {
		for (int j = 1; j <= m; j++) {
			f[j] = 1;
			for (int i = 1; i <= n; i++) {
				if (a[i][j] < 0) f[j] = 0;
			}
		}
	}
	for (int j = 2; j <= m; j++) {
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i] = 0;
			if (a[i][j - 1] <= 0 && a[i][j] <= 0) dp[i] += dp[i - 1];
			if (i > 1 && a[i][j - 1] >= 0 && a[i][j] >= 0 && a[i - 1][j] >= 0 && a[i - 1][j - 1] >= 0) {
				dp[i] += dp[i - 2];
			}
			if (dp[i] >= mod) dp[i] -= mod;
		}
		g[j] = dp[n] - (f[j - 1] && f[j] ? 1 : 0);
	}
	dp[0] = 1;
	for (int j = 1; j <= m; j++) {
		dp[j] = 0;
		if (f[j]) dp[j] = dp[j - 1];
		if (j > 1 && g[j]) dp[j] = (dp[j] + 1ll * dp[j - 2] * g[j]) % mod;
	}
	printf("%d\n", dp[m]);
	return 0;
}