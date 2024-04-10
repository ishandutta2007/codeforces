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

#define MAX 1010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll vis[MAX][MAX];
ll arr[MAX][MAX];

ll dx[4] = { -1, 0, 1, 0 };
ll dy[4] = { 0, 1, 0, -1 };

void solve() {
	ll N;
	cin >> N;
	ll i, j;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) cin >> arr[i][j];
	N++;
	for (i = 0; i <= N; i++) for (j = 0; j <= N; j++) vis[i][j] = 0;
	N--;
	if (N == 2) {
		cout << (arr[1][1] ^ arr[1][2]) << ln;
		return;
	}
	ll k;
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			ll c = 1;
			for (k = 0; k < 4; k++) if (vis[i + dx[k]][j + dy[k]]) c = 0;
			if (c) {
				ans ^= arr[i][j];
				for (k = 0; k < 4; k++) vis[i + dx[k]][j + dy[k]] = 1;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			assert(vis[i][j]);
		}
	}
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