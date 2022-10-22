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

const int N = 3e5 + 1;
vector<int> adj[N];
unordered_set<int> chain[N];
int ans[N], remap[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> edges;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges.push_back(make_pair(a, b));
	}

	map<vector<int>,vector<int>> groups;
	for(int i=1; i<=n; i++) {
		adj[i].push_back(i);
		sort(adj[i].begin(), adj[i].end());
		groups[adj[i]].push_back(i);
	}

	int gid = 0;
	for(const auto& g : groups) {
		++gid;
		for(int v : g.second) {
			ans[v] = gid;
		}
	}

	if(gid == 1) {
		remap[1] = 1;
	} else {
		for(auto [a, b] : edges) {
			if(ans[a] == ans[b]) continue;
			chain[ans[a]].insert(ans[b]);
			chain[ans[b]].insert(ans[a]);
		}

		int s = -1;
		for(int i=1; i<=gid; i++) {
			if(chain[i].size() == 1) {
				s = i;
			}
		}
		if(s == -1) {
			//cerr<<"bad at deg"<<nl;
			cout << "NO" << nl;
			return 0;
		}
		for(int t=1; t<=gid; t++) {
			remap[s] = t;
			if(chain[s].size() > 2) {
				//cerr<<"bad at chain"<<nl;
				cout << "NO" << nl;
				return 0;
			}
			for(int j : chain[s]) {
				if(!remap[j]) {
					s = j;
					break;
				}
			}
		}
	}

	cout << "YES" << nl;
	for(int i=1; i<=n; i++) {
		cout << remap[ans[i]] << " ";
	}
	cout << nl;

	return 0;
}