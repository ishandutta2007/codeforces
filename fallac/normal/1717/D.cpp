/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 201010
#define MOD 1000000007
//#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll mpow(ll x, ll y) {
	if (y == 0) return 1;
	ll res = mpow(x, y / 2);
	res *= res;
	res %= MOD;
	if (y & 1) res *= x;
	return res % MOD;
}

ll inv(ll x) { return mpow(x, MOD - 2); }

void solve() {
	ll N, K;
	cin >> N >> K;
	ll r;
	ll val = 1;
	ll ans = 0;
	for (r = 0; r <= min(N, K); r++) {
		ans += val;
		ans %= MOD;
		val *= (N - r);
		val %= MOD;
		val *= inv(r + 1);
		val %= MOD;
	}
	cout << ans << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}