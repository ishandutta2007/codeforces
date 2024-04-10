#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<pair<int, int>, bool> rec(int node, int parent, const vector<vector<int>>& adj) {
	int leaves = 0;
	int buds = 0;
	int children = 0;
	bool is_leaf = true;
	for (int to : adj[node]) {
		if (to == parent) {
			continue;
		}
		auto res = rec(to, node, adj);
		bool is_child_there = res.second;
		int child_leaves = res.first.first;
		int child_buds = res.first.second;
		leaves += child_leaves;
		buds += child_buds;
		if (is_child_there) {
			is_leaf = false;
		}
	}
	if (is_leaf) {
		++leaves;
	} else {
		++buds;
	}
	return make_pair(make_pair(leaves, buds), is_leaf);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	rep(i,0,n-1) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto res = rec(0, -1, adj);
	int ans = res.first.first - res.first.second + 1;
	if (res.second)
		--ans;
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}