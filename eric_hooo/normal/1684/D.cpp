#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		static int a[200010];
		static int p[200010], q[200010];
		long long base = 0;
		for (int i = 1; i <= k; i++) {
			base += i;
		}
		long long ans = 0;
		static vector <int> all; all.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			p[i] = a[i], q[i] = (n - i) - k;
			ans += a[i];
			all.push_back(p[i] - q[i]);
		}
		sort(all.rbegin(), all.rend());
		for (int i = 0; i < k; i++) {
			ans -= all[i];
		}
		ans += base;
		printf("%lld\n", ans);
	}
	return 0;
}