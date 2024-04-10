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

#define MAX 2020
#define MOD 100000009

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var
ll dp[MAX][MAX];
ll s[MAX];
//

void solve() {
	ll N;
	cin >> N;
	ll i, j;
	for (i = 1; i <= N; i++) cin >> s[i];
	sort(s + 1, s + N + 1);
	ll k;
	//k:size
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			dp[i][j] = INT64_MAX;
		}
	}
	dp[1][N] = s[N] - s[1];
	for (k = N - 1; k >= 1; k--) {
		for (i = 1; i + k - 1 <= N; i++) {
			j = i + k - 1;
			if (i == 1) dp[i][j] = min(dp[i][j], dp[i][j + 1] + s[j] - s[i]);
			else if (j == N) dp[i][j] = min(dp[i][j], dp[i - 1][j] + s[j] - s[i]);
			else dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + s[j] - s[i], dp[i][j + 1] + s[j] - s[i]));
		}
	}
	ll mn = INT64_MAX;
	for (i = 1; i <= N; i++) mn = min(dp[i][i], mn);
	cout << mn << ln;
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