//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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

const int N = 2e5 + 1;
const int L = 18;
vector<int> adj[N];
int depth[N];
int jump[N][L];

void build(int u, int par) {
	depth[u] = depth[par] + 1;
	jump[u][0] = par;
	for(int j=1; j<L; j++) {
		jump[u][j] = jump[jump[u][j-1]][j-1];
	}
	for(int v : adj[u]) {
		if(v == par) continue;
		build(v, u);
	}
}

int ancestor(int u, int k) {
	for(int j=0; j<L; j++) {
		if(k & 1<<j) {
			u = jump[u][j];
		}
	}
	return u;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(1, 0);

	for(int i=0; i<m; i++) {
		int k;
		cin >> k;
		vector<pair<int,int>> path;
		for(int j=0; j<k; j++) {
			int v;
			cin >> v;
			v = jump[v][0];
			path.push_back(make_pair(depth[v], v));
		}
		sort(path.begin(), path.end());

		bool ok = true;
		for(int j=1; j<k; j++) {
			int up = path[j-1].second;
			int down = path[j].second;
			int diff = path[j].first - path[j-1].first;
			ok &= (ancestor(down, diff) == up);
		}

		if(ok) {
			cout << "YES" << nl;
		} else {
			cout << "NO" << nl;
		}
	}

	return 0;
}