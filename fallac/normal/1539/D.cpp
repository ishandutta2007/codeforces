/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

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

//

void solve() {

}

void init() {
	ll N;
	cin >> N;
	ll i;
	ll a, b;
	vector<pll> v;
	for (i = 1; i <= N; i++) {
		cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(v.begin(), v.end());
	ll p1, p2;
	p1 = 0, p2 = N - 1;
	ll cnt = 0;
	ll ans = 0;
	while (p1 <= p2) {
		if (p2 < 0) break;
		if (p1 >= N) break;
		if (v[p1].second <= 0) p1++;
		if (v[p2].second <= 0) p2--;
		if (cnt >= v[p1].first) ans += v[p1].second, cnt += v[p1].second, p1++;
		else {
			if (cnt + v[p2].second > v[p1].first) {
				ll num = v[p1].first - cnt;
				ans += num * 2;
				cnt += num;
				v[p2].second -= num;
			}
			else {
				ans += 2 * v[p2].second, cnt += v[p2].second, p2--;
			}
		}
	}
	cout << ans << ln;
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