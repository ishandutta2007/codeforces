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

#define MAX 1010
#define MOD 100000009
#define INF 100000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

ll arr[MAX][MAX][2][2];
bool dp[MAX][MAX][2][2];

ll f(ll c00, ll c01, ll x, ll rev) {
	if (c00 == 1 && c01 == 2 && x == 0 && rev == 0) {
		ll a = 1;
	}
	if (!(c00 + c01 + x)) return 0;
	if (dp[c00][c01][x][rev]) return arr[c00][c01][x][rev];
	ll res = INF;
	if (c01) res = min(res, -f(c00, c01 - 1, x, (c01 - 1) ? 1 : 0) + 1);
	if (c00) res = min(res, -f(c00 - 1, c01 + 1, x, (c01 + 1) ? 1 : 0) + 1);
	if (x) res = min(res, -f(c00, c01, 0, c01 ? 1 : 0) + 1);
	if (rev) res = min(res, -f(c00, c01, 0, 0));
	dp[c00][c01][x][rev] = true;
	return arr[c00][c01][x][rev] = res;
}

void solve() {
	ll N;
	cin >> N;
	string s;
	cin >> s;
	ll i;
	vector<ll> v;
	v.resize(N + 1);
	if (N == 1) {
		if (s[0] == '1') {
			cout << "DRAW" << ln;
			return;
		}
	}
	for (i = 0; i < N; i++) v[i + 1] = s[i] == '0' ? 0 : 1;
	ll c00 = 0;
	ll c01 = 0;
	ll x = 0;
	ll cnt = 0;
	if ((N % 2) && (!v[(N + 1) / 2])) x = 1;
	for (i = 1; i <= N / 2; i++) {
		if (v[i] == 1 && v[N - i + 1] == 1) cnt += 0;
		else if (v[i] == 0 && v[N - i + 1] == 0) c00++;
		else c01++;
	}
	ll a, b;
	a = b = 0;
	ll chk = 0;
	ll p = 0;
	ll res = f(c00, c01, x, c01 ? 1 : 0);
	if (res == 0) cout << "DRAW" << ln;
	else if (res < 0) cout << "ALICE" << ln;
	else if (res > 0) cout << "BOB" << ln;
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