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

//var

//

void solve() {
	int N, X, Y;
	cin >> N >> X >> Y;
	if (X > Y) swap(X, Y);
	if (X) {
		cout << -1 << Ln;
		return;
	}
	if (!Y) {
		cout << -1 << ln;
		return;
	}
	if ((N - 1) % Y) {
		cout << -1 << Ln;
		return;
	}
	int i, j;
	j = 0;
	int pv = 1;
	int f = 1;
	for (i = 1; i < N; i++) {
		cout << pv << bb;
		j++;
		if (j == Y) {
			j = 0;
			pv += Y;
			pv += f;
			f = 0;
		}
	}
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