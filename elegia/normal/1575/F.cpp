#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

const int P = 1000000007, Q = P - 1;
 
int mpow(int x, int k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

const int N = 100010;

int e[N], fac[N], ifac[N], inv[N], pp[N], pq[N];
int cnt[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, k; std::cin >> n >> k;
	fac[0] = 1; for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * (ull)i % P;
	ifac[n] = mpow(fac[n], P - 2); for (int i = n; i; --i) ifac[i - 1] = ifac[i] * (ull)i % P;
	for (int i = 1; i <= n; ++i) inv[i] = ifac[i] * (ull)fac[i - 1] % P;

	int p = mpow(k, P - 2), in = inv[n];
	e[0] = k;
	for (int i = 1; i != n; ++i) {
		e[i] = (i * (ull)(k - 1) % P * p % P * in % P * e[i - 1] + 1) % P;
		e[i] = e[i] * (ull)n % P * k % P * inv[n - i] % P;
	}
	for (int i = n - 1; i >= 0; --i) e[i] = (e[i] + e[i + 1]) % P;

	std::unordered_map<int, int> mp;
	int oth = 0;
	for (int rep = 0; rep != n; ++rep) {
		int ai; std::cin >> ai;
		if (ai == -1) ++oth;
		else ++mp[ai];
	}

	int q = 1 - p; if (q < 0) q += P;
	pp[0] = 1; for (int i = 1; i <= n; ++i) pp[i] = pp[i - 1] * (ull)p % P;
	pq[0] = 1; for (int i = 1; i <= n; ++i) pq[i] = pq[i - 1] * (ull)q % P;
	auto cal = [&](int c) {
		int ret = 0;
		for (int i = 0; i <= oth; ++i) {
			ret = (ret + pp[i] * (ull)pq[oth - i] % P * ifac[i] % P * ifac[oth - i] % P * e[c + i]) % P;
		}
		return ret * (ull)fac[oth] % P;
	};
	cnt[0] = k;
	for (const auto& pr : mp) { ++cnt[pr.second]; --cnt[0]; }
	int ans = (P - k + 1) * (ull)e[0] % P;
	for (int i = 0; i <= n; ++i) if (cnt[i]) ans = (ans + cnt[i] * (ull)cal(i)) % P;
	ans = ans * (ull)p % P;
	std::cout << ans << '\n';


	return 0;
}