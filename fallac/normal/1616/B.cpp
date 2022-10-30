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
	cin >> N >> s;
	ll i;
	vector<ll> v(N);
	for (i = 2; i < N; i++) {
		if (s[i] < s[i - 2]) v[i] = 1;
		else if (s[i] == s[i - 2]) v[i] = v[i - 1];
	}
	for (i = 1; i < N; i++) {
		if (s[i] < s[i - 1]) continue;
		else if (s[i] > s[i - 1]) break;
		else {
			if (v[i]) continue;
			else break;
		}
	}
	i--;
	ll a = i;
	for (i = 0; i <= a; i++) cout << s[i];
	for (i = a; i >= 0; i--) cout << s[i];
	cout << ln;
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