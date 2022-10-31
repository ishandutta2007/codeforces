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

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll A[MAX];
ll B[MAX];

void solve() {
	ll N, M, ta, tb, K;
	cin >> N >> M >> ta >> tb >> K;
	ll ans = tb;
	ll i;
	for (i = 0; i < N; i++) cin >> A[i], A[i] += ta;
	for (i = 0; i < M; i++) cin >> B[i];
	if (K >= min(N, M)) {
		cout << -1 << ln;
		return;
	}
	for (i = 0; i <= K; i++) {
		ll ft = A[i];
		ll loc = lower_bound(B, B + M, ft) - B;
		ll rem = K - i;
		loc += rem;
		loc = min(loc, M);
		if (loc == M) {
			cout << -1 << ln;
			return;
		}
		else ans = max(ans, B[loc] + tb);
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