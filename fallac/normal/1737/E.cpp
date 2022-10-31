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

#define MAX 1010101
#define MOD 1000000007
//#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll dp[MAX]; // a_1 + a_2 + ... + a_k = N - i, i>a_1, i+a_1>a_2, ...
ll sumdp[MAX];
ll ans[MAX];

ll mpow(ll x, ll y) {
	if (!y) return 1;
	ll res = mpow(x, y / 2);
	res *= res;
	res %= MOD;
	if (y & 1) res = (res * x) % MOD;
	return res;
}

ll inv(ll v) {
	return mpow(v, MOD - 2);
}

void solve() {
	int N;
	cin >> N;
	if (N == 1) {
		cout << 1 << ln;
		return;
	}
	int i;
	dp[N] = 1;
	sumdp[N] = 1;
	sumdp[N + 1] = 0;
	for (i = N - 1; i >= 2; i--) {
		dp[i] = sumdp[i + 1] - sumdp[min(N + 1, i * 2)];
		dp[i] %= MOD;
		if (dp[i] < 0) dp[i] += MOD;
		sumdp[i] = (sumdp[i + 1] + dp[i]) % MOD;
	}
	for (i = 2; i <= N; i++) {
		ans[i] = 1;
		if (i == 2) ans[i] *= 2;
		else {
			int minr = (i - 1) / 2;
			ans[i] = mpow(2, i - 1 - minr);
		}
		ans[i] *= dp[i];
		ans[i] %= MOD;
	}
	for (i = 1; i <= N; i++) {
		ans[i] *= inv(mpow(2, N - 1));
		ans[i] %= MOD;
		if (ans[i] < 0) ans[i] += MOD;
		cout << ans[i] << ln;
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