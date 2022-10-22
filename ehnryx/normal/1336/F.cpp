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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1 << 18;
const int L = 18;

struct SparseBIT {
	unordered_map<int,int> bit;
	void clear() {
		bit.clear();
	}
	int query(int x) {
		int res = 0;
		for(++x; x>0; x-=x&-x) {
			auto it = bit.find(x);
			if(it != bit.end()) res += it->second;
		}
		return res;
	}
	int query(int l, int r) {
		return query(r) - query(l-1);
	}
	void insert(int x, int v) {
		for(++x; x<N; x+=x&-x) {
			bit[x] += v;
		}
	}
};

struct BIT {
	int bit[N];
	BIT() {
		clear();
	}
	void clear() {
		memset(bit, 0, sizeof bit);
	}
	int query(int x) {
		int res = 0;
		for(++x; x>0; x-=x&-x) {
			res += bit[x];
		}
		return res;
	}
	void insert(int x, int v) {
		for(++x; x<N; x+=x&-x) {
			bit[x] += v;
		}
	}
	void insert(int l, int r, int v) {
		insert(l, v);
		insert(r+1, -v);
	}
};

BIT et;

vector<int> adj[N];
int sz[N], depth[N], tour[N], anc[N][L];

int tid;
int build(int u, int p) {
	depth[u] = depth[p] + 1;
	anc[u][0] = p;
	for(int j=1; j<L; j++) {
		anc[u][j] = anc[anc[u][j-1]][j-1];
	}
	tour[u] = tid++;
	sz[u] = 1;
	for(int v : adj[u]) {
		if(v == p) continue;
		sz[u] += build(v, u);
	}
	return sz[u];
}

int jump(int a, int k) {
	assert(k >= 0);
	for(int j=0; j<L; j++) {
		if(k & 1<<j) {
			a = anc[a][j];
		}
	}
	return a;
}

int lca(int a, int b) {
	if(depth[a] < depth[b]) swap(a, b);
	a = jump(a, depth[a]-depth[b]);
	assert(depth[a] == depth[b]);
	if(a == b) return a;
	for(int j=L-1; j>=0; j--) {
		if(anc[a][j] != anc[b][j]) {
			a = anc[a][j];
			b = anc[b][j];
		}
	}
	return anc[a][0];
}

bool cmp_tour(int a, int b) {
	return tour[a] < tour[b];
}

vector<pair<int,int>> compress(vector<int>& nodes) {
	sort(nodes.begin(), nodes.end(), cmp_tour);
	int r = nodes.size();
	for(int i=1; i<r; i++) {
		nodes.push_back(lca(nodes[i], nodes[i-1]));
	}
	sort(nodes.begin(), nodes.end(), cmp_tour);
	nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
	vector<pair<int,int>> out;
	out.push_back(make_pair(nodes[0], 0));
	for(int i=1; i<nodes.size(); i++) {
		out.push_back(make_pair(nodes[i], lca(nodes[i], nodes[i-1])));
	}
	return out;
}

vector<pair<int,int>> paths[N];
vector<int> groups[N];
vector<int> ep[N];

SparseBIT st[N]; // sparse bit for compressed subtree
vector<int> upds[N]; // updates for smaller to larger

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(1, 0);

	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		int c = lca(a, b);
		//cerr<<"got path "<<a<<" "<<b<<" -> lca = "<<c<<" @ depth "<<depth[c]<<nl;
		paths[c].push_back(make_pair(a, b));
	}

	for(int i=1; i<=n; i++) {
		groups[depth[i]].push_back(i);
	}

	ll ans = 0;

	// different depths
	for(int i=n; i>=1; i--) {
		for(int c : groups[i]) {
			for(auto [a, b] : paths[c]) {
				////cerr<<nl;
				////cerr<<"@ path "<<a<<" "<<b<<" w/ lca "<<c<<" at depth "<<depth[c]<<nl;
				ans += et.query(tour[a]) + et.query(tour[b]);
				////cerr<<"query "<<a<<" -> "<<et.query(tour[a])<<nl;
				////cerr<<"query "<<b<<" -> "<<et.query(tour[b])<<nl;
			}
			for(auto [a, b] : paths[c]) {
				if(depth[a] >= depth[c]+k) {
					a = jump(a, depth[a]-depth[c]-k);
					////cerr<<"INSERT ep "<<a<<nl;
					et.insert(tour[a], tour[a]+sz[a]-1, 1);
				}
				if(depth[b] >= depth[c]+k) {
					b = jump(b, depth[b]-depth[c]-k);
					////cerr<<"INSERT ep "<<b<<nl;
					et.insert(tour[b], tour[b]+sz[b]-1, 1);
				}
				////cerr<<nl;
			}
		}
	}

	//cerr<<nl;
	//cerr<<"different depths: "<<ans<<nl;
	//cerr<<endl;

	// same depths (same lca)
	et.clear();
	for(int c=1; c<=n; c++) {
		if(paths[c].size() <= 1) continue;
		//cerr<<"DO lca = "<<c<<nl;
		vector<int> nodes;
		for(auto& [a, b] : paths[c]) {
			if(tour[a] > tour[b]) swap(a, b);
			nodes.push_back(a);
			nodes.push_back(b);
			//cerr<<"path: "<<a<<" "<<b<<nl;
		}
		vector<pair<int,int>> edges = compress(nodes);

		// build compressed tree
		for(auto [v, _] : edges) {
			adj[v].clear();
			ep[v].clear();
		}
		for(auto [v, p] : edges) {
			if(p) {
				adj[p].push_back(v);
				//cerr<<"compressed edge "<<p<<" "<<v<<nl;
			}
		}
		for(auto [a, b] : paths[c]) {
			ep[a].push_back(b);
		}
		//cerr<<nl;

		// query when x1 and y2 are in the same subtree
		// ie. the paths are in different directions
		// intersection must be a vertical path
		vector<int> memo; // for clearing later
		function<ll(int)> query_dfs = [&](int u) {
			ll res = (ll)et.query(tour[u]) * ep[u].size();
			for(int v : adj[u]) {
				res += query_dfs(v);
			}
			return res;
		};
		function<void(int)> update_dfs = [&](int u) {
			//cerr<<"dfs "<<u<<nl;
			for(int b : ep[u]) {
				if(depth[b] < depth[c] + k) continue;
				b = jump(b, depth[b] - depth[c] - k);
				//cerr<<"et.insert "<<b<<" from path "<<u<<" -> "<<b<<nl;
				et.insert(tour[b], tour[b]+sz[b]-1, 1);
				memo.push_back(b);
			}
			for(int v : adj[u]) {
				update_dfs(v);
			}
		};

		// insert paths starting at the lca
		for(int b : ep[c]) {
			if(depth[b] < depth[c] + k) continue;
			b = jump(b, depth[b] - depth[c] - k);
			//cerr<<"init insert "<<b<<" from path "<<c<<" -> "<<b<<nl;
			et.insert(tour[b], tour[b]+sz[b]-1, 1);
			memo.push_back(b);
		}
		// query and insert subtrees
		for(int v : adj[c]) {
			//cerr<<"query dfs "<<c<<" -> "<<v<<nl;
			ans += query_dfs(v);
			//cerr<<"update dfs "<<c<<" -> "<<v<<nl;
			update_dfs(v);
		}
		// clear updates
		for(int b : memo) {
			et.insert(tour[b], tour[b]+sz[b]-1, -1);
		}

		//cerr<<nl;
		//cerr<<"DONE querying same subtree -> "<<ans<<nl;
		//cerr<<endl;

		// query when x1 and y2 are in different subtrees
		// ie. the paths are in the same direction
		for(auto [v, _] : edges) {
			st[v].clear();
			upds[v].clear();
		}

		function<int(int,int)> walk = [&](int a, int b) {
			if(depth[a] + depth[b] - 2*depth[c] < k) return 0;
			if(depth[a] - depth[c] >= k) {
				return c;
			} else {
				return jump(b, depth[a] + depth[b] - 2*depth[c] - k);
			}
		};

		function<ll(int)> solve = [&](int u) {
			//cerr<<"SOLVE "<<u<<endl;
			ll res = 0;
			for(int b : ep[u]) {
				int y = walk(u, b);
				//cerr<<"start path "<<u<<" -> "<<b<<" walk = "<<y<<nl;
				if(y) {
					res += st[u].query(tour[y], tour[y]+sz[y]-1);
					//cerr<<"query subtree "<<y<<" -> "<<st[u].query(tour[y], tour[y]+sz[y]-1)<<nl;
				}
				//cerr<<"insert node "<<b<<nl;
				st[u].insert(tour[b], 1);
				upds[u].push_back(b);
			}
			for(int v : adj[u]) {
				res += solve(v);
				// merge subtree v with subtree u
				if(upds[u].size() < upds[v].size()) {
					swap(st[u], st[v]);
					swap(upds[u], upds[v]);
				}
				for(int b : upds[v]) {
					int y = walk(u, b);
					//cerr<<"add path "<<u<<" -> "<<b<<" walk = "<<y<<nl;
					if(y) {
						res += st[u].query(tour[y], tour[y]+sz[y]-1);
						//cerr<<"add query subtree "<<y<<" -> "<<st[u].query(tour[y], tour[y]+sz[y]-1)<<nl;
					}
				}
				for(int b : upds[v]) {
					//cerr<<"add insert node "<<b<<nl;
					st[u].insert(tour[b], 1);
					upds[u].push_back(b);
				}
			}
			return res;
		};
		ans += solve(c);
	}

	cout << ans << nl;

	return 0;
}