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
#define MOD 1000000007
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
	char c;
	cin >> N >> c;
	string s;
	cin >> s;
	ll i;
	vector<ll> v;
	for (i = 0; i < N; i++) {
		if (s[i] != c) v.push_back(i);
	}
	if (v.empty()) {
		cout << 0 << ln;
		return;
	}
	else {
		if (s[N - 1] == c) {
			cout << 1 << ln << N << ln;
			return;
		}
		else {
			ll i;
			for (i = N - 1; i >= 0; i--) {
				if (s[i] == c) break;
			}
			i++;
			if (i >= (N + 2) / 2) {
				cout << 1 << ln;
				cout << i << ln;
			}
			else {
				cout << 2 << ln;
				cout << N << bb << N - 1 << ln;
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