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
	vector<ll> v1, v2;
	ll a;
	ll s1, s2;
	s1 = s2 = 0;
	for (i = 1; i <= N; i++) cin >> a, v1.push_back(a), s1 += a;
	for (i = 1; i <= N; i++) cin >> a, v2.push_back(a), s2 += a;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	ll num = N / 4;
	for (i = 0; i < num; i++) s1 -= v1[i];
	for (i = 0; i < num; i++) s2 -= v2[i];
	ll cnt = 0;
	ll ptr = num;
	while (1) {
		if (s1 >= s2) break;
		s1 += 100;
		N++;
		cnt++;
		if (!(N % 4)) num++, s1 -= v1[num - 1];
		if ((N % 4) && ptr > 0) ptr--, s2 += v2[ptr];
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