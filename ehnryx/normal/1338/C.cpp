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

ll calc(ll s, ll t, ll n) {
	if(t == 1) {
		assert(n == 1);
		return s;
	}
	t /= 4;
	if(n <= t) {
		return calc(s+0*t, t, n-0*t);
	} else if(n <= 2*t) {
		return calc(s+2*t, t, n-1*t);
	} else if(n <= 3*t) {
		return calc(s+3*t, t, n-2*t);
	} else {
		assert(n <= 4*t);
		return calc(s+1*t, t, n-3*t);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		ll n;
		cin >> n;
		int id = n % 3;
		n = (n+2) / 3; // 1,2,3 -> 1
		ll t = 1;
		while(t < n) {
			n -= t;
			t *= 4;
		}
		assert(n >= 1);
		ll a = t + n-1;
		ll b = calc(2*t, t, n);
		ll c = a ^ b;
		if(id == 1) cout << a << nl;
		else if(id == 2) cout << b << nl;
		else cout << c << nl;
	}

	return 0;
}