#include <bits/stdc++.h>
using namespace std;

int a[1000010];
int cnt[1000010];

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			cnt[i] = 0;
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			ans += abs(a[i]);
		}
		int D = 0;
		for (int i = 0; i < m; i++) {
			int x; scanf("%d", &x);
			D = gcd(D, x);
		}
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) cnt[i % D]++;
		}
		long long s0 = 0, s1 = 0;
		for (int i = 0; i < D; i++) {
			int minj = 0x3f3f3f3f;
			for (int j = i; j < n; j += D) {
				minj = min(minj, abs(a[j]));
			}
			if (cnt[i] & 1) s1 += minj * 2;
			else s0 += minj * 2;
		}
		ans -= min(s0, s1);
		printf("%lld\n", ans);
	}
	return 0;
}