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
#define Ln '\n'

#define MAX 101010
#define MOD 998244353
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

ll sq(ll x) {
	return x * x;
}

void solve() {
	ll N, M, K;
	cin >> N >> M >> K;
	ll i;
	vector<ll> x, y;
	ll a;
	for (i = 1; i <= N; i++) cin >> a, x.push_back(a);
	for (i = 1; i <= M; i++) cin >> a, y.push_back(a);
	vector<pll> xarr, yarr;
	ll b;
	for (i = 1; i <= K; i++) {
		cin >> a >> b;
		ll xind = lower_bound(x.begin(), x.end(), a) - x.begin();
		ll yind = lower_bound(y.begin(), y.end(), b) - y.begin();
		if ((xind < x.size() && x[xind] == a) && (yind < y.size() && y[yind] == b)) continue;
		if (xind < x.size() && x[xind] == a) yarr.emplace_back(yind, xind);
		else xarr.emplace_back(xind, yind);
	}
	if(xarr.size()) sort(xarr.begin(), xarr.end());
	if(yarr.size()) sort(yarr.begin(), yarr.end());
	vector<ll> v(max(N, M) + 3);
	//xarr
	ll ans = 0;
	ll sum = 0;
	ll sqs = 0;
	ll j = 0;
	ll pv;
	for (i = 0; i <= N; i++) {
		pv = j;
		for (; j < xarr.size(); j++) {
			if (xarr[j].first >= i) break;
			v[xarr[j].second]++;
			sum++;
			sqs += sq(v[xarr[j].second]) - sq(v[xarr[j].second] - 1);
		}
		ans += (sq(sum) - sqs) / 2;
		ll k;
		for (k = pv; k < j; k++) v[xarr[k].second] = 0;
		sum = sqs = 0;
	}
	pv = j = 0;
	for (i = 0; i <= M; i++) {
		pv = j;
		for (; j < yarr.size(); j++) {
			if (yarr[j].first >= i) break;
			v[yarr[j].second]++;
			sum++;
			sqs += sq(v[yarr[j].second]) - sq(v[yarr[j].second] - 1);
		}
		ans += (sq(sum) - sqs) / 2;
		ll k;
		for (k = pv; k < j; k++) v[yarr[k].second] = 0;
		sum = sqs = 0;
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