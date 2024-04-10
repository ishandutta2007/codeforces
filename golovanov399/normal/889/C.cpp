#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

long long pw(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

int main() {
	int n = nxt(), k = nxt();
	
	vector<int> inv(n + 1);
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = (mod - 1ll * mod / i * inv[mod % i] % mod) % mod;
	}

	vector<long long> g(n + 1);
	g[0] = 1;
	long long cursum = 1;
	for (int i = 1; i <= n; ++i) {
		g[i] = cursum;
		g[i] = g[i] * inv[i] % mod;
		cursum += g[i];
		if (i >= k) {
			cursum -= g[i - k];
		}
		cursum %= mod;
		if (cursum < 0) {
			cursum += mod;
		}
	}

	long long fct = 1;
	vector<long long> fact(n + 1);
	for (int i = 1; i <= n; ++i) {
		fct = fct * i % mod;
		fact[i] = fct;
		g[i] = g[i] * fct % mod;
	}

	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		long long tmp = fact[i] - g[i];
		if (tmp < 0) {
			tmp += mod;
		}
		ans += tmp * fact[n - 1] % mod * pw(fact[i], mod - 2) % mod;
	}
	cout << ans % mod << "\n";

	return 0;
}