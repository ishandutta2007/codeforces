/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	ll N, M;
	N = s1.size();
	M = s2.size();
	ll i, j;
	vector<vector<ll>> arr;
	arr.resize(N);
	for (i = 0; i < N; i++) arr[i].resize(M);
	for (i = 0; i < N; i++) if (s1[i] == s2[0]) arr[i][0] = 1;
	for (j = 1; j < M; j++) {
		for (i = 0; i < N; i++) {
			if (s1[i] == s2[j]) {
				bool c = false;
				if (i != 0) {
					if (arr[i - 1][j - 1]) c = true;
				}
				if (c) arr[i][j] = 1;
			}
		}
	}
	for (j = 1; j < M; j++) {
		for (i = 0; i < N; i++) {
			if (s1[i] == s2[j]) {
				bool c = false;
				if (i != N - 1) {
					if (arr[i + 1][j - 1]) c = true;
				}
				if (c) arr[i][j] = 1;
			}
		}
	}
	bool c = false;
	for (i = 0; i < N; i++) if (arr[i][M - 1]) c = 1;
	if (c) cout << yes << ln;
	else cout << no << ln;
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