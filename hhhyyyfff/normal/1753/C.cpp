#include <bits/stdc++.h>

using namespace std;
#define P 998244353

int t, n, a[200001], c0, c1, cnt, ans;

long long sqr(long long x) { return x * x % P; }

long long inv(long long x, int y = P - 2) {
	long long ans = 1;
	while (y) {
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cnt = c0 = c1 = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (a[i]) ++c1; else ++c0;
		}
		for (int i = 1; i <= c0; ++i)
			if (a[i])
				++cnt;
		ans = 0;
		while (cnt) {
			ans = (ans + inv(2 * sqr(cnt) * inv(n) % P * inv(n - 1) % P)) % P;
			--cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}