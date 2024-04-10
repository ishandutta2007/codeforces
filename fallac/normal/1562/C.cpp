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
	ll N;
	cin >> N;
	ll i;
	string s;
	cin >> s;
	ll mn = INF, mx = -1;
	for (i = 0; i < N; i++) {
		if (s[i] == '0') {
			mn = i;
			break;
		}
	}
	for (i = N - 1; i >= 0; i--) {
		if (s[i] == '0') {
			mx = i;
			break;
		}
	}
	if (mx == -1) {
		cout << 2 << bb << N << bb << 1 << bb << N-1 << ln;
	}
	else if (mx >= (N) / 2) {
		cout << 1 << bb << mx+1 << bb << 1 << bb << mx << ln;
	}
	else {
		cout << mx +2 << bb << N << bb << mx + 1 << bb << N << ln;
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