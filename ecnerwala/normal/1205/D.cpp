#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int V = int(1e6) - 1;

const int MAXN = 6000;
int N;
vector<int> adj[MAXN];

int sz[MAXN];
void dfs_sz(int cur, int prv = -1) {
	sz[cur] = 1;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs_sz(nxt, cur);
		sz[cur] += sz[nxt];
	}
}

int find_centroid(int cur, int prv = -1) {
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		int v = find_centroid(nxt, cur);
		if (v != -1) return v;
	}
	if (sz[cur] * 2 >= N) return cur;
	return -1;
}

ll vals[MAXN];
void set_value(int cur, int prv, ll incr, ll& val) {
	vals[cur] = min(val, ll(V));
	val += incr;
	val = min(val, ll(V));

	assert(vals[cur] >= vals[prv]);
	assert(vals[cur] - vals[prv] <= V);

	cout << cur+1 << ' ' << prv+1 << ' ' << max(vals[cur] - vals[prv], 1ll) << '\n';

	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		set_value(nxt, cur, incr, val);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs_sz(0);
	int C = find_centroid(0);

	dfs_sz(C);
	//sort(adj[C].begin(), adj[C].end(), [&](int a, int b) { return sz[a] > sz[b]; });
	nth_element(adj[C].begin(), adj[C].begin(), adj[C].end(), [&](int a, int b) { return sz[a] > sz[b]; });

	vals[C] = 0;

	ll val = 1;
	ll incr = 1;
	for (int nxt : adj[C]) {
		set_value(nxt, C, incr, val);
		if (incr == 1 && (val - 1) * 3 >= N - 1) {
			cerr << val << '\n';
			incr = val;
		}
	}
	cerr << incr << ' ' << val << '\n';
	//assert(val > (2 * N * N / 9));

	return 0;
}