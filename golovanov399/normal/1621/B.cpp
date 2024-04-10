#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	int mn = 2e9;
	int mx = -2e9;
	long long cost_l = 3e9;
	long long cost_r = 3e9;
	long long cost_both = 3e9;
	for (int i = 0; i < n; ++i) {
		int l = nxt(), r = nxt(), c = nxt();
		if (l < mn) {
			cost_l = cost_both = 3e9;
			mn = l;
		}
		if (r > mx) {
			cost_r = cost_both = 3e9;
			mx = r;
		}
		if (l == mn) {
			cost_l = min<long long>(cost_l, c);
		}
		if (r == mx) {
			cost_r = min<long long>(cost_r, c);
		}
		if (l == mn && r == mx) {
			cost_both = min<long long>(cost_both, c);
		}
		cout << min(cost_l + cost_r, cost_both) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}