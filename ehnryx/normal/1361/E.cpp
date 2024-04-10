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

struct Min2 {
	pair<int,int> a, b;
	Min2(): a(INF, -1), b(INF, -1) {}
	int first() const { return a.first; }
	int second() const { return b.first; }
	int parent() const { return a.second; }
	void push(pair<int,int> cur) {
		if(cur < a) {
			b = a;
			a = cur;
		} else if(cur < b) {
			b = cur;
		}
	}
	void push(const Min2& o) {
		push(o.a);
		push(o.b);
	}
};

const int N = 1e5 + 1;
const int M = 200;
vector<int> adj[N];
bool vis[N], up[N];
int depth[N];
Min2 low[N];

bool build(int u, vector<int>& o) {
	o.push_back(u);
	vis[u] = up[u] = true;
	for(int v : adj[u]) {
		if(vis[v]) {
			if(!up[v]) return false;
			low[u].push(make_pair(depth[v], v));
		} else {
			depth[v] = depth[u] + 1;
			if(!build(v, o)) return false;
			low[u].push(low[v]);
		}
	}
	up[u] = false;
	return true;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		for(int i=1; i<=n; i++) {
			adj[i].clear();
		}

		for(int i=0; i<m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}

		set<int> ans;
		for(int it=0; it<M; it++) {
			for(int i=1; i<=n; i++) {
				low[i] = Min2();
				vis[i] = up[i] = false;
				depth[i] = 0;
			}

			int s = rng()%n + 1;
			//cerr<<"s = "<<s<<nl;
			vector<int> order;
			if(!build(s, order)) continue;

			for(int u : order) {
				//cerr<<"@ "<<u<<" w/ "<<low[u].first()<<" "<<low[u].second()<<nl;
				if(u == s) {
					ans.insert(u);
					//cerr<<"is root"<<nl;
				} else if(low[u].first() < depth[u] && low[u].second() >= depth[u]) {
					//cerr<<"is valid, check par: "<<low[u].parent()<<nl;
					if(ans.count(low[u].parent())) {
						ans.insert(u);
					}
				}
			}
			break;
		}

		if(5*ans.size() < n) {
			cout << -1 << nl;
		} else {
			for(int it : ans) {
				cout << it << " ";
			}
			cout << nl;
		}
	}

	return 0;
}