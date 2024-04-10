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

#define MAX 301010
#define MOD 1000000007
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

typedef pair<ll, ll> pll;

ll mpow(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	ll res = mpow(x, y / 2);
	res *= res;
	res %= MOD;
	if (y & 1) res *= x;
	res %= MOD;
	return res;
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	ll a = 1LL << N;
	a -= 2;
	cout << ((6 * mpow(4, a)) % MOD) << ln;
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