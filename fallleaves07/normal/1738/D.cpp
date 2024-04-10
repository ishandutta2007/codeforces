#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct Tree {
	int n;
	vector<vector<int>> sons;
	Tree(int _n) : n(_n), sons(n + 2) {
		for (int i = 1; i <= n; i++) {
			int v;
			cin >> v;
			sons[v].push_back(i);
		}
	}
	vector<int> ans;
	int k;
	void dfs(int v, int tag) {
		int lst = -1;
		for (auto u : sons[v]) {
			if (!sons[u].empty()) {
				lst = u;
			} else {
				ans.push_back(u);
			}
			if (tag) {
				k = max(k, u);
			}
		}
		if (lst != -1) {
			ans.push_back(lst);
			dfs(lst, tag ^ 1);
		}
	}
	void solve() {
		k = 0;
		if (sons[0].empty()) {
			dfs(n + 1, 1);
		} else {
			dfs(0, 0);
		}
		printf("%d\n", k);
		for (auto v : ans) {
			printf("%d ", v);
		}
		puts("");
	}
};

void solve() {
	int n;
	cin >> n;
	Tree t(n);
	t.solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}