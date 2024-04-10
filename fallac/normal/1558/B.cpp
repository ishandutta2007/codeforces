/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var
ll arr[4000001];
//

void solve() {
	ll N, M;
	cin >> N >> M;
	ll i;
	ll sum, dp;
	ll arrsum = 0;
	sum = 1;
	dp = 1;
	if (N <= 3) {
		if (N == 1) cout << 1 << ln;
		if (N == 2) cout << 2 << ln;
		if (N == 3) cout << 5 << ln;
		return;
	}
	for (i = 2; i <= N; i++) {
		arrsum += arr[i];
		arrsum %= M;
		dp = ((i - (i / 2)) + sum) % M + arrsum;
		dp %= M;
		ll k;
		for (k = 2;; k++) {
			ll st = k * i;
			ll en = k * i + k;
			if (st <= N) arr[st] += dp, arr[st] %= M;
			else break;
			if (en <= N) arr[en] -= dp, arr[en] %= M;
		}
		sum += dp;
		sum %= M;
	}
	if (dp < 0) dp += M;
	cout << dp << ln;
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