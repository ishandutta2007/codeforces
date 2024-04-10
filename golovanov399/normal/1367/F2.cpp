#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	map<int, vector<int>> M;
	for (int i = 0; i < n; ++i) {
		M[a[i]].push_back(i);
	}
	int ans = 0;
	for (auto lit = M.begin(); lit != M.end();) {
		auto rit = next(lit);
		int cur = lit->second.size();
		while (rit != M.end() && rit->second[0] > prev(rit)->second.back()) {
			cur += rit->second.size();
			++rit;
		}
		if (lit != M.begin()) {
			cur += lower_bound(all(prev(lit)->second), lit->second[0]) - prev(lit)->second.begin();
		}
		if (rit != M.end()) {
			cur += rit->second.end() - lower_bound(all(rit->second), prev(rit)->second.back());
		}
		ans = max(ans, cur);
		lit = rit;
	}
	for (int i = 0; i < n; ++i) {
		if (M.find(a[i]) == prev(M.end())) {
			continue;
		}
		auto it = M.find(a[i]);
		ans = max<int>(ans, lower_bound(all(it->second), i) - it->second.begin() + 1 + (next(it)->second.end() - lower_bound(all(next(it)->second), i)));
	}
	cout << n - ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}