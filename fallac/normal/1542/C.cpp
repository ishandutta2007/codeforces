/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
#define MOD 1000000007
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "Yes"
#define no "No"

ll gcd(ll a, ll b) {
	while (b) b %= a ^= b ^= a ^= b;
	return a;
}

ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	a /= g;
	b /= g;
	return a * b * g;
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	ll ans = N;
	ll l = 1;
	for (i = 1; i <= 50; i++) {
		ans += (N / l);
		ans %= MOD;
		l = lcm(l, i + 1);
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