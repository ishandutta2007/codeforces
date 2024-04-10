#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int inv2 = 500000004;

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

long long fac[1000010];
long long inv[1000010];
long long pw[1000010];

long long C(int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
	pw[0] = 1; for (int i = 1; i <= 1000005; i++) pw[i] = pw[i - 1] * inv2 % mod;
	fac[0] = 1; for (int i = 1; i <= 1000005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[1000005] = power(fac[1000005], mod - 2); for (int i = 1000004; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	int T; scanf("%d", &T);
	while (T--) {
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		n -= m, swap(n, m);
		if (m == 0) {
			printf("%lld\n", 1ll * n * k % mod);
			continue;
		}
		long long ans = 0;
		for (int i = 0; i <= n; i++) {
			ans = (ans + 1ll * i * C(n + m - i - 1, m - 1) % mod * pw[n + m - i]) % mod;
		}
		printf("%lld\n", ans * k % mod);
	}
	return 0;
}