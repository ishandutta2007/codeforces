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
	ll N, X;
	cin >> N >> X;
	ll i;
	multiset<ll> ms;
	ll a;
	for (i = 1; i <= N; i++) cin >> a, ms.insert(a);
	ll cnt = 0;
	while (ms.size()) {
		a = *ms.begin();
		if (ms.count(a * X)) {
			ms.erase(ms.find(a));
			ms.erase(ms.find(a * X));
		}
		else {
			ms.erase(ms.find(a));
			cnt++;
		}
	}
	cout << cnt << ln;
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