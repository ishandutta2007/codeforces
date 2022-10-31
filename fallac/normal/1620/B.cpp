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
	ll a, b, c, d;
	ll W, H;
	cin >> W >> H;
	ll i;
	ll k;
	ll p, q;
	
	cin >> k;
	cin >> p;
	for (i = 1; i < k; i++) cin >> q;
	a = q - p;
	cin >> k;
	cin >> p;
	for (i = 1; i < k; i++) cin >> q;
	b = q - p;
	cin >> k;
	cin >> p;
	for (i = 1; i < k; i++) cin >> q;
	c = q - p;
	cin >> k;
	cin >> p;
	for (i = 1; i < k; i++) cin >> q;
	d = q - p;

	cout << max(H * max(a, b), W * max(c, d)) << ln;
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