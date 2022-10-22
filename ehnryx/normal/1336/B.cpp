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

ll sqr(ll x) {
	return x*x;
}

ll compute(int A, const vector<int>& b, const vector<int>& c) {
	ll ans = INFLL;
	auto it = lower_bound(b.begin(), b.end(), A);
	if(it != b.end()) {
		auto jt = lower_bound(c.begin(), c.end(), (A+*it)/2);
		if(jt != c.end()) {
			ll cur = sqr(A-*it) + sqr(*it-*jt) + sqr(A-*jt);
			ans = min(ans, cur);
		}
		if(jt != c.begin()) {
			jt = prev(jt);
			ll cur = sqr(A-*it) + sqr(*it-*jt) + sqr(A-*jt);
			ans = min(ans, cur);
		}
	}
	if(it != b.begin()) {
		it = prev(it);
		auto jt = lower_bound(c.begin(), c.end(), (A+*it)/2);
		if(jt != c.end()) {
			ll cur = sqr(A-*it) + sqr(*it-*jt) + sqr(A-*jt);
			ans = min(ans, cur);
		}
		if(jt != c.begin()) {
			jt = prev(jt);
			ll cur = sqr(A-*it) + sqr(*it-*jt) + sqr(A-*jt);
			ans = min(ans, cur);
		}
	}
	return ans;
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
		int na, nb, nc;
		cin >> na >> nb >> nc;
		vector<int> a(na), b(nb), c(nc);
		for(int i=0; i<na; i++) {
			cin >> a[i];
		}
		for(int i=0; i<nb; i++) {
			cin >> b[i];
		}
		for(int i=0; i<nc; i++) {
			cin >> c[i];
		}
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());

		ll ans = INFLL;
		for(int A : a) {
			ans = min(ans, compute(A, b, c));
			ans = min(ans, compute(A, c, b));
		}
		cout << ans << nl;
	}

	return 0;
}