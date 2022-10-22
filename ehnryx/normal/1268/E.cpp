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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Edge {
	int v, c;
};

const int N = 5e5+1;
const int L = 19;
vector<Edge> adj[N];
int depth[N];
int dpe[N], dpv[N];
int anc[N][L], maxe[N][L], inc[N][L];

void build(int u, int p, int c) {
	depth[u] = depth[p] + 1;
	anc[u][0] = p;
	maxe[u][0] = c;
	inc[u][0] = true;
	for(int j=1; j<L; j++) {
		int mp = anc[u][j-1];
		anc[u][j] = anc[mp][j-1];
		maxe[u][j] = max(maxe[u][j-1], maxe[mp][j-1]);
		inc[u][j] = (inc[u][j-1] && inc[mp][j-1] && maxe[u][j-1] < maxe[mp][0]);
	}
	for(auto [v, ec] : adj[u]) {
		if(v == p) continue;
		build(v, u, ec);
	}
}

int lca(int a, int b) {
	if(depth[a] < depth[b]) swap(a,b);
	for(int i=L-1; i>=0; i--) {
		if(depth[anc[a][i]] >= depth[b]) {
			a = anc[a][i];
		}
	}
	if(a == b) return a;
	for(int i=L-1; i>=0; i--) {
		if(anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

vector<pair<int,int>> get_path(int a, int b) {
	vector<pair<int,int>> out;
	for(int u=a; u!=b; u=anc[u][0]) {
		int id = maxe[u][0];
		out.push_back(make_pair(id, dpe[id]));
	}
	return out;
}

int cycle(int a, int b) {
	int c = lca(a, b);
	auto path = get_path(a, c);
	auto other = get_path(b, c);
	reverse(other.begin(), other.end());
	path.insert(path.end(), other.begin(), other.end());
	int pre = -1;
	bool up = true;
	int maxv = -1;
	int ret = 0;
	for(auto [id, val] : path) {
		if(id > pre) {
			if(!up) return 0;
		} else {
			up = false;
		}
		pre = id;
		if(id > maxv) {
			maxv = id;
			ret = val;
		}
	}
	return ret;
}

int dsu[N];
int find(int i) {
	if(dsu[i] == -1) return i;
	return dsu[i] = find(dsu[i]);
}
bool link(int i, int j) {
	if(find(i) == find(j)) {
		return false;
	}
	dsu[find(i)] = find(j);
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	vector<tuple<int,int,int>> edges;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		edges.push_back(make_tuple(a, b, i));
	}
	reverse(edges.begin(), edges.end());

	memset(dsu, -1, sizeof dsu);
	vector<bool> in_tree(m);
	for(auto& [a, b, i] : edges) {
		if(link(a, b)) {
			adj[a].push_back({b, i});
			adj[b].push_back({a, i});
			in_tree[i] = true;
		}
	}
	build(1, 0, -1);

	fill(dpv+1, dpv+1+n, 1);
	for(auto [a, b, i] : edges) {
		if(in_tree[i]) {
			dpe[i] = dpv[a] + dpv[b];
			dpv[a] = dpv[b] = dpe[i];
		} else {
			dpe[i] = dpv[a] + dpv[b] - cycle(a, b);
			dpv[a] = dpv[b] = dpe[i];
		}
	}

	for(int i=1; i<=n; i++) {
		cout << dpv[i] - 1 << " ";
	}
	cout << nl;

	return 0;
}