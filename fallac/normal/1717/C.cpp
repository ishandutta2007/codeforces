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

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int A[MAX];
int B[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++) cin >> A[i];
	for (i = 0; i < N; i++) cin >> B[i];
	for (i = 0; i < N; i++) {
		int ne = (i + 1) % N;
		if (A[i] > B[i]) {
			cout << no << ln;
			return;
		}
		if (A[i] < B[i]) {
			if (B[i] > B[ne] + 1) {
				cout << no << ln;
				return;
			}
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