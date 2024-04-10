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

ll power(ll n, ll e, ll m) {
	ll r = 1;
	for(;e;e/=2) {
		if(e&1) r = r*n % m;
		n = n*n % m;
	}
	return r;
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);

	vector<int> cnt(m);
	vector<int> ans(m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			ans[(a[i]+m-j)%m] += cnt[j];
		}
		cnt[a[i]%m]++;
	}

	ll res = 1;
	for(int j=0; j<m; j++) {
		res = res * power(j, ans[j], m) % m;
	}
	cout << res << nl;

	return 0;
}