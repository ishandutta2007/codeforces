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
	ll a, b, c;
	cin >> a >> b >> c;
	if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
		cout << 0 << ln;
	}
	else {
		if (c % 2) {
			if (b % 2) {
				if (a % 2) {
					cout << 0 << ln;
				}
				else {
					cout << 1 << Ln;
				}
			}
			else {
				if (a % 2) {
					cout << 0 << ln;
				}
				else {
					cout << 1 << Ln;
				}
			}
		}
		else {
			if (b % 2) {
				if (a % 2) {
					cout << 1 << ln;
				}
				else {
					cout << 0 << Ln;
				}
			}
			else {
				if (a % 2) {
					cout << 1 << ln;
				}
				else {
					cout << 0 << ln;
				}
			}
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