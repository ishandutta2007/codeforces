#include <bits/stdc++.h>

using namespace std;

int t, n, ai, g, ans;

void dfs(int x, int g, int sum) {
	if (g == 1) {
		ans = min(ans, sum);
		return;
	}
	if (!x) return;
	if (sum + (n - x + 1) >= ans) return;
	dfs(x - 1, __gcd(g, x), sum + (n - x + 1));
	dfs(x - 1, g, sum);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		g = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &ai);
			g = __gcd(g, ai);
		}
		ans = n;
		dfs(n, g, 0);
		printf("%d\n", ans);
	}
	return 0;
}