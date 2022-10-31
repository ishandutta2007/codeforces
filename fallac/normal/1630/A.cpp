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
	ll N, K;
	cin >> N >> K;
	ll i;
	if (K == N - 1) {
		if (N == 4) {
			cout << -1 << ln;
			return;
		}
		else {
			cout << N - 2 << bb << N - 1 << Ln;
			cout << 1 << bb << N / 2 - 1 << ln;
			for (i = 2; i < N / 2 - 1; i++) cout << i << bb << N - i - 1 << ln;
			cout << 0 << bb << N / 2 << ln;
			return;
		}
	}
	if (K >= N / 2) {
		cout << 0 << bb << (N - 1 - K) << ln;
		for (i = 1; i < N / 2; i++) {
			if (i == N - 1 - K) cout << K << bb << N - 1 << ln;
			else cout << i << bb << N - 1 - i << ln;
		}
	}
	else if (K) {
		cout << 0 << bb << (N - K - 1) << ln;
		for (i = 1; i < N / 2; i++) {
			if (i == K) cout << i << bb << N - 1 << ln;
			else cout << i << bb << N - 1 - i << ln;
		}
	}
	else {
		for (i = 0; i < N / 2; i++) cout << i << bb << N - 1 - i << Ln;
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