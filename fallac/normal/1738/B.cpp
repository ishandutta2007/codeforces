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

ll A[MAX];

void solve() {
	int N, K;
	cin >> N >> K;
	int i;
	for (i = 1; i <= K; i++) cin >> A[i];
	for (i = K; i >= 1; i--) A[i] -= A[i - 1];
	if (K == 1) {
		cout << yes << ln;
		return;
	}
	for (i = 3; i <= K; i++) if (A[i] < A[i - 1]) {
		cout << no << ln;
		return;
	}
	ll S = A[1];
	ll X = N - K + 1;
	if (1ll * A[2] * X < S) {
		cout << no << Ln;
		return;
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