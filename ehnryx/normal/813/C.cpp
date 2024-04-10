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

const int N = 2e5 + 1;
vector<int> adj[N];
int height[N], depth[N], parent[N];

int build(int u, int p) {
	if(p) adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
	height[u] = 0;
	depth[u] = depth[p] + 1;
	parent[u] = p;
	for(int v : adj[u]) {
		height[u] = max(height[u], 1 + build(v, u));
	}
	return height[u];
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, x;
	cin >> n >> x;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(1, 0);

	int allow = (depth[x] - 2) / 2;
	int ans = 0;
	for(int i=0; i<=allow; i++, x=parent[x]) {
		ans = max(ans, height[x] + depth[x] - 1);
	}
	cout << 2 * ans << nl;

	return 0;
}