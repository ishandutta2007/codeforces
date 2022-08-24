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
	int x = 0;
	for (int i = 0; i < n; ++i) {
		x = nxt();
	}
	cout << x << "\n";
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