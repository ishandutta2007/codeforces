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

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int arr[MAX];

void solve() {
	int N;
	int i;
	cin >> N;
	int f = N + 1;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] > 0 && f == N + 1) f = i;
	}
	ll cnt = 0;
	for (i = f; i < N; i++) if (arr[i] == 0) cnt++;
	for (i = 1; i < N; i++) cnt += (ll)arr[i];
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