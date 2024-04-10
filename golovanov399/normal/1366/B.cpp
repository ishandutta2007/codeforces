#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), x = nxt(), m = nxt();
	int l = x - 1, r = x;
	for (int i = 0; i < m; ++i) {
		int cl = nxt() - 1, cr = nxt();
		if (cr <= l || r <= cl) {
			continue;
		}
		l = min(l, cl);
		r = max(r, cr);
	}
	cout << r - l << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}