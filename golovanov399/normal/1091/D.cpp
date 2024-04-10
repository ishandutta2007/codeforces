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

const int mod = 998244353;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<long long> a(n + 1);
	long long cur = 1;
	for (int i = 0; i <= n; ++i) {
		a[n - i] = cur;
		cur = cur * (n - i) % mod;
	}
	for (int i = 0; i < n; ++i) {
		a[i] = (a[i] + mod - a[i + 1]) % mod;
	}

	long long ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans = ans * i % mod;
	}
	for (int i = 0; i < n; ++i) {
		ans += a[i] * (n - i - 1) % mod;
	}
	cout << ans % mod << "\n";

	return 0;
}