#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int a[1000010];
int cnt[1000010];
vector <int> p;
long long fac[1000010], inv[1000010];

long long C(int n, int k) {
	if (n < 0 || k < 0 || k > n) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
	fac[0] = 1; for (int i = 1; i <= 1000005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[1000005] = power(fac[1000005], mod - 2); for (int i = 1000004; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			cnt[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		p.clear();
		for (int i = 1; i <= n; i++) {
			if (cnt[i]) p.push_back(cnt[i]);
		}
		sort(p.begin(), p.end());
		if (p.size() == 1) {
			printf("1\n");
			continue;
		}
		int G = 0;
		for (auto x : p) {
			G = gcd(G, x);
		}
		int tot = 0, con = 0;
		for (int i = 1; i <= n; i++) {
			int d = gcd(n, i), k = n / d, D = d;
			if (G % k != 0) continue;
			long long coef = 1, cccc = 0;
			long long dp[2] = {1, 0};
			int used = 0;
			for (auto it : p) {
				it /= k;
				long long ndp[2] = {0, 0};
				ndp[0] = dp[0] * C(D - 2 - used, it) % mod;
				ndp[1] = dp[1] * C(D - used, it) % mod;
				if (it > 1) {
					ndp[1] = (ndp[1] + dp[0] * C(D - 2 - used, it - 2)) % mod;
				}
				dp[0] = ndp[0], dp[1] = ndp[1];
				used += it;
				coef = coef * C(d, it) % mod, d -= it;
			}
			ADD(tot, coef), ADD(con, dp[1]);
		}
		tot = tot * power(n, mod - 2) % mod;
		long long ans = 1ll * (1ll * tot * n % mod - con + mod) * power(tot, mod - 2) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}