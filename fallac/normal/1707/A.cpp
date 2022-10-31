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

int arr[MAX];

void solve() {
	int N, Q;
	cin >> N >> Q;
	int i;
	for (i = 1; i <= N; i++) cin >> arr[i];
	int sum = 0;
	for (i = N; i >= 1; i--) {
		if (sum < arr[i] || sum == 0) sum++;
		if (sum > Q) break;
	}
	int k = i + 1;
	for (i = 1; i < k; i++) {
		if (Q >= arr[i]) cout << 1;
		else cout << 0;
	}
	for (i = k; i <= N; i++) cout << 1;
	cout << ln;
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