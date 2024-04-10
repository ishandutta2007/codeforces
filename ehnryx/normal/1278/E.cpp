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
vector<int> adj[N];
int lv[N], rv[N];

int solve(int u, int p, int id) {
	int ccnt = adj[u].size() - (p>0);
	rv[u] = id + ccnt + 1;
	int cpos = rv[u];
	int nxt = rv[u];
	for(int v:adj[u]) {
		if(v==p) continue;
		lv[v] = --cpos;
		nxt = solve(v, u, nxt);
	}
	return nxt;
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
	lv[1] = 1;
	solve(1, 0, 1);

	for(int i=1; i<=n; i++) {
		cout << lv[i] << " " << rv[i] << nl;
	}

	return 0;
}