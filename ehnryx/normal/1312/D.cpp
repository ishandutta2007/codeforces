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
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 1;
ll fact[N], invf[N];

ll ncr(int n, int r) {
	if(r<0 || r>n) return 0;
	return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
}

ll power(ll n, int e) {
	ll r = 1;
	for(;e;e/=2) {
		if(e&1) r = r*n % MOD;
		n = n*n % MOD;
	}
	return r;
}

ll inverse(ll n) {
	return power(n, MOD-2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	fact[0] = invf[0] = 1;
	for(int i=1; i<N; i++) {
		fact[i] = fact[i-1] * i % MOD;
		invf[i] = inverse(fact[i]);
	}

	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for(int i=1; i<=m; i++) {
		ans += ncr(i-1, n-2) * (n-2) % MOD * power(2, n-3) % MOD;
	}
	cout << ans % MOD << nl;

	return 0;
}