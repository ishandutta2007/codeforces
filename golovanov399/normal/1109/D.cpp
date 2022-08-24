#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 1111111;
long long fact[N], inv[N], invfact[N];

const int mod = 1000000007;

inline long long C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

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

	int n = nxt(), m = nxt();
	[[maybe_unused]] int a = nxt(), b = nxt();

	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; ++i) {
		inv[i] = (i == 1) ? 1 : mod - mod / i * inv[mod % i] % mod;
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = invfact[i - 1] * inv[i] % mod;
	}

	long long ans = 0;
	long long curm = 1;
	for (int i = 0; i < n - 1; ++i) {
		curm = curm * m % mod;
	}
	for (int k = 1; k < n; ++k) {
		curm = curm * inv[m] % mod;
		ans += curm * C(m - 1, k - 1) % mod * fact[n - 2] % mod * invfact[n - 2 - (k - 1)] % mod * (n - k - 2 < 0 ? 1ll : pw(n, n - k - 2) % mod * (k + 1) % mod) % mod;
	}

	cout << ans % mod << "\n";

	return 0;
}