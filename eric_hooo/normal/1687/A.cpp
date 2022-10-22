#include <bits/stdc++.h>
using namespace std;

int a[200010];
long long S[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			S[i] = S[i - 1] + a[i];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			int j = max(0, i - k);
			ans = max(ans, S[i] - S[j] + 1ll * (i - j) * k - 1ll * (i - j) * (i - j + 1) / 2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}