//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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

ll power(ll n, ll e) {
	ll r = 1;
	for(;e>0;e/=2) {
		if(e&1) r = r*n % MOD;
		n = n*n % MOD;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	ll n, m, l, r;
	cin >> n >> m >> l >> r;
	ll even = r/2 - (l-1)/2;
	ll odd = (r+1)/2 - l/2;
	//cerr<<"even: "<<even<<nl;
	//cerr<<"odd: "<<odd<<nl;
	ll area = n*m;
	if(area % 2 == 0) {
		ll ans = (power((even-odd) % MOD, area) + power((even+odd) % MOD, area)) % MOD;
		ans = (ans * power(2, MOD-2) % MOD + MOD) % MOD;
		cout << ans << nl;
	} else {
		ll ans = power((even+odd) % MOD, area);
		cout << ans << nl;
	}

	return 0;
}