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

constexpr int mod = 998'244'353;

constexpr int N = 555555;
long long fact[N];
long long inv[N];
long long invfact[N];

long long C(int n, int k) {
	if (n < k) {
		return 0;
	}
	return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; ++i) {
		inv[i] = (i == 1) ? 1 : mod - inv[mod % i] * (mod / i) % mod;
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = invfact[i - 1] * inv[i] % mod;
	}

	int n = nxt(), m = nxt();
	assert(!m);
	string s;
	cin >> s;
	int can[2] = {0, 0};
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'b') {
			cur += (i % 2 == 0) ? 1 : -1;
		} else if (s[i] == '?') {
			can[i % 2] += 1;
		}
	}
	int tot = can[0] + can[1];
	cur -= can[1];
	long long ans = 0;
	for (int i = 0; i <= tot; ++i) {
		if ((cur + i) % 2 == 0) {
			ans += C(tot, i) * abs(cur + i) % mod;
		}
	}
	ans %= mod;
	for (int i = 0; i < tot; ++i) {
		ans = ans * inv[2] % mod;
	}
	cout << ans << "\n";

	return 0;
}