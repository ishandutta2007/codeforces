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
	ll N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	if (N == 1) {
		ll i;
		for (i = 1; i <= K; i++) {
			cout << s[0];
		}
		cout << ln;
		return;
	}
	ll i;
	ll p1, p2;
	p1 = 0;
	p2 = 1;
	cout << s[0];
	for (i = 2; i <= K; i++) {
		if (s[p1] == s[p2]) {
			cout << s[p1];
			p1++;
			p2++;
			if (p2 >= N) p2 -= N;
		}
		else if (s[p1] < s[p2]) {
			cout << s[p1];
			p2 = p1;
			p2++;
			p1 = 0;
			if (p2 >= N) p2 -= N;
		}
		else {
			cout << s[p2];
			p2++;
			p1 = 0;
			if (p2 >= N) p2 -= N;
		}
	}
	cout << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}