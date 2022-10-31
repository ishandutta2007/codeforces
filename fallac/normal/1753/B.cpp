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

#define MAX 501010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int arr[MAX];

void solve() {
	int N, X;
	cin >> N >> X;
	int i;
	for (i = 1; i <= X; i++) arr[i] = 0;
	int a;
	for (i = 1; i <= N; i++) cin >> a, arr[a]++;
	int c = 0;
	for (i = 1; i <= X; i++) {
		int k = i + 1;
		arr[i + 1] += arr[i] / k;
		arr[i] %= k;
		if (i < X && arr[i]) c = 1;
	}
	if (c) cout << "No" << ln;
	else cout << "Yes" << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}