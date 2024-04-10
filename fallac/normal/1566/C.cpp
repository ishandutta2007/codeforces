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
	string s1, s2;
	cin >> s1 >> s2;
	vector<ll> v(N);
	for (i = 0; i < N; i++) {
		v[i] = s1[i] + s2[i] - 2 * '0';
	}
	ll prev = -1;
	ll ans = 0;
	for (i = 0; i < N; i++) {
		if (v[i] == 2) {
			if (prev == 0) {
				ans++;
				prev = -1;
			}
			else prev = 2;
		}
		else if (v[i] == 1) {
			ans += 2;
			prev = -1;
		}
		else {
			ans++;
			if (prev == 2) {
				prev = -1;
				ans++;
			}
			else {
				prev = 0;
			}
		}
	}
	cout << ans << ln;
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