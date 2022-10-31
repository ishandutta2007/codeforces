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
#define MOD 100000009
#define INF 1000000000000

//#define vv vector
#define pq priority_queue
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll N, K;
	cin >> N >> K;
	ll i;
	ll a, b;
	vector<ll> chk;
	vector<pll> p;
	chk.resize(2 * N + 1);
	for (i = 1; i <= K; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		chk[a] = chk[b] = 1;
		p.push_back({ a, b });
	}
	vector<ll> r;
	for (i = 1; i <= 2 * N; i++) {
		if (!chk[i]) r.push_back(i);
	}
	ll R = r.size();
	for (i = 0; i < R / 2; i++) {
		p.push_back({ r[i], r[i + R / 2] });
	}
	sort(p.begin(), p.end());
	ll sum = 0;
	ll j;
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (p[j].first<p[i].second && p[j].second>p[i].second) sum++;
		}
	}
	cout << sum << ln;
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