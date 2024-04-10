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

#define MAX 1010100
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
	vector<vector<int>> mp(N, vector<int>(M));
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) cin >> mp[i][j];
	int ccnt = 0;
	int v = 0;
	for (i = 1; i < N; i++) {
		vector<int> vpi(M);
		ll l, r;
		l = r = 0;
		for (j = 0; j < M; j++) vpi[j] = mp[i][j] - mp[0][j];
		for (j = 0; j < M; j++) {
			if (vpi[j] > 0) l += abs(vpi[j]);
			if (vpi[j] < 0) r += abs(vpi[j]);
			if (j < M - 1) vpi[j + 1] += vpi[j];
		}
		if (l != r) ccnt++, v = i;
	}
	if (ccnt != 1) swap(mp[0], mp[1]), v = 1;
	for (i = v; i <= v; i++) {
		vector<int> vpi(M);
		ll l, r;
		l = r = 0;
		for (j = 0; j < M; j++) vpi[j] = mp[i][j] - mp[0][j];
		for (j = 0; j < M; j++) {
			if (vpi[j] > 0) l += abs(vpi[j]);
			if (vpi[j] < 0) r += abs(vpi[j]);
			if (j < M - 1) vpi[j + 1] += vpi[j];
		}
		if (l != r) {
			if (ccnt != 1) cout << 1 << bb << r - l << ln;
			else cout << v + 1 << bb << r - l << ln;
			return;
		}
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