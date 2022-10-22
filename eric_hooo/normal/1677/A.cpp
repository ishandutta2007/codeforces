#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		static int a[5010], pre[5010][5010], suc[5010][5010];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				pre[i][j] = (i == 1 ? 0 : pre[i - 1][j]) + (a[i] <= j);
			}
		}
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j <= n; j++) {
				suc[i][j] = (i == n ? 0 : suc[i + 1][j]) + (a[i] <= j);
			}
		}
		long long ans = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += pre[i - 1][a[j]] * suc[j + 1][a[i]];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}