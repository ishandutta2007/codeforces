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
	string s;
	cin >> s;
	vector<ll> v(26);
	ll i;
	for (i = 0; i < s.size(); i++) v[s[i] - 'a']++;
	string t;
	cin >> t;
	if (t[0] < t[1] && t[1] < t[2]) {
		if (v[t[0] - 'a'] && v[t[1] - 'a'] && v[t[2] - 'a']) {
			ll i;
			for (i = 0; i < 26; i++) {
				ll a = i;
				if (t[1] - 'a' == i) a = t[2] - 'a';
				if (t[1] - 'a' < i && i <= t[2] - 'a') a = t[1] - 'a';
				for (ll j = 0; j < v[a]; j++) {
					cout << (char)(a + 'a');
				}
			}
			cout << ln;
			return;
		}
	}
	for (i = 0; i < 26; i++) {
		ll a = i;
		for (ll j = 0; j < v[i]; j++) {
			cout << (char)(a + 'a');
		}
	}
	cout << Ln;
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