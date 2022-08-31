#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

constexpr int mod = 1'000'000'007;

void solve() {
	int n = nxt(), m = nxt(), k = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	long long ans = 0;
	vector<long long> inv(n + 1);
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = mod - mod / i * inv[mod % i] % mod;
	}
	vector<long long> C(n + 1);
	C[m - 1] = 1;
	for (int i = m; i <= n; ++i) {
		C[i] = C[i - 1] * i % mod * inv[i - m + 1] % mod;
	}
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && a[j] <= a[i] + k) {
			++j;
		}
		ans += C[j - i - 1];
	}
	cout << ans % mod << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}