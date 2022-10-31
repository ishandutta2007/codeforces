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
	vector<ll> v;
	ll a;
	ll cnt = 0;
	for (i = 1; i <= N; i++) {
		cin >> a;
		v.push_back(a & 1);
		if (a & 1) cnt++;
	}
	if (N % 2 == 0 && cnt != N / 2) {
		cout << -1 << ln;
		return;
	}
	if (N % 2 && (cnt != N / 2) && cnt != (N / 2 + 1)) {
		cout << -1 << ln;
		return;
	}
	if (N % 2 && cnt == N / 2) {
		ll ans = 0;
		ll cnt = 0;
		for (i = 0; i < N; i++) {
			if (v[i]) ans += abs(i - cnt * 2 - 1), cnt++;
		}
		cout << ans << Ln;
	}
	else if (N % 2 && cnt == (N / 2 + 1)) {
		ll ans = 0;
		ll cnt = 0;
		for (i = 0; i < N; i++) {
			if (v[i]) ans += abs(i - cnt * 2), cnt++;
		}
		cout << ans << Ln;
	}
	else {
		ll asdf = 0;
		ll ans = 0;
		ll cnt = 0;
		for (i = 0; i < N; i++) {
			if (v[i]) ans += abs(i - cnt * 2), cnt++;
		}
		asdf = ans;
		ans = 0;
		cnt = 0;
		for (i = 0; i < N; i++) {
			if (v[i]) ans += abs(i - cnt * 2 - 1), cnt++;
		}
		asdf = min(asdf, ans);
		cout << asdf << Ln;
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