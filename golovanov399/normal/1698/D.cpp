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
	int n = nxt();
	int l = 0, r = n;
	while (r > l + 1) {
		int m = (l + r) / 2;
		cout << "? " << l + 1 << " " << m << endl;
		int there = 0;
		for (int i = l; i < m; ++i) {
			int x = nxt();
			there += clamp(x, l + 1, m) != x;
		}
		((m - l - there) % 2 ? r : l) = m;
	}
	cout << "! " << r << endl;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

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