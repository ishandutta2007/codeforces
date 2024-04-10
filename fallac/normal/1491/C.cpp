/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'

#define MAX 401010
#define MOD 100000009
#define INF 2e18

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second

ll arr[MAX];
ll dp[MAX];

void init(ll N) {
	ll i;
	for (i = 1; i <= N; i++) dp[i] = 0;
}

void solve() {
	ll N;
	cin >> N;
	init(N);
	ll i;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		if (arr[i] != 1) {
			ll k = dp[i];
			ll a = arr[i];
			for (ll j = min(i + arr[i], N); j >= i + 2; j--) {
				dp[j]++;
			}
			if (dp[i] >= arr[i] - 1) {
				dp[i] -= arr[i] - 1;
				dp[i + 1] += dp[i];
				continue;
			}
			else {
				ans += arr[i] - dp[i] - 1;
				dp[i] = 0;
			}
		}
		else {
			dp[i + 1] += dp[i];
		}
	}
	cout << ans << ln;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		solve();
	}
}