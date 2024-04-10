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

using Poly = vector<long long>;

Poly mult(const Poly& a, const Poly& b) {
	Poly c(a.size() + b.size() - 1);
	for (int i = 0; i < (int)a.size(); ++i) {
		for (int j = 0; j < (int)b.size(); ++j) {
			c[i + j] += a[i] * b[j] % mod;
		}
	}
	for (auto& x : c) {
		x %= mod;
	}
	return c;
}

long long pw(long long a, long long b) {
	if (b < 0) {
		return 0;
	}
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

#define apply kljhaflhadf

long long apply(const Poly& p, long long x) {
	long long res = 0;
	long long cur = 1;
	for (long long c : p) {
		res += c * cur % mod;
		cur = cur * x % mod;
	}
	return res % mod;
}

int main() {
	int n = nxt(), k = nxt();

	vector<Poly> ffs(k + 1);
	ffs[0] = {1};
	for (int i = 1; i <= k; ++i) {
		ffs[i] = mult(ffs[i - 1], {mod - i + 1, 1});
	}

	vector<long long> a(k + 1);
	a[k] = mod - 1;
	for (int i = k; i >= 0; --i) {
		int c = mod - a[i];
		for (int j = 0; j <= i; ++j) {
			a[j] = (a[j] + ffs[i][j] * c) % mod;
		}
		a[i] = c;
	}

	long long ans = 0;
	for (int i = 0; i <= k; ++i) {
		ans += apply(ffs[i], n) * pw(2, n - i) % mod * a[i] % mod;
	}
	cout << ans % mod << "\n";

	return 0;
}