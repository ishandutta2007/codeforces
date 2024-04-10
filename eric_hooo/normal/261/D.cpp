#include <bits/stdc++.h>
using namespace std;

int a[100010];
int dp[100010];

int main () {
	int T; scanf("%d", &T);
	int n, maxB, t; scanf("%d%d%d", &n, &maxB, &t);
	while (T--) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		if (t >= maxB) {
			sort(a, a + n);
			int ans = 1;
			for (int i = 1; i < n; i++) {
				if (a[i] != a[i - 1]) ans++;
			}
			printf("%d\n", ans);
			continue;
		}
		memset(dp, 0, sizeof(dp));
		for (int _ = 0; _ < t; _++) {
			for (int i = 0; i < n; i++) {
				int x = a[i], val = dp[x - 1] + 1;
				while (x <= maxB && dp[x] < val) dp[x] = val, x++;
			}
		}
		printf("%d\n", dp[maxB]);
	}
	return 0;
}