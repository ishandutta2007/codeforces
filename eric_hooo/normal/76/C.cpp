#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

char s[200010];
long long dp[1 << 22];
int c[30], d[30][30];

int main () {
	int n, k, T; scanf("%d%d%d", &n, &k, &T);
	int full = 0;
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		full |= 1 << s[i] - 'A';
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &d[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		int j = i + 1, ban = 0;
		while (j < n && s[i] != s[j]) {
			if (!(ban >> s[j] - 'A' & 1)) {
				int x = s[i] - 'A', y = s[j] - 'A';
				dp[ban] += d[x][y];
				dp[ban | 1 << x] -= d[x][y];
				dp[ban | 1 << y] -= d[x][y];
				dp[ban | 1 << x | 1 << y] += d[x][y];
			}
			ban |= 1 << s[j] - 'A', j++;
		}
		if (j != n) {
			int x = s[i] - 'A';
			dp[ban] += d[x][x];
			dp[ban | 1 << x] -= d[x][x];
		}
	}
	for (int i = 0; i < k; i++) {
		for (int mask = 0; mask < (1 << k); mask++) {
			if (mask >> i & 1) dp[mask] += dp[mask ^ 1 << i];
		}
	}
	int ans = 0;
	for (int mask = 0; mask < (1 << k); mask++) {
		long long sum = 0;
		for (int i = 0; i < k; i++) {
			if (mask >> i & 1) sum += c[i];
		}
		if ((full | mask) == full && mask != full && dp[mask] + sum <= T) ans++;
//		if ((full | mask) == full && mask != full) cout << mask << " " << dp[mask] + sum << endl;
	}
	printf("%d\n", ans);
	return 0;
}
/*
5 3 13
BACAC
4 1 2
1 2 3
2 3 4
3 4 10


*/