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
	set<ll> ee;
	vector<vector<ll>> arr(N + 1), rev(N + 1);
	vector<ll> cnt(N + 1);
	ll a, j;
	for (i = 1; i <= N; i++) {
		cin >> a;
		ll k;
		for (j = 1; j <= a; j++) {
			cin >> k;
			arr[i].push_back(k);
			rev[k].push_back(i);
		}
		cnt[i] = a;
		if (!a) ee.insert(i);
	}
	ll ccnt = 0;
	vector<ll> nn;
	ll ans = 0;
	while (1) {
		ans++;
		nn.clear();
		while (ee.size()) {
			ccnt++;
			ll t = *ee.begin();
			ee.erase(*ee.begin());
			for (auto x : rev[t]) {
				cnt[x]--;
				if (cnt[x] == 0) {
					if (t < x) ee.insert(x);
					else nn.push_back(x);
				}
			}
		}
		if (ccnt == N) {
			cout << ans << ln;
			return;
		}
		for (auto v : nn) ee.insert(v);
		if (ee.empty()) {
			cout << -1 << ln;
			return;
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