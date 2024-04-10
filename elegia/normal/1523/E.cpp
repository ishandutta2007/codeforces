#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int P = 1000000007;

const int N = 100000, SZ = N + 10;

int fac[SZ], ifac[SZ], inv[SZ];

int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

int binom(int n, int m) {
	return fac[n] * (ull)ifac[m] % P * ifac[n - m] % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	fac[0] = 1;
	for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * (ull)i % P;
	ifac[N] = mpow(fac[N], P - 2);
	for (int i = N; i; --i) ifac[i - 1] = ifac[i] * (ull)i % P;
	for (int i = 1; i <= N; ++i) inv[i] = ifac[i] * (ull)fac[i - 1] % P;
	
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		int ans = 1;
		for (int i = 1; n - (k - 1) * (i - 1) >= i; ++i) {
			int ways = binom(n - (k - 1) * (i - 1), i);
			ans = (ans + ways * (ull)ifac[n] % P * fac[n - i] % P * fac[i]) % P;
		}
		cout << ans << '\n';
	}
	
	return 0;
}