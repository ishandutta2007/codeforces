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
	string s;
	cin >> s;
	ll N = s.size();
	ll i;
	ll x = 0;
	for (i = 1; i < N; i++) {
		if ((s[i] - '0' + s[i - 1] - '0') >= 10) x = 1;
	}
	if (x) {
		for (i = N - 1; i >= 1; i--) {
			if ((s[i] - '0' + s[i - 1] - '0') >= 10) break;
		}
		ll k = i;
		for (i = 0; i < k - 1; i++) cout << s[i];
		cout << (s[k] - '0' + s[k - 1] - '0');
		for (i = k + 1; i < N; i++) cout << s[i];
		cout << Ln;
	}
	else {
		s[1] += s[0] - '0';
		for (i = 1; i < N; i++) cout << s[i];
		cout << Ln;
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