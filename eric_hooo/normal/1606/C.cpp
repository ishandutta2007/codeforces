#include <bits/stdc++.h>
using namespace std;

long long pw[20] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int a[20];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k), k++;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			int tmp = i + 1 == n ? 0x3f3f3f3f : pw[a[i + 1] - a[i]] - 1;
			tmp = min(tmp, k);
			ans += pw[a[i]] * tmp, k -= tmp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}