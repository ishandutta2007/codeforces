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

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

void NO() {
	cout << no << ln;
	exit(0);
}

void solve() {
	ll N;
	cin >> N;
	if (N % 2) {
		cout << no << ln;
		return;
	}
	if (N % 4) {
		N /= 2;
		ll x = sqrt(N);
		if (x * x == N) cout << yes << ln;
		else cout << no << ln;
	}
	else {
		N /= 4;
		ll x = sqrt(N);
		if (x * x == N) cout << yes << ln;
		else {
			N *= 4;
			N /= 2;
			ll x = sqrt(N);
			if (x * x == N) cout << yes << ln;
			else cout << no << ln;
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