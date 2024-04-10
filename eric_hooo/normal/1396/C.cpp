#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int a[1000010];
long long t1[1000010], t2[1000010], sum[1000010];
long long r1, r2, r3, d, dp[1000010];

long long get_t1(int x) {
	return min(r2, r1 * x + r1) + r1;
}

long long get_t2(int x) {
	return min(r1 * x + r3, get_t1(x) + 2 * d);
}

int main () {
	int n; scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		t1[i] = get_t1(a[i]), t2[i] = get_t2(a[i]);
	}
	for (int i = n; i >= 1; i--) {
		sum[i] = sum[i + 1] + (i == n ? t2[i] : min(t1[i], t2[i]));
	}
	dp[0] = -d;
	long long minj = INF;
	for (int i = 1; i <= n; i++) {
		if (i - 2 >= 0) minj = min(minj, dp[i - 2] + t1[i - 1]);
		minj += 3 * d + t1[i];
		dp[i] = min(dp[i - 1] + t2[i] + d, minj + d);
	}
	long long ans = dp[n];
	for (int i = 1; i < n; i++) {
		ans = min(ans, dp[i - 1] + sum[i] + d + d * (n - i) * 2);
	}
	printf("%lld\n", ans);
	return 0;
}