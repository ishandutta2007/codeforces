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
	string s;
	cin >> s;
	ll i;
	vector<ll> v(N), one, two;
	vector<vector<ll>> ans(N, vector<ll>(N));
	for (i = 0; i < N; i++) {
		v[i] = s[i] - '0';
	}
	ll j;
	for (i = 0; i < N; i++) {
		if (v[i] == 1) one.push_back(i);
		else two.push_back(i);
	}
	if (two.size() <= 2 && two.size() >= 1) {
		cout << no << ln;
		return;
	}
	cout << yes << ln;
	for (i = 0; i < two.size(); i++) {
		ll a, b;
		a = two[i];
		b = two[(i + 1) % two.size()];
		ans[a][b] = 1;
		ans[b][a] = -1;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i == j) {
				cout << 'X';
				continue;
			}
			if (ans[i][j] == 1) cout << '+';
			else if (ans[i][j] == -1) cout << '-';
			else cout << '=';
		}
		cout << ln;
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