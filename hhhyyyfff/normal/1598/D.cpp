#include <bits/stdc++.h>

using namespace std;

int t, n, a[200000], b[200000], cnt_a[200001], cnt_b[200001];
long long ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(cnt_a, 0, sizeof(int) * (n + 1));
		memset(cnt_b, 0, sizeof(int) * (n + 1));
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
			++cnt_a[a[i]];
			++cnt_b[b[i]];
		}
		ans = n * (n - 1ll) * (n - 2) / 6;
		for (int i = 0; i < n; ++i)
			ans -= (cnt_a[a[i]] - 1ll) * (cnt_b[b[i]] - 1);
		printf("%lld\n", ans);
	}
	return 0;
}