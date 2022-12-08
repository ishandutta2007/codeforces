#include <bits/stdc++.h>

using namespace std;

char s[400001];
int n, sum[20], maxm[20], f[20][400001], ssum[1 << 20], g[1 << 20], ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		for (int j = 0; s[j]; ++j) {
			sum[i] += s[j] == '(' ? 1 : -1;
			if (sum[i] < maxm[i]) maxm[i] = sum[i];
			if (sum[i] <= 0 && sum[i] == maxm[i]) ++f[i][-sum[i]];
		}
	}
	for (int i = 1; i < 1 << n; ++i) {
		for (int j = 0; j < n; ++j)
			if (i & 1 << j) {
				ssum[i] = ssum[i ^ 1 << j] + sum[j];
				break;
			}
		g[i] = -1;
		for (int j = 0; j < n; ++j)
			if (i & 1 << j) {
				if (g[i ^ 1 << j] == -1) continue;
				ans = max(ans, g[i ^ 1 << j] + f[j][ssum[i ^ 1 << j]]);
				if (ssum[i ^ 1 << j] + maxm[j] >= 0)
					g[i] = max(g[i], g[i ^ 1 << j] + f[j][ssum[i ^ 1 << j]]);
			}
	}
	printf("%d\n", ans);
	return 0;
}