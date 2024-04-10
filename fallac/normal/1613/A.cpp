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

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll mn = min(b, d);
	b -= mn;
	d -= mn;
	if (b == 0 && d == 0) {
		if (a > c) cout << '>' << ln;
		else if (a < c) cout << '<' << ln;
		else cout << '=' << ln;
	}
	else {
		if (b == 0) {
			ll i;
			for (i = 0; i < d; i++) {
				c *= 10;
				if (a < c) {
					cout << '<' << Ln;
					return;
				}
			}
			if (a > c) cout << '>' << ln;
			else if (a < c) cout << '<' << ln;
			else cout << '=' << ln;
		}
		else {
			ll i;
			for (i = 0; i < b; i++) {
				a *= 10;
				if (a > c) {
					cout << '>' << ln;
					return;
				}
			}
			if (a > c) cout << '>' << ln;
			else if (a < c) cout << '<' << ln;
			else cout << '=' << ln;
		}
	}
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