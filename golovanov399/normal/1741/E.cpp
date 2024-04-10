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
	vector<int> a(n);
	generate(all(a), nxt);
	vector<char> can(n + 1, false);
	can[0] = true;
	for (int i = 0; i < n; ++i) {
		if (can[i] && i + a[i] + 1 <= n) {
			can[i + a[i] + 1] = true;
		}
		if (i >= a[i] && can[i - a[i]]) {
			can[i + 1] = true;
		}
	}
	cout << (can[n] ? "Yes" : "No") << "\n";
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