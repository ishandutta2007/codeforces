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

const int N = 5e5 + 1;
ordered_set<int> nbs[N];
vector<int> adj[N];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<pair<int,int>> v;
	for(int i=1; i<=n; i++) {
		int a;
		cin >> a;
		v.emplace_back(a, i);
	}
	sort(v.begin(), v.end());

	vector<int> ans;
	for(auto [a, i] : v) {
		ans.push_back(i);
		if(nbs[i].find(a) != nbs[i].end() || nbs[i].order_of_key(a) != a-1) {
			cout << -1 << nl;
			return 0;
		}
		for(int j : adj[i]) {
			nbs[j].insert(a);
		}
	}

	for(int it : ans) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}