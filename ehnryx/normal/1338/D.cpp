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

struct Two {
	int first, second;
	Two(int v): first(v), second(v) {}
	void update(int v) {
		if(v > first) {
			second = first;
			first = v;
		} else if(v > second) {
			second = v;
		}
	}
};

const int N = 1e5 + 1;
vector<int> adj[N];

int skip(int, int);
int take(int, int);

int solve(int u, int p) {
	Two bestskip(0), both(0);
	int res = adj[u].size();
	for(int v : adj[u]) {
		if(v == p) continue;
		res = max(res, solve(v, u));
		bestskip.update(skip(v, u));
		both.update(max(take(v, u), skip(v, u)));
	}
	res = max(res, 1 + bestskip.first + bestskip.second);
	res = max(res, (int)adj[u].size() - 1 + both.first);
	res = max(res, (int)adj[u].size() - 2 + both.first + both.second);
	return res;
}

int sdp[N];
int skip(int u, int p) {
	if(sdp[u] != -1) return sdp[u];
	int children = (int)adj[u].size() - (p > 0);
	int res = children;
	for(int v : adj[u]) {
		if(v == p) continue;
		res = max(res, children-1 + take(v, u));
		res = max(res, children-1 + skip(v, u));
	}
	return sdp[u] = res;
}

int tdp[N];
int take(int u, int p) {
	if(tdp[u] != -1) return tdp[u];
	int res = 1;
	for(int v : adj[u]) {
		if(v == p) continue;
		res = max(res, 1 + skip(v, u));
	}
	return tdp[u] = res;
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

	memset(sdp, -1, sizeof sdp);
	memset(tdp, -1, sizeof tdp);
	cout << solve(1, 0) << nl;

	return 0;
}