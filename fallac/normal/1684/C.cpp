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

void solve() {
	int N, M;
	cin >> N >> M;
	int i, j;
	vector<int> swapchk(M);
	vector<vector<int>> mp(N, vector<int>(M));
	for (i = 0; i < N; i++) {
		vector<int> arr, cpy;
		int a;
		for (j = 0; j < M; j++) {
			cin >> a;
			mp[i][j] = a;
			arr.push_back(a);
			cpy.push_back(a);
		}
		sort(arr.begin(), arr.end());
		for (j = 0; j < M; j++) if (arr[j] != cpy[j]) swapchk[j] = 1;
	}
	int cnt = 0;
	int a, b;
	a = b = -1;
	for (j = 0; j < M; j++) cnt += swapchk[j];
	if (cnt > 2) {
		cout << -1 << ln;
		return;
	}
	if (cnt == 0) {
		cout << 1 << bb << 1 << ln;
		return;
	}
	for (j = 0; j < M; j++) {
		if (swapchk[j] && a == -1) a = j;
		else if (swapchk[j]) b = j;
	}
	for (i = 0; i < N; i++) swap(mp[i][a], mp[i][b]);
	for (i = 0; i < N; i++) {
		for (j = 1; j < M; j++) {
			if (mp[i][j - 1] > mp[i][j]) {
				cout << -1 << ln;
				return;
			}
		}
	}
	a++; b++;
	cout << a << bb << b << ln;
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