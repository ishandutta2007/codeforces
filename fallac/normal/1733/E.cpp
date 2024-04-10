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

#define MAX 150
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

const int N = 120;

ll mp[MAX][MAX];
int nxt[MAX][MAX];
void add(int t) {
	int x, y;
	x = y = 0;
	while (t--) {
		if (x >= N || y >= N) return;
		if (nxt[x][y]) nxt[x][y] = 0, y++;
		else nxt[x][y] = 1, x++;
	}
	mp[x][y] = 1;
}

void solve() {
	int Q;
	cin >> Q;
	while (Q--) {
		int i, j;
		for (i = 0; i < N; i++) for (j = 0; j < N; j++) mp[i][j] = 0, nxt[i][j] = 1;
		ll T;
		int x, y;
		cin >> T >> x >> y;
		T++;
		if (T <= 260) {
			for (i = T - 1; i >= 0; i--) add(i);
			if (mp[x][y]) cout << yes << ln;
			else cout << no << ln;
			continue;
		}
		mp[0][0] = T - 250;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (mp[i][j] & 1) {
					mp[i + 1][j] += mp[i][j] / 2;
					mp[i][j + 1] += mp[i][j] / 2;
					if (nxt[i][j]) mp[i][j + 1]++;
					else mp[i + 1][j]++;
					nxt[i][j] ^= 1;
				}
				else {
					mp[i + 1][j] += mp[i][j] / 2;
					mp[i][j + 1] += mp[i][j] / 2;
				}
				mp[i][j] = 0;
			}
		}
		for (i = 249; i >= 0; i--) add(i);
		if (mp[x][y]) cout << yes << ln;
		else cout << no << ln;
	}
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