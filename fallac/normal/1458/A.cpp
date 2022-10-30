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

ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	gcd(b % a, a);
}

void solve() {
	ll N, M;
	cin >> N >> M;
	vector<ll> a, ans;
	a.resize(N + 1);
	ll i;
	for (i = 1; i <= N; i++) cin >> a[i];
	if (N == 1) {
		ll x;
		for (i = 1; i <= M; i++) {
			cin >> x;
			ans.push_back(x + a[1]);
		}
		for (i = 0; i < ans.size(); i++) cout << ans[i] << ln;
		return;
	}
	ll g = abs(a[2] - a[1]);
	for (i = 3; i <= N; i++) {
		g = gcd(g, abs(a[i] - a[i - 1]));
	}
	ll x;
	for (i = 1; i <= M; i++) {
		cin >> x;
		ans.push_back(gcd(a[1] + x, g));
	}
	for (i = 0; i < ans.size(); i++) cout << ans[i] << ln;
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