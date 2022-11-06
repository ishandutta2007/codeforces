#include<bits/stdc++.h>
using LL = long long;

struct Tree {
	std::vector<std::vector<int>> e;
	std::vector<int> a, b, ans;
	Tree(int n) : e(n + 1), a(n + 1), b(n + 1), ans(n + 1) {
		for (int i = 2; i <= n; i++) {
			int p;
			std::cin >> p >> a[i] >> b[i];
			e[p].push_back(i);
		}
	}
	std::vector<LL> stk;
	void solve(int v = 1, LL A = 0) {
		if (v == 1) {
			stk.push_back(0);
		}
		ans[v] = std::upper_bound(stk.begin(), stk.end(), A) - stk.begin() - 1;
		for (auto u : e[v]) {
			stk.emplace_back(stk.back() + b[u]);
			solve(u, A + a[u]);
			stk.pop_back();
		}
	}
};

void solve() {
	int n;
	std::cin >> n;
	Tree t(n);
	t.solve();
	for (int i = 2; i <= n; i++) {
		printf("%d%c", t.ans[i], " \n"[i == n]);
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}