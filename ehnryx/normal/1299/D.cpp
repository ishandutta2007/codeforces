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

const int N = 1e5 + 1;
const int M = 5;
const int K = 374;

vector<pair<int,int>> adj[N];
int dsu[N];
vector<int> cbasis[N];
int cycle[N], sz[N];

bool vis[N];
int par[N], value[N];

int sum[K][K];
int dp[N][K];

int find(int i) {
	if(dsu[i] == -1) return i;
	return dsu[i] = find(dsu[i]);
}
void link(int i, int j) {
	if(find(i) != find(j)) {
		dsu[find(i)] = find(j);
	}
}

void build(int u, int p) {
	par[u] = p;
	vis[u] = true;
	for(auto [v, c] : adj[u]) {
		if(v == p || vis[v]) continue;
		value[v] = value[u] ^ c;
		build(v, u);
	}
}

vector<int> get_basis(const vector<int>& a) {
	vector<int> basis(M);
	for(int v : a) {
		for(int j=0; j<M; j++) {
			if(!(v & 1<<j)) continue;
			if(!basis[j]) {
				basis[j] = v;
				break;
			} else {
				v ^= basis[j];
			}
		}
	}
	vector<int> out;
	for(int v : basis) {
		if(v) {
			out.push_back(v);
		}
	}
	return out;
}

vector<int> add(vector<int> a, const vector<int>& b) {
	a.insert(a.end(), b.begin(), b.end());
	return get_basis(a);
}

bool equal(const vector<int>& a, const vector<int>& b) {
	return a.size() == b.size() && add(a, b).size() == a.size();
}

int get_index(const vector<int>& a, const vector<vector<int>>& bs) {
	int ret = -1;
	for(int i=0; i<bs.size(); i++) {
		if(equal(a, bs[i])) {
			assert(ret == -1);
			ret = i;
		}
	}
	assert(ret != -1);
	return ret;
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	vector<vector<int>> subspace;
	subspace.push_back({});
	for(int v=0; v<1<<M; v++) {
		int k = subspace.size();
		for(int i=0; i<k; i++) {
			vector<int> ns = add(subspace[i], {v});
			if(ns.size() == subspace[i].size()) continue;
			bool ok = true;
			for(const vector<int>& t : subspace) {
				if(equal(ns, t)) {
					ok = false;
					break;
				}
			}
			if(ok) {
				subspace.push_back(move(ns));
			}
		}
	}

	memset(sum, -1, sizeof sum);
	assert(subspace.size() == K);
	for(int i=0; i<K; i++) {
		for(int j=0; j<=i; j++) {
			vector<int> cur = add(subspace[i], subspace[j]);
			if(cur.size() == subspace[i].size() + subspace[j].size()) {
				sum[i][j] = sum[j][i] = get_index(cur, subspace);
			}
		}
	}

	int n, m;
	cin >> n >> m;
	memset(dsu, -1, sizeof dsu);
	vector<tuple<int,int,int>> edges;
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
		edges.emplace_back(a, b, c);
		if(a != 1 && b != 1) {
			link(a, b);
		}
	}

	vis[1] = true;
	for(auto [v, c] : adj[1]) {
		value[v] = c;
		vis[v] = true;
	}
	for(auto [v, _] : adj[1]) {
		build(v, 1);
	}

	memset(cycle, -1, sizeof cycle);
	for(auto [a, b, c] : edges) {
		if(find(a) != find(b)) continue;
		if(par[a] == b || par[b] == a) continue;
		int val = value[a] ^ value[b] ^ c;
		if(par[a] == 1 && par[b] == 1) {
			cycle[find(a)] = val;
		} else {
			cbasis[find(a)] = add(cbasis[find(a)], {val});
			sz[find(a)]++;
		}
	}

	dp[1][0] = 1;
	int last = 1;
	for(int i=2; i<=n; i++) {
		if(i != find(i)) continue;
		int cur = get_index(cbasis[i], subspace);
		int both = -1;
		if(cycle[i] != -1) {
			vector<int> cyc = add(cbasis[i], {cycle[i]});
			if(cyc.size() != cbasis[i].size()) {
				both = get_index(cyc, subspace);
			}
		}

		for(int j=0; j<K; j++) {
			if(!dp[last][j]) continue;
			// don't add component
			dp[i][j] = (dp[i][j] + dp[last][j]) % MOD;
			// check zero cycles
			if(cbasis[i].size() != sz[i]) continue;
			// add component
			int nj = sum[cur][j];
			if(nj != -1) {
				dp[i][nj] = (dp[i][nj] + dp[last][j]) % MOD;
			}
			// has 2 edges, and component again
			if(cycle[i] != -1 && nj != -1) {
				dp[i][nj] = (dp[i][nj] + dp[last][j]) % MOD;
			}
			// has 2 edges, add both
			if(both != -1) {
				nj = sum[both][j];
				if(nj != -1) {
					dp[i][nj] = (dp[i][nj] + dp[last][j]) % MOD;
				}
			}
		}

		last = i;
	}

	int ans = 0;
	for(int j=0; j<K; j++) {
		ans = (ans + dp[last][j]) % MOD;
	}
	cout << ans << nl;

	return 0;
}