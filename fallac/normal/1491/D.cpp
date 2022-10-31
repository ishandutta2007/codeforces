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
#define yes "YES"
#define no "NO"

#define MAX 401010
#define MOD 100000009
#define INF 2e18

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second

void init() {

}

void solve() {
	ll p, q;
	cin >> p >> q;
	ll p1, q1;
	p1 = q1 = 0;
	if (p > q) {
		cout << no << ln;
		return;
	}
	if (p == q) {
		cout << yes << ln;
		return;
	}
	while (p) {
		p1 += p % 2;
		q1 += q % 2;
		if (p1 < q1) {
			cout << no << ln;
			return;
		}
		p /= 2;
		q /= 2;
	}
	while (q) {
		q1 += q % 2;
		q /= 2;
	}
	if (p1 < q1) {
		cout << no << ln;
		return;
	}
	cout << yes << ln;
	return;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		solve();
	}
}