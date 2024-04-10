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

//var

//

void solve() {
	ll a, b, c, m;
	cin >> a >> b >> c >> m;
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	if (m > a + b + c - 3) {
		cout << no << Ln;
		return;
	}
	ll x = min(m, c - b);
	m -= x;
	c -= x;
	if (m) {
		x = min(b - a, m / 2);
		b -= x;
		c -= x;
		m -= 2 * x;
		if (m) {
			if (a == b) {
				x = m / 3;
				a -= x;
				b -= x;
				c -= x;
				m -= 3 * x;
			}
			if (m) {
				if (m == 1) a--;
				else a--, b--;
			}
		}
	}
	if (c > a + b + 1) cout << no << ln;
	else cout << yes << ln;
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