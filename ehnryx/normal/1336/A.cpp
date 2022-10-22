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

const int N = 1 << 18;
vector<int> adj[N];
int sz[N], par[N], depth[N];

int build(int u, int p) {
	depth[u] = depth[p] + 1;
	par[u] = p;
	sz[u] = 1;
	for(int v : adj[u]) {
		if(v == p) continue;
		sz[u] += build(v, u);
	}
	return sz[u];
}

int chain[N], root[N], pos[N];

int cid, cpos;
void hld_build(int u, int p, int id) {
	if(id == -1) {
		id = cid++;
		root[id] = u;
	}
	chain[u] = id;
	pos[u] = cpos++;
	int bestc = -1;
	for(int v : adj[u]) {
		if(v == p) continue;
		if(bestc == -1 || sz[v] > sz[bestc]) {
			bestc = v;
		}
	}
	if(bestc != -1) {
		hld_build(bestc, u, id);
	}
	for(int v : adj[u]) {
		if(v == p) continue;
		if(v != bestc) {
			hld_build(v, u, -1);
		}
	}
}

pair<int,int> st[2*N];
int z[2*N];

void push(int i) {
	if(z[i]) {
		st[2*i].first += z[i];
		st[2*i+1].first += z[i];
		z[2*i] += z[i];
		z[2*i+1] += z[i];
		z[i] = 0;
	}
}

void pull(int i) {
	st[i] = max(st[2*i], st[2*i+1]);
}

void insert(int l, int r, int v, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		st[i].first += v;
		z[i] += v;
		return;
	}
	push(i);
	int m = (s+e) / 2;
	insert(l, r, v, 2*i, s, m);
	insert(l, r, v, 2*i+1, m+1, e);
	pull(i);
}

pair<int,int> query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return make_pair(-INF, -1);
	if(l<=s && e<=r) {
		return st[i];
	}
	push(i);
	int m = (s+e) / 2;
	return max(query(l, r, 2*i, s, m), query(l, r, 2*i+1, m+1, e));
}

void path_update(int v) {
	while(chain[v] != chain[1]) {
		insert(pos[root[chain[v]]], pos[v], -1);
		v = par[root[chain[v]]];
	}
	insert(pos[root[chain[v]]], pos[v], -1);
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(1, 0);
	hld_build(1, 0, -1);
	assert(cpos == n);

	for(int i=1; i<=n; i++) {
		insert(pos[i], pos[i], depth[i] - 1);
		st[pos[i]+N].second = i;
	}
	for(int i=N-1; i>0; i--) {
		pull(i);
	}

	ll ans = 0;
	for(int i=0; i<k; i++) {
		auto [val, id] = query(0, n-1);
		insert(pos[id], pos[id], -INF);
		path_update(id);
		ans += val;
	}
	cout << ans << nl;

	return 0;
}