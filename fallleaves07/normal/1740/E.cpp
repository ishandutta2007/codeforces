#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct Tree {
	vector<vector<int>> son;
	vector<int> f, dep, fa;
	Tree(int n) : son(n + 1), f(n + 1, 0), dep(n + 1), fa(n + 1) {
		for (int i = 2; i <= n; i++) {
			cin >> fa[i];
			son[fa[i]].emplace_back(i);
		}
	}
	void solve() {
		dfs(1);
		printf("%d\n", f[1]);
	}
	void dfs(int v) {
		for (auto u : son[v]) {
			dfs(u);
			dep[v] = max(dep[v], dep[u]);
			f[v] += f[u];
		}
		++dep[v];
		f[v] = max(f[v], dep[v]);
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	Tree t(n);
	t.solve();
    return 0;
}