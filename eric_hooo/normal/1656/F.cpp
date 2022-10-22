#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;

int a[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int maxj = -inf, minj = inf;
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			maxj = max(maxj, a[i]);
			minj = min(minj, a[i]);
			sum += a[i];
		}
		if (sum + maxj * (n - 2ll) < 0 || sum + minj * (n - 2ll) > 0) {
			printf("INF\n");
			continue;
		}
		sort(a + 1, a + n + 1);
		long long pre = 0, suc = 0;
		for (int i = 1; i <= n; i++) {
			suc += a[i];
		}
		long long ans = -0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i <= n; i++) {
			suc -= a[i];
			long long lef = pre - 1ll * (i - 1) * a[i], rig = suc - 1ll * (n - i) * a[i];
			long long sum = lef * (a[n] - a[i]) + rig * (a[1] - a[i]) - 1ll * (a[1] - a[i]) * (a[n] - a[i]);
			ans = max(ans, sum - 1ll * a[i] * a[i] * (n - 1));
			pre += a[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}