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

const int N = 1e5 + 1;
vector<int> adj[N];

void remove_parent(int u, int p) {
	auto it = find(adj[u].begin(), adj[u].end(), p);
	if(it != adj[u].end()) {
		adj[u].erase(it);
	}
	for(int v : adj[u]) {
		remove_parent(v, u);
	}
}

vector<pair<int,int>> ans;
void solve(int u, int cur) {
	assert(cur > 0);
	ans.push_back(make_pair(u, cur));
	int children = adj[u].size();
	int val = cur-1 - children;
	int extra = 0;
	if(val < 0) {
		extra = children - (cur-1);
		assert(extra > 0 && extra <= children);
		for(int i=0; i<extra; i++) {
			solve(adj[u][i], cur + i+1);
			ans.push_back(make_pair(u, cur + i+1));
		}
		val = 0;
	}
	ans.push_back(make_pair(u, val++));
	for(int i=extra; i<children; i++) {
		solve(adj[u][i], val);
		ans.push_back(make_pair(u, val++));
	}
	assert(val == cur);
}

// TODO
// double-check correctness
// read limits carefully
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
	remove_parent(1, 0);

	ans.push_back(make_pair(1, 0));
	for(int i=0; i<adj[1].size(); i++) {
		solve(adj[1][i], i+1);
		ans.push_back(make_pair(1, i+1));
	}

	cout << ans.size() << nl;
	set<pair<int,int>> ok;
	int pa = 1;
	int pb = INF;
	for(auto [a, b] : ans) {
		cout << a << " " << b << nl;
		assert(b == pb+1 || (a == pa && 0 <= b && b < pb));
		assert(ok.insert(make_pair(a, b)).second);
		pa = a;
		pb = b;
	}

	return 0;
}