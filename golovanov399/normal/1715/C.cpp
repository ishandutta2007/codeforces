#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] != a[i + 1]) {
			ans += 1ll * (i + 1) * (n - 1 - i);
		}
	}
	auto upd = [&](int i, int x) {
		if (i > 0 && a[i] != a[i - 1]) {
			ans -= 1ll * i * (n - i);
		}
		if (i + 1 < n && a[i] != a[i + 1]) {
			ans -= 1ll * (i + 1) * (n - 1 - i);
		}
		a[i] = x;
		if (i > 0 && a[i] != a[i - 1]) {
			ans += 1ll * i * (n - i);
		}
		if (i + 1 < n && a[i] != a[i + 1]) {
			ans += 1ll * (i + 1) * (n - 1 - i);
		}
	};
	while (m--) {
		int i = nxt() - 1, x = nxt();
		upd(i, x);
		cout << ans + 1ll * n * (n + 1) / 2 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}