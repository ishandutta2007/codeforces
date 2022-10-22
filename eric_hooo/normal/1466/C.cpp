#include <bits/stdc++.h>
using namespace std;

char s[100010];
int dp[100010][4];

void chmin(int &x, int y) {
	x = min(x, y);
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 4; j++) {
				dp[i][j] = 0x3f3f3f3f;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 4; j++) {
				if (((j & 1) && s[i - 2] == s[i]) || ((j & 2) && s[i - 1] == s[i])) {
					chmin(dp[i + 1][j >> 1], dp[i][j] + 1);
					continue;
				}
				chmin(dp[i + 1][j >> 1 | 2], dp[i][j]);
				chmin(dp[i + 1][j >> 1], dp[i][j] + 1);
			}
		}
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < 4; i++) {
			ans = min(ans, dp[n][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}