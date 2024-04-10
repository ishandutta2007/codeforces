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

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var
pair<pair<ll, ll>, ll> v[MAX];
//

void solve() {
	ll N;
	cin >> N;
	ll i;
	ll sum = 0;
	for (i = 1; i <= N; i++) {
		cin >> v[i].first.first >> v[i].first.second;
		sum += v[i].first.second;
		v[i].second = i;
	}
	sort(v + 1, v + N + 1);
	priority_queue<ll> pq;
	pq.push(v[1].first.first + v[1].first.second);
	ll ptr = 1;
	ll cst = 0;
	while (ptr < N) {
		ll t = pq.top();
		if (v[ptr + 1].first.first <= t) pq.push(v[ptr + 1].first.first + v[ptr + 1].first.second);
		else {
			cst += v[ptr + 1].first.first - t;
			pq.push(v[ptr + 1].first.first + v[ptr + 1].first.second);
		}
		ptr++;
	}
	cout << sum + cst << ln;
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