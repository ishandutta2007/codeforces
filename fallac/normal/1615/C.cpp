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

void solve() {
	ll N;
	cin >> N;
	string a, b;
	cin >> a >> b;
	ll i;
	ll s0, s1;
	ll d0, d1;
	s0 = s1 = 0;
	d0 = d1 = 0;
	for (i = 0; i < N; i++) {
		if (a[i] == b[i]) {
			if (a[i] == '1') s1++;
			else s0++;
		}
		else {
			if (a[i] == '1') d1++;
			else d0++;
		}
	}
	if (s1 == s0 + 1 && d0 == d1) cout << min(s0 * 2 + 1, d0 * 2) << Ln;
	else if (s1 == s0 + 1) cout << s0 * 2 + 1 << ln;
	else if (d0 == d1) cout << d0 * 2 << Ln;
	else cout << -1 << ln;
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