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

const int mod = 1000000009;
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

	int n = nxt() + 1, a = nxt(), b = nxt(), k = nxt();
	string s;
	cin >> s;

	long long cur = 1;
	long long ans = 0;
	long long c = b * pw(a, mod - 2) % mod;
	for (int i = 0; i < k; ++i) {
		ans += cur * (s[i] == '+' ? 1 : mod - 1) % mod;
		cur = cur * c % mod;
	}
	ans %= mod;

	if (cur == 1) {
		ans *= n / k;
	} else {
		ans = ans * (pw(cur, n / k) - 1) % mod * pw(cur - 1, mod - 2) % mod;
	}
	ans %= mod;
	ans = ans * pw(a, n - 1) % mod;
	cout << ans % mod << "\n";

	return 0;
}