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

ll A[MAX];
ll B[MAX];

ll dp[110][20010];

void solve() {
	ll N;
	cin >> N;
	ll i;
	vector<ll> selected;
	ll k;
	ll X = 0;
	for (i = 1; i <= N; i++) cin >> A[i] >> B[i], A[i] <<= 1, B[i] <<= 1, X += B[i];
	dp[0][0] = X / 2;
	ll j;
	for (i = 1; i <= N; i++) {
		for (j = N; j >= 0; j--) {
			for (k = 0; k <= 20000; k++) {
				if (dp[j][k]) {
					dp[j + 1][k + A[i]] = max(dp[j + 1][k + A[i]], dp[j][k] + B[i] / 2);
				}
			}
		}
	}
	for (i = 1; i <= N; i++) {
		ll mx = 0;
		for (j = 0; j <= 20000; j++) mx = max(mx, min(j, dp[i][j]));
		cout << mx / 2;
		if (mx % 2) cout << ".5";
		cout << bb;
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