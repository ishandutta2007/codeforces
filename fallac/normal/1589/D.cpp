/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

map<pair<ll, ll>, ll> mp;
ll cnt;

ll query(ll x, ll y) {
	if (mp[{x, y}]) return mp[{x, y}];
	cnt++;
	assert(cnt <= 40);
	cout << '?' << bb << x << bb << y << endl;
	ll a;
	cin >> a;
	mp[{x, y}] = a;
	return a;
}

void solve() {
	mp.clear();
	cnt = 0;
	ll N;
	cin >> N;
	ll l, r;
	ll mid;
	l = 1;
	r = N + 1;
	ll tot;
	tot = query(1, N);
	while (r - l > 1) {
		mid = (l + r) / 2;
		ll x;
		x = query(1, mid);
		if (tot == x) r = mid;
		else l = mid;
	}
	ll i, j, k;
	k = r;
	ll x;
	x = query(1, k - 1);
	j = k - (tot - x);
	ll sz = k - j + 1;
	ll left = tot - (sz * (sz - 1) / 2);
	left *= 2;
	ll a = sqrt(left);
	left /= 2;
	i = max((ll)2, a - 10);
	while (1) {
		if (i * (i - 1) / 2 == left) break;
		i++;
	}
	ll lsz = i;
	i = j - lsz;
	cout << '!' << bb << i << bb << j << bb << k << endl;
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