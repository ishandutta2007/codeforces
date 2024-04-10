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
typedef pair<int, int> pii;

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
	int N;
	cin >> N;
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int a, b;
	cin >> a >> b;
	int p, q;
	if (x1 == x2) p = x1;
	if (x2 == x3) p = x2;
	if (x3 == x1) p = x3;
	if (y1 == y2) q = y1;
	if (y2 == y3) q = y2;
	if (y3 == y1) q = y3;
	if ((p == 1 || p == N) && (q == 1 || q == N)) {
		if (a == p || b == q) cout << yes << ln;
		else cout << no << ln;
		return;
	}
	x1 &= 1;
	y1 &= 1;
	x2 &= 1;
	y2 &= 1;
	x3 &= 1;
	y3 &= 1;
	a &= 1;
	b &= 1;
	p &= 1;
	q &= 1;
	if ((a ^ p) && (b ^ q)) cout << no << ln;
	else cout << yes << ln;
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