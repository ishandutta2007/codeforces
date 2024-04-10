#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<pair<int, int>> all_edges;
vector<vector<int>> adj;
vector<vector<int>> edge_inds;
vector<bool> vis;
vector<bool> must_include;
vector<bool> remaining;

void dfs(int cur, int parent) {
	vis[cur] = true;
	rep(i,0,2) {
		rep(j,0,sz(adj[cur])) {
			if (i == must_include[edge_inds[cur][j]]) {
				continue;
			}
			int to = adj[cur][j];
			if (to == parent)
				continue;
			if (vis[to]) {
				remaining[edge_inds[cur][j]] = true;
			} else {
				dfs(to, cur);
			}
		}
	}
}

vector<bool> get_remaining(vector<bool> _must_include) {
	must_include = _must_include;
	vis = vector<bool>(n);
	remaining = vector<bool>(m);
	dfs(0, -1);
	return remaining;
}

bool is_cycle(vector<int> edges) {
	int num_edges = sz(edges);
	set<int> nodes;
	for (int e : edges) {
		nodes.insert(all_edges[e].first);
		nodes.insert(all_edges[e].second);
	}
	return num_edges == 3 && sz(nodes) == 3;
}

vector<int> get_edges(vector<bool> edges) {
	vector<int> ret;
	rep(i,0,m) {
		if (edges[i]) {
			ret.push_back(i);
		}
	}
	return ret;
}

vector<bool> to_vec(vector<int> edges) {
	vector<bool> ret(m, false);
	for (int e : edges)
		ret[e] = true;
	return ret;
}

pair<bool, vector<bool>> rec(vector<int> must_include_edges) {
	auto r = get_remaining(to_vec(must_include_edges));
	if (!is_cycle(get_edges(r))) {
		return make_pair(true, r);
	}
	for (int e : get_edges(r)) {
		must_include_edges.push_back(e);
		if (is_cycle(must_include_edges))
			continue;
		auto res = rec(must_include_edges);
		if (res.first)
			return res;
		must_include_edges.pop_back();
	}
	return make_pair(false, vector<bool>());
}

void solve() {
	cin >> n >> m;
	adj = vector<vector<int>>(n);
	edge_inds = vector<vector<int>>(n);
	all_edges.clear();
	rep(i,0,m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		all_edges.emplace_back(a, b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		edge_inds[a].push_back(i);
		edge_inds[b].push_back(i);
	}
	auto res = rec(vector<int>());
	if (!res.first) {
		res.second = get_remaining(vector<bool>(m));
	}
	rep(i,0,m)
		cout << res.second[i];
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}