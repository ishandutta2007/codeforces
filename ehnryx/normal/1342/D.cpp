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



// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<int> c(k+1);
	for(int i=1; i<=k; i++) {
		cin >> c[i];
	}

	int maxv = 0;
	for(int i=1; i<=n; i++) {
		int cap = c[a[n-i]];
		maxv = max(maxv, (i + cap-1) / cap);
	}

	vector<vector<int>> group(maxv);
	for(int i=1; i<=n; i++) {
		group[i % maxv].push_back(a[n-i]);
	}

	cout << maxv << nl;
	for(const vector<int>& v : group) {
		cout << v.size();
		for(int j : v) {
			cout << " " << j;
		}
		cout << nl;
	}

	return 0;
}