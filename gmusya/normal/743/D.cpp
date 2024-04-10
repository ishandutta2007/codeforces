#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll INF = 1e18;

int n;
vector <bool> used;
vector <ll> a, tree_sum, tree_max;
vector <pair <ll, ll>> tree_ans;
vector <vector <int>> g;

void dfs_sum(int v) {
	used[v] = true;
	tree_sum[v] = a[v];
	for (int u : g[v]) 
		if (!used[u]) {
			dfs_sum(u);
			tree_sum[v] += tree_sum[u];
		}
}

void dfs_max(int v) {
	used[v] = false;
	tree_max[v] = tree_sum[v];
	for (int u : g[v]) 
		if (used[u]) {
			dfs_max(u);
			tree_max[v] = max(tree_max[v], tree_max[u]);
		}
}

void dfs_ans(int v) {
	used[v] = true;
	vector <ll> max_in_kids = { -INF, -INF };
	for (int u : g[v]) 
		if (!used[u]) 
			max_in_kids.push_back(tree_max[u]);
	sort(max_in_kids.begin(), max_in_kids.end());
	reverse(max_in_kids.begin(), max_in_kids.end());
	tree_ans[v] = { max_in_kids[0], max_in_kids[1] };
	for (int u : g[v]) 
		if (!used[u]) {
			dfs_ans(u);
			if (tree_ans[v].first + tree_ans[v].second < tree_ans[u].first + tree_ans[u].second)
				tree_ans[v] = tree_ans[u];
		}
}

int main() {
	cin >> n;
	used.resize(n), a.resize(n), tree_sum.resize(n), tree_max.resize(n), tree_ans.resize(n), g.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs_sum(0);
	dfs_max(0);
	dfs_ans(0);
	if (tree_ans[0].second == -INF) cout << "Impossible";
	else cout << tree_ans[0].first + tree_ans[0].second;
	return 0;
}