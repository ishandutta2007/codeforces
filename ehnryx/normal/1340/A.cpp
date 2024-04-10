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
int a[N];

int dsu[N], sz[N];
int find(int i) {
	if(dsu[i] == -1) return i;
	return dsu[i] = find(dsu[i]);
}
int link(int i, int j) {
	if(find(i) != find(j)) {
		sz[find(j)] += sz[find(i)];
		dsu[find(i)] = find(j);
	}
	return sz[find(j)];
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		fill(dsu, dsu+n+1, -1);
		fill(sz, sz+n+1, 1);
		vector<pair<int,int>> order;
		for(int i=0; i<n; i++) {
			cin >> a[i];
			order.emplace_back(a[i], i);
		}
		sort(order.begin(), order.end());

		multiset<int> have;
		for(int i=0; i<n; i++) {
			have.insert(1);
		}

		bool ok = true;
		for(auto [v, i] : order) {
			ok &= (sz[find(i)] == *have.rbegin());
			if(!ok) break;
			have.erase(prev(have.end()));
			int cur = link(i, i+1);
			if(find(i) < n) {
				have.insert(cur);
			}
		}
		if(ok) {
			cout << "Yes" << nl;
		} else {
			cout << "No" << nl;
		}
	}

	return 0;
}