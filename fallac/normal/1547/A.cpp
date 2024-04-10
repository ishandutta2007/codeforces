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
//#define MOD 1000000007
ll MOD;
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "Yes"
#define no "No"



void solve() {
	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	ll x = 0;
	if (a == c && c == e & min(b, d) <= f && f <= max(b, d)) x = 2;
	if (b == d && d == f & min(a, c) <= e && e <= max(a, c)) x = 2;
	cout << abs(a - c) + abs(b - d) + x << ln;
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