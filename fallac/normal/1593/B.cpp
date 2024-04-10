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
	string s;
	cin >> s;
	ll N = s.size();
	ll i, j;
	ll ans = INF;
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (s[i] == '0' && s[j] == '0') ans = min(ans, N - i - 2);
			if (s[i] == '2' && s[j] == '5') ans = min(ans, N - i - 2);
			if (s[i] == '5' && s[j] == '0') ans = min(ans, N - i - 2);
			if (s[i] == '7' && s[j] == '5') ans = min(ans, N - i - 2);
		}
	}
	cout << ans << Ln;
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