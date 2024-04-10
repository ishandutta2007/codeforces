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
	int N;
	cin >> N;
	int i, x;
	set<int> st;
	int c = 0;
	for (i = 1; i <= N; i++) {
		cin >> x;
		st.insert(x);
		if (x == 1) c = 1;
	}
	if (!c) {
		cout << yes << ln;
		return;
	}
	else {
		for (auto v : st) {
			if (st.find(v + 1) != st.end()) {
				cout << no << ln;
				return;
			}
		}
		cout << yes << ln;
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