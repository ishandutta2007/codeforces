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
	int M;
	int ma, mb;
	ma = mb = 0;
	cin >> N;
	int i, a;
	for (i = 1; i <= N; i++)cin >> a, ma = max(ma, a);
	cin >> M;
	for (i = 1; i <= M; i++)cin >> a, mb = max(mb, a);
	if (ma == mb) {
		cout << "Alice" << ln;
		cout << "Bob" << Ln;
	}
	else if (ma < mb) {
		cout << "Bob" << ln;
		cout << "Bob" << ln;
	}
	else {
		cout << "Alice" << Ln;
		cout << "Alice" << Ln;
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