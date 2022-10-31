/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'

#define MAX 101010
#define MOD 100000009
#define INF 10000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

ll gcd(ll a, ll b) {
	while (b) b %= a ^= b ^= a ^= b;
	return a;
}

void solve() {
	ll N;
	cin >> N;
	string s;
	cin >> s;
	ll i;
	vector<ll> v, z, o;
	map<pair<ll, ll>, ll> mp;
	v.resize(N + 1);
	z.resize(N + 1);
	o.resize(N + 1);
	for (i = 1; i <= N; i++) v[i] = s[i - 1] == 'D' ? 1 : 0;
	for (i = 1; i <= N; i++) {
		o[i] = o[i - 1];
		z[i] = z[i - 1];
		if (v[i] == 1) o[i]++;
		else z[i]++;
	}
	for (i = 1; i <= N; i++) {
		ll zz, oo;
		zz = z[i];
		oo = o[i];
		if (!(zz && oo)) {
			if (zz) zz = 1;
			if (oo) oo = 1;
		}
		else {
			ll g = gcd(zz, oo);
			zz /= g;
			oo /= g;
		}
		cout << (1 + (mp[make_pair(zz, oo)]++)) << ln;
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