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

vector<ll> asdf;

void solve() {
	ll N;
	cin >> N;
	ll i;
	if (N <= 26) {
		for (i = 0; i < N; i++) cout << char(i + 'a');
		cout << ln;
		return;
	}
	if (N % 2) {
		N -= 2;
		N /= 2;
		for (i = 1; i <= N; i++) cout << 'a';
		cout << "bc";
		for (i = 1; i <= N + 1; i++) cout << 'a';
		cout << ln;
	}
	else {
		N -= 2;
		N /= 2;
		for (i = 1; i <= N; i++) cout << 'a';
		cout << 'b';
		for (i = 1; i <= N + 1; i++) cout << 'a';
		cout << ln;
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