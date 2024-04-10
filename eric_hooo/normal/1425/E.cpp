#include <bits/stdc++.h>
using namespace std;

int a[100010], d[100010];
long long suc[100010];

int main () {
	int n, k; scanf("%d%d", &n, &k);
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int minj = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		if (i != n) minj = min(minj, d[i]);
	}
	if (k >= 2) {
		printf("%lld\n", max(max(0ll, (long long)a[n] - d[n]), sum - minj));
		return 0;
	}
	if (k == 0) {
		long long ans = 0, cur = 0;
		for (int i = n; i >= 1; i--) {
			cur += a[i];
			ans = max(ans, cur - d[i]);
		}
		printf("%lld\n", ans);
		return 0;
	}
	long long ans = 0, cur = 0;
	for (int i = n; i >= 2; i--) {
		cur += a[i];
		suc[i] = max(suc[i + 1], cur - d[i]);
		ans = max(ans, cur - d[i]);
	}
	for (int i = 2; i <= n; i++) {
		ans = max(ans, sum - a[i] - d[1]);
	}
	long long pre = 0; minj = 0x3f3f3f3f;
	for (int i = 1; i <= n - 1; i++) {
		pre = pre + a[i], minj = min(minj, d[i]);
		ans = max(ans, max(0ll, pre - minj) + suc[i + 1]);
	}
	printf("%lld\n", ans);
	return 0;
}