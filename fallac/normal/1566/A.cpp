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
	ll N, S;
	cin >> N >> S;
	if (N == 1) {
		cout << S << ln;
		return;
	}
	if (N == 2) {
		cout << S / 2 << ln;
		return;
	}
	if (N % 2 == 0) {
		ll a = N / 2 - 1;
		cout << S / (N - a) << ln;
	}
	else {
		ll a = N / 2;
		cout << S / (N - a) << ln;
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