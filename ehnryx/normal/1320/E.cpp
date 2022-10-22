//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Node {
	int v, t, dist, rest;
	bool operator < (const Node& o) const {
		if(dist != o.dist) return dist > o.dist;
		return t > o.t;
	}
};

const int N = 2e5 + 1;
const int L = 18;
vector<int> adj[N];
int anc[N][L], depth[N];
int order[N];
int idx[N];

int sid = 0;
void build(int u, int p) {
	depth[u] = depth[p] + 1;
	order[u] = sid++;
	anc[u][0] = p;
	for(int j=1; j<L; j++) {
		anc[u][j] = anc[anc[u][j-1]][j-1];
	}
	for(int v : adj[u]) {
		if(v == p) continue;
		build(v, u);
	}
}

int lca(int a, int b) {
	if(depth[a] < depth[b]) swap(a, b);
	for(int j=L-1; j>=0; j--) {
		if(depth[anc[a][j]] >= depth[b]) {
			a = anc[a][j];
		}
	}
	if(a == b) return a;
	for(int j=L-1; j>=0; j--) {
		if(anc[a][j] != anc[b][j]) {
			a = anc[a][j];
			b = anc[b][j];
		}
	}
	return anc[a][0];
}

int distance(int a, int b) {
	int c = lca(a, b);
	return depth[a] + depth[b] - 2*depth[c];
}

bool euler_tour(int a, int b) {
	return order[a] < order[b];
}

vector<pair<int,int>> compress(vector<int> v) {
	sort(v.begin(), v.end(), euler_tour);
	int n = v.size();
	for(int i=1; i<n; i++) {
		v.push_back(lca(v[i], v[i-1]));
	}
	sort(v.begin(), v.end(), euler_tour);
	v.resize(unique(v.begin(), v.end()) - v.begin());
	n = v.size();

	vector<pair<int,int>> out;
	out.push_back(make_pair(v[0], v[0]));
	for(int i=1; i<n; i++) {
		out.push_back(make_pair(v[i], lca(v[i], v[i-1])));
	}
	return out;
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(1, 0);

	int q;
	cin >> q;
	while(q--) {
		int k, m;
		cin >> k >> m;
		vector<int> virus(k), speed(k), query(m);
		vector<int> nodes;
		for(int i=0; i<k; i++) {
			cin >> virus[i] >> speed[i];
			nodes.push_back(virus[i]);
		}
		for(int i=0; i<m; i++) {
			cin >> query[i];
			nodes.push_back(query[i]);
		}
		vector<pair<int,int>> edges = compress(nodes);
		for(auto [a, b] : edges) {
			idx[a] = idx[b] = -1;
		}

		int nn = edges.size() + 1;
		vector<vector<pair<int,int>>> graph(nn);
		int uid = 0;
		for(auto [a, b] : edges) {
			if(idx[a] == -1) idx[a] = uid++;
			if(idx[b] == -1) idx[b] = uid++;
			if(a == b) continue;
			int d = distance(a, b);
			graph[idx[a]].push_back(make_pair(idx[b], d));
			graph[idx[b]].push_back(make_pair(idx[a], d));
		}

		priority_queue<Node> dijk;
		for(int i=0; i<virus.size(); i++) {
			dijk.push({idx[virus[i]], i, 0, 0});
		}
		vector<int> dist(nn, -1);
		vector<int> ans(nn, -1);
		while(!dijk.empty()) {
			auto [v, t, d, r] = dijk.top();
			dijk.pop();
			if(dist[v] != -1) continue;
			dist[v] = d;
			ans[v] = t;
			for(auto [w, len] : graph[v]) {
				if(dist[w] != -1) continue;
				if(len <= r) {
					dijk.push({w, t, d, r-len});
				} else {
					int nd = d + 1 + (len-r-1)/speed[t];
					int nr = (speed[t] - (len-r) % speed[t]) % speed[t];
					dijk.push({w, t, nd, nr});
				}
			}
		}

		for(int v : query) {
			cout << ans[idx[v]] + 1 << " ";
		}
		cout << nl;
	}

	return 0;
}