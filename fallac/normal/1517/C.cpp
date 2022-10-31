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

ll arr[MAX];
ll mp[MAX][MAX];

ll N;

bool chk(ll x, ll y) {
	if (x < y) return false;
	if (!(1 <= x && x <= N)) return false;
	if (!(1 <= y && y <= N)) return false;
	return true;
}

ll cnt = 0;

void dfs(ll x, ll y, ll k) {
	if (cnt == k) return;
	mp[x][y] = k, cnt++;
	if (cnt == k) return;
	if (chk(x, y - 1) && (mp[x][y - 1] == 0)) dfs(x, y - 1, k);
	else dfs(x + 1, y, k);
}

void solve() {
	cin >> N;
	ll i, j;
	for (i = 1; i <= N; i++) cin >> arr[i];
	for (i = 1; i <= N; i++) {
		cnt = 0;
		dfs(i, i, arr[i]);
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			cout << mp[i][j] << bb;
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