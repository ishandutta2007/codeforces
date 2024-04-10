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

#define MAX 301010
//#define MOD 100000007
//#define MOD 100000009
#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll fact[MAX];

ll mpow(ll x, ll y) {
	if (!y) return 1;
	ll res = mpow(x, y / 2);
	res *= res;
	res %= MOD;
	if (y & 1) return (res * x) % MOD;
	else return res;
}

ll inv(ll x) {
	return mpow(x, MOD - 2);
}

ll C(ll n, ll r) {
	ll res = fact[n];
	res *= inv(fact[r]);
	res %= MOD;
	res *= inv(fact[n - r]);
	res %= MOD;
	return res;
}

ll H(ll n, ll r) {
	return C(n + r - 1, r);
}

ll dp[MAX];
ll dp2[MAX];

void solve() {
	ll N;
	cin >> N;
	ll i;
	fact[0] = 1;
	for (i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % MOD;
	ll mul2 = 1;
	ll ans = 0;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp2[0] = 1;
	dp2[1] = 1;
	dp2[2] = 3;
	for (i = 3; i <= N; i++) {
		dp[i] = dp[i - 2] * (i - 1) + dp[i - 1];
		dp[i] %= MOD;
	}
	for (i = 3; i <= N; i++) {
		dp2[i] = dp2[i - 1] * (2 * i - 1);
		dp2[i] %= MOD;
	}
	for (i = 0; i * 4 <= N; i++) {
		int K = N - i * 4;
		ll tmp = mul2 * C(N - i * 2, i * 2);
		tmp %= MOD;
		tmp *= dp[K];
		tmp %= MOD;
		tmp *= dp2[i];
		tmp %= MOD;
		ans += tmp;
		ans %= MOD;
		mul2 *= 2;
		mul2 %= MOD;
	}
	cout << ans << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}