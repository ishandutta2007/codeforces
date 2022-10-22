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

const int N = 3e5+1;
vector<int> adj[N];
int one[N], two[N];

void init(int n) {
	for(int i=1;i<=n;i++) {
		adj[i].clear();
	}
}

int solve(int u, int p) {
	int nb = adj[u].size();
	int res = 1;
	one[u] = two[u] = nb+1;
	int best1 = 0;
	int best2 = 0;
	for(int v:adj[u]) {
		if(v==p) continue;
		res = max(res, solve(v,u));
		one[u] = max(one[u], one[v] + nb-1);
		if(one[v] > best1) {
			best2 = best1;
			best1 = one[v];
		} else if(one[v] > best2) {
			best2 = one[v];
		}
	}
	two[u] = max(two[u], best1+best2-1 + nb-2);
	res = max(res, one[u]);
	res = max(res, two[u]);
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		init(n);
		for(int i=1;i<n;i++) {
			int a,b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cout << solve(1,0) << nl;
	}

	return 0;
}