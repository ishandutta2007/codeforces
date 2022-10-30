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
	if (a == 0) return b;
	while (b) {
		if (a == 0) return b;
		a ^= b ^= a ^= b %= a;
	}
	return a;
}

void solve() {
	ll N;
	cin >> N;
	vector<ll> v(N);
	ll i;
	ll mn = INF;
	for (i = 0; i < N; i++) cin >> v[i], mn = min(mn, v[i]);
	ll g = 0;
	for (i = 0; i < N; i++) g = gcd(v[i] - mn, g);
	if (g == 0) g = -1;
	cout << g << ln;
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