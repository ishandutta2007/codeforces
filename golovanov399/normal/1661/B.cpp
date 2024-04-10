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
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		unsigned int x = nxt();
		if (!x) {
			cout << "0 ";
			continue;
		}
		unsigned int ans = 1e9;
		for (int i = 0; i <= 15; ++i) {
			ans = min(ans, 15 - i + ((-x) & ((1 << i) - 1)));
		}
		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}