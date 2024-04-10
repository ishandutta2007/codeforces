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
	vector<int> b(n);
	generate(all(b), nxt);
	vector<vector<pair<int, int>>> by_l(n);
	for (int i = 0; i < n; ++i) {
		if (b[i] == 0) {
			by_l[i + 1].push_back({n, i});
		} else {
			by_l[(i + 1) / (b[i] + 1)].push_back({(i + 1) / b[i], i});
		}
	}
	vector<int> p(n, -1);
	set<pair<int, int>> S;
	for (int i = 0; i < n; ++i) {
		for (auto pp : by_l[i]) {
			S.insert(pp);
		}
		assert(!S.empty());
		p[S.begin()->second] = i + 1;
		S.erase(S.begin());
	}
	for (auto x : p) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}