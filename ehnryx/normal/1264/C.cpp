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
const ll MOD = 998244353;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll n, ll e) {
	ll res = 1;
	for(;e;e/=2) {
		if(e&1) res = res*n % MOD;
		n = n*n % MOD;
	}
	return res;
}

ll inverse(ll n) {
	return power(n, MOD-2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	ll base = inverse(100);
	int p[n+1];
	for(int i=1; i<=n; i++) {
		cin >> p[i];
		p[i] = p[i] * base % MOD;
	}

	int suf[n+2], inv[n+2];
	suf[n+1] = 1;
	inv[n+1] = 1;
	for(int i=n; i>=1; i--) {
		suf[i] = (ll) suf[i+1] * inverse(p[i]) % MOD;
		inv[i] = (ll) inv[i+1] * p[i] % MOD;
	}

	int pre[n+1];
	pre[0] = 0;
	for(int i=1; i<=n; i++) {
		pre[i] = (pre[i-1] + suf[i]) % MOD;
	}

	auto get = [&](int l, int r) {
		ll res = (ll) (pre[r-1] - pre[l-1]) * inv[r] % MOD;
		return (res + MOD) % MOD;
	};

	ll ans = pre[n];
	set<int> vals;
	vals.insert(1);
	vals.insert(n+1);
	for(int i=0; i<m; i++) {
		int v;
		cin >> v;
		if(vals.count(v)) {
			auto it = vals.find(v);
			ans += MOD - get(*prev(it), v);
			ans += MOD - get(v, *next(it));
			ans += get(*prev(it), *next(it));
			ans %= MOD;
			vals.erase(it);
		} else {
			auto it = vals.insert(v).first;
			ans += get(*prev(it), v);
			ans += get(v, *next(it));
			ans += MOD - get(*prev(it), *next(it));
			ans %= MOD;
		}
		cout << ans << nl;
	}

	return 0;
}