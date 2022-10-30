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

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
#define MOD 1000000007
//#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll mpow(ll a, ll x) {
	if (x == 1) return a;
	if (x == 0) return 1;
	a %= MOD;
	ll res = mpow(a, x / 2);
	res *= res;
	res %= MOD;
	if (x & 1) res *= a;
	res %= MOD;
	return res;
}

void solve() {
	ll N, K;
	cin >> N >> K;
	if (N % 2) {
		cout << mpow(mpow(2, N - 1) + 1, K) << Ln;
	}
	else {
		ll i;
		ll ans = 0;
		ans += mpow(mpow(2, N - 1) - 1, K);
		for (i = 0; i < K; i++) {
			ans += mpow(mpow(2, N - 1) - 1, K - i - 1) * mpow(2, i * N);
			ans %= MOD;
		}
		cout << ans << ln;
	}
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