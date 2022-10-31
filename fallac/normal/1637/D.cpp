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
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll N;
	cin >> N;
	vector<ll> A(N + 1), B(N + 1);
	ll i;
	ll s = 0;
	ll sa, sb;
	sa = 0;
	ll sq = 0;
	for (i = 1; i <= N; i++) cin >> A[i], s += A[i], sa += A[i];
	for (i = 1; i <= N; i++) cin >> B[i], s += B[i];
	for (i = 1; i <= N; i++) sq += A[i] * A[i] + B[i] * B[i];
	if (N == 1) {
		cout << 0 << ln;
		return;
	}
	ll M = 30201;
	vector<ll> dp(M), cpy;
	cpy = dp;
	dp[0] = 1;
	for (i = 1; i <= N; i++) {
		ll j;
		for (j = M - 1; j >= 0; j--) {
			if (dp[j]) cpy[j + A[i]] = cpy[j + B[i]] = 1;
		}
		dp = cpy;
		cpy = vector<ll>(M, 0);
	}
	for (i = 0; i < M; i++) {
		if (!dp[i]) continue;
		if (abs(2 * sa - s) > abs(2 * i - s)) sa = i;
	}
	sb = s - sa;
	ll ans = sa * sa + sb * sb + sq * (N - 2);
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