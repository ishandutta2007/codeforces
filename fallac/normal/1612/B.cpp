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
	ll a, b;
	cin >> N >> a >> b;
	vector<ll> v;
	ll i;
	ll k = N;
	vector<ll> chk(N + 1);
	v.push_back(a);
	chk[a] = 1;
	chk[b] = 1;
	for (i = 1; i <= N / 2 - 1; i++) {
		if (!chk[k]) chk[k] = 1, v.push_back(k);
		else i--;
		k--;
	}
	for (i = 1; i <= N; i++) {
		if (!chk[i]) chk[i] = 1, v.push_back(i);
	}
	v.push_back(b);
	for (i = 0; i < N / 2; i++) {
		if (v[i] < a) {
			cout << -1 << ln;
			return;
		}
	}
	for (; i < N; i++) {
		if (v[i] > b) {
			cout << -1 << ln;
			return;
		}
	}
	for (i = 0; i < N; i++) cout << v[i] << ln;
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