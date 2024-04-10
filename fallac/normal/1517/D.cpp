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

#define MAX 600
#define MOD 100000009
#define INF 100000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var
ll arr[MAX][MAX][4];
ll dp[MAX][MAX][12];
//

ll N, M, K;

bool chk(ll x, ll y) {
	if (!(1 <= x && x <= N)) return 0;
	if (!(1 <= y && y <= M)) return 0;
	return 1;
}

void solve() {
	cin >> N >> M >> K;
	ll i, j, a;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M - 1; j++) {
			cin >> a;
			arr[i][j][0] = arr[i][j + 1][2] = a;
		}
	}
	for (i = 1; i <= N - 1; i++) {
		for (j = 1; j <= M; j++) {
			cin >> a;
			arr[i][j][1] = arr[i + 1][j][3] = a;
		}
	}
	if (K % 2) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) cout << -1 << bb;
			cout << ln;
		}
		return;
	}
	K /= 2;
	ll k;
	for (k = 1; k <= K; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) {
				dp[i][j][k] = INF;
				if (chk(i, j + 1)) dp[i][j][k] = min(dp[i][j][k], dp[i][j + 1][k - 1] + arr[i][j + 1][2]);
				if (chk(i, j - 1)) dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k - 1] + arr[i][j - 1][0]);
				if (chk(i + 1, j)) dp[i][j][k] = min(dp[i][j][k], dp[i + 1][j][k - 1] + arr[i + 1][j][3]);
				if (chk(i - 1, j)) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - 1] + arr[i - 1][j][1]);
			}
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cout << (2 * dp[i][j][K]) << bb;
		}
		cout << ln;
	}
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