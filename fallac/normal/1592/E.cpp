/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O0")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 2310100
#define MAXS 21
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

ll arr[MAX];
ll dp[2][MAX];

void solve() {
	ll N;
	cin >> N;
	ll i;
	for (i = 1; i <= N; i++) cin >> arr[i];
	vector<ll> v;
	ll ans = 0;
	ll d;
	for (d = MAXS - 1; d >= 0; d--) {
		ll i, j;
		j = 0;
		ll sum = 0;
		vector<pair<ll, ll>> e;
		for (i = 1; i <= N; i++) {
			if (arr[i] & (1LL << d)) {
				ll a = arr[i] >> d;
				sum ^= a;
				if (dp[i % 2][sum]) ans = max(i - (dp[i % 2][sum] - 1), ans);
				if (dp[i % 2][sum] == 0) dp[i % 2][sum] = i + 1, e.emplace_back(i % 2, sum);
				if (j == 0) j = i, dp[(i + 1) % 2][0] = i, e.emplace_back((i + 1) % 2, 0);
			}
			else {
				ll k;
				sum = 0;
				for (auto x : e) dp[x.first][x.second] = 0;
				e.clear();
				j = 0;
			}
		}
		for (auto x : e) dp[x.first][x.second] = 0;
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