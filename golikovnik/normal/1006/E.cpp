#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<vector<int>> graph;
vector<int> tin, vt, sz;
int timer;

void dfs(int v, int p = -1) {
	tin[v] = timer;
	vt[timer++] = v;
	int size = 1;
	for (int u: graph[v]) {
		if (u != p) {
			dfs(u, v);
			size += sz[u];
		}
	}
	sz[v] = size;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	graph.resize(n);
	tin.resize(n);
	vt.resize(n);
	sz.resize(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		graph[p - 1].push_back(i);
	}
	dfs(0);
	for (int i = 0; i < q; ++i) {
		int u, k;
		cin >> u >> k;
		--u;
		if (sz[u] < k) {
			cout << -1;
		} else {
			cout << vt[tin[u] + k - 1] + 1;
		}
		cout << "\n";
	}
	return 0;	
}