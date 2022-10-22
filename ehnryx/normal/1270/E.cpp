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

ll dist(ll a, ll b) {
	return a*a + b*b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	map<ll,vector<pii>> vals;
	vector<int> adj[n];
	int x[n], y[n];
	ll g = 0;
	for(int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		for(int j=0; j<i; j++) {
			ll d = dist(x[i]-x[j], y[i]-y[j]);
			vals[d].push_back(pii(i,j));
			g = __gcd(g, d);
		}
	}

	for(const auto& [d, v] : vals) {
		for(const auto& [a, b] : v) {
			if(d/g % 2 == 0) {
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
	}

	stack<int> dfs;
	vector<bool> vis(n);
	dfs.push(0);
	vis[0] = true;
	int cnt = 0;
	while(!dfs.empty()) {
		cnt++;
		int u = dfs.top();
		dfs.pop();
		for(int v:adj[u]) {
			if(!vis[v]) {
				vis[v] = true;
				dfs.push(v);
			}
		}
	}

	cout << cnt << nl;
	for(int i=0; i<n; i++) {
		if(vis[i]) cout << i+1 << " ";
	}
	cout << nl;

	return 0;
}