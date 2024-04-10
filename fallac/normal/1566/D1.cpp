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
#define pll pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

vector<ll> adj[MAX];

bool cmp(pll a, pll b) {
	if (a.first != b.first) return a.first < b.first;
	else return a.second > b.second;
}

void solve() {
	ll N;
	cin >> N >> N;
	vector<pair<ll, ll>> v(N + 1);
	ll i;
	for (i = 1; i <= N; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	vector<ll> chk(N + 1);
	sort(v.begin(), v.end(), cmp);
	vector<ll> loc(N+1);
	for (i = 1; i <= N; i++) {
		loc[v[i].second] = i;
	}
	ll cnt = 0;
	for (i = 1; i <= N; i++) {
		for (ll j = 1; j < loc[i]; j++) if (chk[j]) cnt++;
		chk[loc[i]] = 1;
	}
	cout << cnt << ln;
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