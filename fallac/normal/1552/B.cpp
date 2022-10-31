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

//#define vv vector
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
	vector<ll> v[5];
	v[0].resize(N + 1);
	v[1].resize(N + 1);
	v[2].resize(N + 1);
	v[3].resize(N + 1);
	v[4].resize(N + 1);
	ll i;
	for (i = 1; i <= N; i++) {
		cin >> v[0][i];
		cin >> v[1][i];
		cin >> v[2][i];
		cin >> v[3][i];
		cin >> v[4][i];
	}
	ll j;
	vector<ll> asdf;
	for (i = 1; i <= N; i++) asdf.push_back(i);
	while (1) {
		if (asdf.size() == 1) break;
		else {
			ll a = asdf.back();
			asdf.pop_back();
			ll b = asdf.back();
			asdf.pop_back();
			ll cnt = 0;
			for (i = 0; i < 5; i++) {
				if (v[i][a] < v[i][b]) cnt++;
			}
			if (cnt >= 3) asdf.push_back(a);
			else asdf.push_back(b);
		}
	}
	ll win = asdf[0];
	for (i = 1; i <= N; i++) {
		ll cnt = 0;
		for (j = 0; j < 5; j++) {
			if (v[j][i] < v[j][win]) cnt++;
		}
		if(cnt>=3){
			cout << -1 << ln;
			return;
		}
	}
	cout << win << ln;
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