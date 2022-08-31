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
	int n = nxt(), m = nxt(), x = nxt(), y = nxt(), d = nxt();
	if (x - d <= 1 && x + d >= n) {
		cout << "-1\n";
	} else if (y - d <= 1 && y + d >= m) {
		cout << "-1\n";
	} else if (x - d <= 1 && y - d <= 1) {
		cout << "-1\n";
	} else if (x + d >= n && y + d >= m) {
		cout << "-1\n";
	} else {
		cout << n + m - 2 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}