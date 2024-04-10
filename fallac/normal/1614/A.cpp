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
	ll N, L, R, K;
	cin >> N >> L >> R >> K;
	ll i, a;
	vector<ll> v;
	for (i = 1; i <= N; i++) {
		cin >> a;
		if (a >= L && a <= R) v.push_back(a);
	}
	sort(v.begin(), v.end());
	ll sum = 0;
	for (i = 0; i < v.size(); i++) {
		if (sum + v[i] <= K) sum += v[i];
		else break;
	}
	cout << i << ln;
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