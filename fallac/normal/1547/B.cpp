/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 1000000007
ll MOD;
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "Yes"
#define no "No"



void solve() {
	string s;
	cin >> s;
	ll N = s.size();
	ll i;
	vector<ll> v;
	v.resize(26);
	for (i = 0; i < N; i++) {
		if (v[s[i] - 97]) {
			cout << no << ln;
			return;
		}
		v[s[i] - 97] = i + 1;
	}
	ll cnt = 0;
	for (i = 0; i < N; i++) {
		if (v[i]) cnt++;
	}
	if (cnt != N) {
		cout << no << ln;
		return;
	}
	ll mx = 0, mn = INF;
	for (i = 0; i < N; i++) {
		if (v[i] > v[0]) {
			if (mx > v[i]) {
				cout << no << ln;
				return;
			}
		}
		else {
			if (mn < v[i]) {
				cout << no << ln;
				return;
			}
		}
		mn = min(v[i], mn);
		mx = max(v[i], mx);
	}
	cout << yes << ln;
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