#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	vector<vector<int>> by_val(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
		by_val[a[i]].push_back(i);
	}
	int cnt = count_if(all(by_val), [](const vector<int>& v) { return !v.empty(); });
	if (cnt == n - 1) {
		int i0 = 0;
		while (!by_val[i0].empty()) {
			++i0;
		}
		int pos = 0;
		while ((int)by_val[pos].size() != 2) {
			++pos;
		}
		if (by_val[pos].back() != i0) {
			by_val[pos].pop_back();
		} else {
			by_val[pos].erase(by_val[pos].begin());
		}
	}
	cout << cnt << "\n";
	vector<int> ans(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!by_val[i].empty()) {
			ans[by_val[i][0]] = i;
		}
	}
	vector<char> used(n);
	for (int x : ans) {
		if (x > -1) {
			used[x] = 1;
		}
	}
	vector<int> path_beg;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			path_beg.push_back(i);
		}
	}

	for (int i = 0; i < (int)path_beg.size(); ++i) {
		int v = path_beg[i];
		while (ans[v] > -1) {
			v = ans[v];
		}
		ans[v] = path_beg[(i + 1) % path_beg.size()];
	}
	for (int x : ans) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}