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

const int N = 2e5+1;
vector<Edge> adj[N];
int sz[N];
ll good, bad;
int n;

int solve(int u, int p) {
	sz[u] = 1;
	for(const Edge& e : adj[u]) {
		if(e.v == p) continue;
		sz[u] += solve(e.v, u);
		if(sz[e.v]%2 == 1) {
			good += e.c;
		}
		bad += (ll) e.c * min(sz[e.v], 2*n-sz[e.v]);
	}
	return sz[u];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for(int i=1; i<=2*n; i++) {
			adj[i].clear();
		}
		for(int i=1; i<2*n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({b,c});
			adj[b].push_back({a,c});
		}
		good = bad = 0;
		solve(1, 0);
		cout << good << " " << bad << nl;
	}

	return 0;
}