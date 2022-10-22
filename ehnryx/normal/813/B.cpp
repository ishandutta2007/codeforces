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



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	ll x, y, l, r;
	cin >> x >> y >> l >> r;

	vector<ll> bad = { l-1, r+1 };
	for(int i=0; i<=60; i++) {
		ld a = powl(x, i);
		if(a > r+1) continue;
		ll xv = llround(a);
		for(int j=0; j<=60; j++) {
			ld b = powl(y, j);
			if(b > r+1) continue;
			ll yv = llround(b);
			if(l <= xv + yv && xv + yv <= r) {
				bad.push_back(xv + yv);
			}
		}
	}
	sort(bad.begin(), bad.end());
	bad.resize(unique(bad.begin(), bad.end()) - bad.begin());

	ll ans = 0;
	for(int i=1; i<bad.size(); i++) {
		ans = max(ans, bad[i] - bad[i-1] - 1);
	}
	cout << ans << nl;

	return 0;
}