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
vector<int> adj[N];
int depth[N];

void build(int u, int p) {
	depth[u] = depth[p] + 1;
	for(int v : adj[u]) {
		if(v == p) continue;
		build(v, u);
	}
}

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

	for(int i=1; i<=n; i++) {
		if(adj[i].size() > 1) {
			build(i, 0);
			break;
		}
	}

	int leaves = 0;
	set<int> next_to_leaf;
	int mask = 0;
	for(int i=1; i<=n; i++) {
		if(adj[i].size() == 1) {
			leaves++;
			next_to_leaf.insert(adj[i][0]);
			mask |= 1 << (depth[i] & 1);
		}
	}
	int internal = n-1 - leaves;

	if(__builtin_popcount(mask) == 1) {
		cout << 1 << " " << next_to_leaf.size() + internal << nl;
	} else {
		cout << 3 << " " << next_to_leaf.size() + internal << nl;
	}

	return 0;
}