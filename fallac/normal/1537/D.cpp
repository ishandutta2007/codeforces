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
	ll N;
	cin >> N;
	if (N >= 10) {
		ll x = N;
		ll cnt = 0;
		while (x) {
			if (x == 1) break;
			if (x % 2) {
				cnt = -1;
				break;
			}
			x /= 2;
			cnt++;
		}
		if (N <= 16) cnt = -1;
		if (cnt != -1) {
			if (cnt % 2) {
				cout << "Bob" << ln;
			}
			else {
				cout << "Alice" << ln;
			}
			return;
		}
		if (N % 2) {
			cout << "Bob" << ln;
		}
		else {
			cout << "Alice" << ln;
		}
	}
	else {
		ll ans[] = { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 };
		if (ans[N]) cout << "Alice" << ln;
		else cout << "Bob" << ln;
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