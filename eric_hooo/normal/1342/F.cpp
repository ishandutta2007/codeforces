#include <bits/stdc++.h>
using namespace std;

int a[20];
int dp[1 << 15][15][15], lst[1 << 15][15][15];
int sum[1 << 15], cnt[1 << 15];
int num[67];

int NUM(int mask) {return num[mask % 67];}

bool chmin(int &x, int y) {return (x = x < y ? x : y) == y;}

int main() {
	for (int i = 0; i < (1 << 15); i++) cnt[i] = cnt[i >> 1] + (i & 1);
	for (int i = 0; i < 20; i++) num[(1 << i) % 67] = i;
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int mask = 1; mask < (1 << n); mask++) sum[mask] = sum[mask - 1 & mask] + a[NUM(mask & -mask)];
		for (int mask = 0; mask < (1 << n); mask++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) dp[mask][i][j] = 0x3f3f3f3f;
			}
		}
		for (int mask = 1; mask < (1 << n); mask++) {
			dp[mask][NUM(mask & -mask)][0] = sum[mask];
			lst[mask][NUM(mask & -mask)][0] = mask << 4;
		}
		for (int mask = 1; mask < (1 << n); mask++) {
			int tot = cnt[mask], MMM = mask ^ (1 << n) - 1;
			for (int i = 0; i < n; i++) {
				if (!(mask >> i & 1)) continue;
				for (int mmm = MMM; mmm; mmm = mmm - 1 & MMM) {
					int val = sum[mmm], tmp = mmm & ~((1 << i + 1) - 1);
					if (!tmp) break;
					int ni = NUM(tmp & -tmp);
					for (int j = 0; j < tot; j++) {
						if (dp[mask][i][j] >= val) continue;
						if (chmin(dp[mask | mmm][ni][j + 1], val)) {
							lst[mask | mmm][ni][j + 1] = mmm << 4 | i;
						}
					}
				}
			}
		}
		for (int j = n - 1; j >= 0; j--) {
			for (int i = 0; i < n; i++) {
				if (dp[(1 << n) - 1][i][j] != 0x3f3f3f3f) {
					printf("%d\n", n - j - 1);
					int mask = (1 << n) - 1, x = i, y = j, cur = (1 << n) - 1;
					while (y != -1) {
						int mmm = lst[mask][x][y] >> 4, nx = lst[mask][x][y] & 15;
						for (int i = 0; i < n; i++) {
							if ((mmm >> i & 1) && i != x) {
								int idx = 0;
								for (int j = 0; j <= i; j++) idx += cur >> j & 1;
								int idy = 0;
								for (int j = 0; j <= x; j++) idy += cur >> j & 1;
								printf("%d %d\n", idx, idy);
								cur ^= 1 << i;
							}
						}
						mask ^= mmm, x = nx, y--;
					}
					goto END;
				}
			}
		}
		END:;
	}
	return 0;
}