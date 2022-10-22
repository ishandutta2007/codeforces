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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int L = 60;

ll count(int n, bool o) {
	ll res = 0;
	for(int j=0; j<=n; j++) {
		res += (o ? 1LL<<j : 2LL<<j);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	ll n, k;
	cin >> n >> k;

	ll ans = 0;
	for (int i=0; i<L; i++) {
		ll mask = (1LL<<i) - 1;
		ll pref = n >> i;
		if(pref > 0 && (n & mask) + 1 + count(i-1, pref % 2) >= k) {
			ans = max(ans, pref);
		}
		if(pref-1 > 0 && (pref-1) % 2 == 0 && (n & mask) + 1 + (1LL<<i) + count(i-1, false) >= k) {
			ans = max(ans, pref-1);
		}
		if(pref-1 > 0 && count(i, true) >= k) {
			ans = max(ans, pref-1);
		}
		if(pref-2 > 0 && count(i, (pref-2) % 2) >= k) {
			ans = max(ans, pref-2);
		}
		if(pref-3 > 0 && count(i, (pref-3) % 2) >= k) {
			ans = max(ans, pref-3);
		}
	}
	cout << ans << nl;

	return 0;
}