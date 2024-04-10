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
	int i;
	vector<int> v;
	int a;
	for (i = 1; i <= N; i++) {
		cin >> a;
		v.push_back(a);
	}
	int mn = N * 2;
	int mx = -1;
	for (i = 1; i < N; i++) {
		if (v[i] == v[i - 1]) mx = max(mx, i), mn = min(mn, i - 1);
	}
	if (mx == -1) cout << 0 << ln;
	else {
		int sz = mx - mn + 1;
		if (sz == 2) cout << 0 << ln;
		else if (sz == 3) {
			if (v[mn] == v[mn + 1] && v[mn + 1] == v[mn + 2]) cout << 1 << ln;
			else cout << 0 << ln;
		}
		else cout << sz - 3 << ln;
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