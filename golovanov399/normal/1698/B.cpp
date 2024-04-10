#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	if (k == 1) {
		cout << (n - 1) / 2 << "\n";
	} else {
		int ans = 0;
		for (int i = 1; i < n - 1; ++i) {
			ans += a[i] > a[i - 1] + a[i + 1];
		}
		cout << ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}
	// for (int i = 1; i <= t; ++i) {
	// 	cout << "Case #" << i << ": ";
	// 	solve();
	// }

	return 0;
}