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

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var
ll notprime[MAX];
//

void solve() {
	ll N;
	cin >> N;
	vector<ll> a;
	a.resize(N);
	ll i, j;
	for (i = 0; i < N - 1; i++) a[i] = 1;
	i = 1;
	while (!notprime[i] || notprime[N - 1 + i]) 
		i++;
	a[N - 1] = i;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << a[(i + j) % N] << bb;
		}
		cout << ln;
	}
}

void init() {
	ll i;
	i = 2;
	notprime[1] = 1;
	for (i = 2; i <= 100000; i++) {
		if (notprime[i] == 0) {
			for (ll j = i * 2; j <= 100000; j += i) {
				notprime[j] = 1;
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	init();
	while (T--) {
		solve();
	}
}