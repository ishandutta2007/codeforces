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

const int N = 5e5+1;
const int L = 19;
ll fact[N];
vector<int> adj[N];
unordered_map<int,int> nxt[N];
unordered_set<int> done[N];
int par[N][L];
int depth[N];
int val[N];

struct DSU {
	unordered_map<int,int> dsu;
	int find(int i) {
		if(!dsu[i]) return i;
		return dsu[i] = find(dsu[i]);
	}
	int link(int i, int j) {
		if(find(i) == find(j)) return false;
		dsu[find(i)] = find(j);
		return true;
	}
};
DSU dsu[N];

void build(int u, int p) {
	depth[u] = depth[p]+1;
	par[u][0] = p;
	for (int j=1;j<L;j++) {
		par[u][j] = par[par[u][j-1]][j-1];
	}
	for (int v:adj[u]) {
		if(v==p) continue;
		build(v, u);
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a,b);
	for (int i=L-1;i>=0;i--) {
		if(depth[a] - (1<<i) >= depth[b]) {
			a = par[a][i];
		}
	}
	if(a == b) return a;
	for (int i=L-1;i>=0;i--) {
		if(par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	assert(a != b);
	assert(par[a][0] == par[b][0]);
	assert(par[a][0]);
	return par[a][0];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	fact[0] = 1;
	for (int i=1;i<N;i++) {
		fact[i] = i * fact[i-1] % MOD;
	}

	int n;
	cin >> n;
	for (int i=1;i<n;i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(1, 0);

	const int FIRST = -1;
	const int LAST = -2;

	int tot = 0;
	for (int i=1;i<=n;i++) {
		cin >> val[i];
		if(val[i] == 0) continue;

		int c = lca(i, val[i]);
		tot += depth[i] + depth[val[i]] - 2*depth[c];
		if (tot > 2*n-2) {
			//cerr<<"too much"<<nl;
			cout << 0 << nl;
			return 0;
		}
		//cerr<<"update "<<i<<" -> "<<val[i]<<" through "<<c<<nl;

		vector<int> path, down;
		// up
		for (int u=val[i]; u!=c; u=par[u][0]) {
			path.push_back(u);
		}
		path.push_back(c);
		// down
		for (int u=i; u!=c; u=par[u][0]) {
			down.push_back(u);
		}
		path.insert(path.end(), down.rbegin(), down.rend());
		assert(path.size() == depth[i] + depth[val[i]] - 2*depth[c] + 1);

		for (int j=0; j<path.size(); j++) {
			int u = path[j];
			int s = (j==0 ? FIRST : path[j-1]);
			int t = (j+1==path.size() ? LAST : path[j+1]);
			//cerr<<u<<" : "<<s<<" -> "<<t<<nl;
			if(nxt[u].count(s) || done[u].count(t) || !dsu[u].link(s,t)) {
				//cerr<<"bad"<<nl;
				cout << 0 << nl;
				return 0;
			}
			nxt[u][s] = t;
			done[u].insert(t);
		}
	}

	ll ans = 1;
	for (int i=1;i<=n;i++) {
		int u = FIRST;
		int seen = 0;
		while (nxt[i].count(u)) {
			seen += (u != FIRST);
			assert(u != LAST);
			u = nxt[i][u];
		}
		if (u == LAST && seen < (int)adj[i].size()) {
			//cerr<<"too few"<<nl;
			cout << 0 << nl;
			return 0;
		}
		int cnt = (int)adj[i].size() - (int)nxt[i].size();
		ans = ans * fact[max(0,cnt)] % MOD;
	}
	cout << ans << nl;

	return 0;
}