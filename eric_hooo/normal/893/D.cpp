#include <bits/stdc++.h>
using namespace std;

int sum[100010], a[100010];

int main () {
	int n, d; scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	long long minj = 0, maxj = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (maxj < 0) maxj = d, minj = 0, ans++;
			else minj = max(minj, 0ll);
		} else {
			minj += a[i], maxj += a[i];
			if (minj > d) {
				printf("-1\n");
				return 0;
			}
			maxj = min(maxj, 1ll * d);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}