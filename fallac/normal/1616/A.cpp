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

//var

//

void solve() {
	ll N;
	vector<ll> v(300); //300iq
	cin >> N;
	ll i;
	ll a;
	for (i = 1; i <= N; i++) {
		cin >> a;
		a = abs(a);
		v[a + 100]++;
		v[a + 100] = min(v[a + 100], (ll)2);
	}
	ll ans = 0;
	for (i = 0; i < 300; i++) {
		if (i == 100) v[i] = min(v[i], 1LL);
		ans += v[i];
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