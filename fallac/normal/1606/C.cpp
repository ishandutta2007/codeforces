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
	ll N, K;
	cin >> N >> K;
	ll i;
	vector<ll> v(N), ans(N);
	for (i = 0; i < N; i++) cin >> v[i];
	vector<ll> arr;
	K++;
	v.push_back(18);
	for (i = 0; i < N; i++) {
		ll d = v[i + 1] - v[i];
		ll j;
		ll x = 10;
		for (j = 1; j < d; j++) x *= 10;
		x -= 1;
		if (x >= K) {
			cout << K;
			ll j;
			for (j = i - 1; j >= 0; j--) {
				cout << ans[j];
			}
			cout << ln;
			return;
		}
		else ans[i] = x, K -= x;
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