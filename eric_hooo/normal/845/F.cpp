#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

char a[300][300], tmp[300][300];
int n, m;

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

void rotate() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[j][i] = a[i][j];
		}
	}
	swap(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

int dp[2][1 << 15][2][2];

int main () {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	if (n < m) rotate();
	int now = 0, pre = 1;
	dp[now][0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			swap(now, pre);
			memset(dp[now], 0, sizeof(dp[now]));
			for (int mask = 0; mask < (1 << m); mask++) {
				for (int p1 = 0; p1 < 2; p1++) {
					for (int p2 = 0; p2 < 2; p2++) {
						if (!dp[pre][mask][p1][p2]) continue;
						int val = dp[pre][mask][p1][p2];
						int np1 = j == 0 ? 0 : p1;
						int cover = !((mask >> j & 1) | np1);
						// put
						if (a[i][j] != 'x') add(dp[now][mask | 1 << j][1][p2], val);
						// not put
						if (a[i][j] == 'x') add(dp[now][mask & ~(1 << j)][0][p2], val);
						if (a[i][j] == '.' && p2 + cover < 2) add(dp[now][mask][np1][p2 + cover], val);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				add(ans, dp[now][i][j][k]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}