#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct Tree {
	int n;
	vector<vector<int>> sons;
	vector<int> dep;
	Tree(int _n) : n(_n), sons(n + 1), dep(n + 1) {
		for (int i = 2; i <= n; i++) {
			int fa;
			cin >> fa;
			sons[fa].emplace_back(i);
		}
	}
	int dfs(int v, int lim) {
		int cnt = 0;
		for (auto u : sons[v]) {
			cnt += dfs(u, lim);
			if (dep[u] + 1 >= lim && v != 1) {
				++cnt;
			} else {
				dep[v] = max(dep[v], dep[u] + 1);
			}
		}
		return cnt;
	}
	int calc(int lim) {
		fill(dep.begin(), dep.end(), 0);
		return dfs(1, lim);
	}
	void solve(int k) {
		int l = 1, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (calc(mid) <= k) {
				ans = mid, r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		printf("%d\n", ans);
	}
};

void solve() {
	int n, k;
	cin >> n >> k;
	Tree t(n);
	t.solve(k);
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