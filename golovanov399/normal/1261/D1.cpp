#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 222222;
const int mod = 998244353;
long long fact[N], inv[N], invfact[N];

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
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; ++i) {
		inv[i] = (i == 1) ? 1 : mod - mod / i * inv[mod % i] % mod;
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = invfact[i - 1] * inv[i] % mod;
	}

	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	int d = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != a[(i + 1) % n]) {
			++d;
		}
	}

	if (d == 0) {
		cout << "0\n";
		return 0;
	}

	vector<long long> deg(d + 1);
	deg[0] = 1;
	for (int i = 1; i <= d; ++i) {
		deg[i] = deg[i - 1] * (k - 2) % mod;
	}

	long long ans = 0;
	for (int k = 0; k * 2 <= d; ++k) {
		ans += fact[d] * invfact[k] % mod * invfact[k] % mod * invfact[d - 2 * k] % mod * deg[d - 2 * k] % mod;
	}
	ans %= mod;
	for (int i = 0; i < n - d; ++i) {
		ans = ans * k % mod;
	}
	ans = (pw(k, n) - ans + mod) % mod;
	if (ans % 2) {
		ans += mod;
	}
	ans /= 2;
	cout << ans << "\n";

	return 0;
}