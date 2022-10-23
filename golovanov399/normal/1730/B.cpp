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
	int max_sum = -1e9, min_dif = 1e9;
	vector<pair<int, int>> a(n);
	for (auto& p : a) {
		p.first = nxt();
	}
	for (auto& p : a) {
		p.second = nxt();
	}
	for (auto [x, y] : a) {
		max_sum = max(max_sum, x + y);
		min_dif = min(min_dif, x - y);
	}
	int double_x = max_sum + min_dif;
	cout << double_x / 2 << "." << double_x % 2 * 5 << "\n";
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