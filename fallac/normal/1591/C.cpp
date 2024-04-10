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
#define INF 100000000000000

#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll N, K;
	cin >> N >> K;
	ll i;
	ll A, B;
	vector<ll> v1, v2;
	for (i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		if (a) {
			if (a > 0) v1.push_back(a);
			else v2.push_back(-a);
		}
	}
	if (v1.size()) sort(v1.begin(), v1.end());
	if (v2.size()) sort(v2.begin(), v2.end());
	A = v1.size();
	B = v2.size();
	ll a1, a2, b1, b2;
	a1 = a2 = b1 = b2 = 0;
	vector<ll> c;
	if (v1.size()) {
		c = v1;
		while (v1.size()) {
			a1 += v1.back() * 2;
			for (i = 1; i <= K; i++) if (v1.size()) v1.pop_back();
		}
		v1 = c;
		a2 = v1.back();
		for (i = 1; i <= K; i++) if (v1.size()) v1.pop_back();
		while (v1.size()) {
			a2 += v1.back() * 2;
			for (i = 1; i <= K; i++) if (v1.size()) v1.pop_back();
		}
	}
	if (v2.size()) {
		c = v2;
		while (v2.size()) {
			b1 += v2.back() * 2;
			for (i = 1; i <= K; i++) if (v2.size()) v2.pop_back();
		}
		v2 = c;
		b2 = v2.back();
		for (i = 1; i <= K; i++) if (v2.size()) v2.pop_back();
		while (v2.size()) {
			b2 += v2.back() * 2;
			for (i = 1; i <= K; i++) if (v2.size()) v2.pop_back();
		}
	}
	cout << min(a1 + b2, a2 + b1) << ln;
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