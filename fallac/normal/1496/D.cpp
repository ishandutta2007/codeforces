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

#define MAX 101010
#define MOD 100000009

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

ll arr[MAX], l[MAX], r[MAX];
ll dp[MAX];

void solve() {
	ll N;
	cin >> N;
	ll i;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (i = 2; i <= N; i++) {
		if (arr[i - 1] < arr[i]) l[i] = l[i - 1] + 1;
	}
	for (i = N - 1; i >= 1; i--) {
		if (arr[i + 1] < arr[i]) r[i] = r[i + 1] + 1;
	}
	ll m = 0;
	for (i = 1; i <= N; i++) {
		m = max(m, l[i]);
		m = max(m, r[i]);
	}
	if (!m) {
		cout << 0 << ln;
		return;
	}
	ll x = 0;
	for (i = 1; i <= N; i++) {
		if (m == l[i] || m == r[i]) {
			if (x) {
				cout << 0 << ln;
				return;
			}
			x = i;
		}
	}
	ll a = max(l[x], r[x]);
	ll b = min(l[x], r[x]);
	a++;
	b++;
	if (a % 2) a--;
	if (b > a) cout << 1 << ln;
	else cout << 0 << ln;
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