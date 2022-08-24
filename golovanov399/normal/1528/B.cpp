#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

constexpr int mod = 998'244'353;

void solve() {
	int n = nxt();
	vector<long long> p2(n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		p2[i] = p2[i - 1] * 2 % mod;
	}
	long long ans = 0;
	for (int d = 1; d <= n; ++d) {
		for (int k = d; k <= n; k += d) {
			ans += (n == k) ? 1 : p2[n - k - 1];
		}
	}
	cout << ans % mod << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}