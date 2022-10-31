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
#define yes "Yes"
#define no "No"

//var

//

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;
	ll i;
	if (a == 1) {
		n--;
		if (n % b) cout << no << ln;
		else cout << yes << ln;
	}
	else {
		ll k;
		k = 1;
		ll c = 0;
		while (1) {
			if (k > n) break;
			if ((n - k) % b == 0) {
				c = 1;
				break;
			}
			k *= a;
		}
		if (c) cout << yes << ln;
		else cout << no << ln;
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