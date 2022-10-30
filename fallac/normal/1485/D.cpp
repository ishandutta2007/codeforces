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

ll arr[1000][1000];

void solve() {
	ll N, M;
	cin >> N >> M;
	ll i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) cin >> arr[i][j];
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if ((i + j) % 2) cout << 720720 << bb;
			else cout << 720720 - (arr[i][j] * arr[i][j] * arr[i][j] * arr[i][j]) << bb;
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