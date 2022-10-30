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
	ll N;
	cin >> N;
	ll i;
	vector<ll> a(N + 1);
	for (i = 1; i <= N; i++) cin >> a[i];
	vector<ll> b(N + 1);
	for (i = 1; i <= N; i++) cin >> b[i];
	vector<ll> A(300);
	vector<ll> B(300);
	for (i = 1; i <= N; i++) A[a[i] + 101]++;
	for (i = 1; i <= N; i++) B[b[i] + 101]++;
	for (i = 299; i >= 1; i--) {
		if (B[i] && A[i]) {
			ll m = min(B[i], A[i]);
			A[i] -= m;
			B[i] -= m;
		}
		if (B[i] && A[i - 1]) {
			ll m = min(B[i], A[i - 1]);
			A[i - 1] -= m;
			B[i] -= m;
		}
	}
	for (i = 0; i < 300; i++) {
		if (A[i] || B[i]) {
			cout << no << ln;
			return;
		}
	}
	cout << yes << ln;
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