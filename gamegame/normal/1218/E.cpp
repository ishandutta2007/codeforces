// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;
const int N = (int) 1 << 15, mod = (int) 998244353;
int a[N], b[N], dp[N];
int pw(int a, int b) { return b != 0? (LL) pw((LL) a * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }
void NTT(int a[], int lg, bool inverse) {
	int N = 1 << lg;
	for (int i = 0; i < N; ++i) {
		int rev = 0;
		for (int j = 0; j < lg; ++j)
			if (i >> j & 1)
				rev |= 1 << (lg - j - 1);
		if (rev > i)
			swap(a[rev], a[i]);
	}
	for (int len = 2; len <= N; len <<= 1) {
		int wn = pw(3, (mod - 1) / len);
		if (inverse)
			wn = pw(wn, mod - 2);
		for (int j = 0; j < N; j += len) {
			int w = 1;
			for (int x = j, y = j + len / 2; y < j + len; ++x, ++y) {
				int u = a[x], v = (LL) a[y] * w % mod;
				a[x] = u + v; 
				a[y] = u - v + mod;
				while (a[x] >= mod)
					a[x] -= mod;
				while (a[y] >= mod)
					a[y] -= mod;
				w = (LL) w * wn % mod;
			}
		}
	}
	if (inverse) {
		int div = pw(N, mod - 2);
		for (int i = 0; i < N; ++i)
			a[i] = (LL) a[i] * div % mod;
	}
}
int res[17][N], tmpa[17][N], tmpb[17][N];
void solve(int b, int e, int a[N], int d = 0) {
	if (b + 1 == e) {
		res[d][0] = 1;
		res[d][1] = a[b];
		return;
	}
	int m = b + e >> 1;
	solve(b, m, a, d + 1);
	for (int j = 0; j <= (m - b); ++j) tmpa[d][j] = res[d + 1][j], res[d + 1][j] = 0;
	solve(m, e, a, d + 1);
	for (int j = 0; j <= (e - m); ++j) tmpb[d][j] = res[d + 1][j], res[d + 1][j] = 0;
	int lg = 0;
	while ((1 << lg) <= e - b) ++lg;
	NTT(tmpa[d], lg, false);
	NTT(tmpb[d], lg, false);
	for (int j = 0; j < (1 << lg); ++j) res[d][j] = (LL) tmpa[d][j] * tmpb[d][j] % mod, tmpa[d][j] = tmpb[d][j] = 0;
	NTT(res[d], lg, true);
}
int32_t main() {
	int n, k;
	cin >> n >> k;
	for (int j = 0; j < n; ++j) cin >> a[j];
	int qm;
	cin >> qm;
	while (qm--) {
		int c;
		cin >> c;
		if (c == 1) {
			int q, p, d;
			cin >> q >> p >> d;
			--p;
			for (int j = 0; j < n; ++j)
				b[j] = q - a[j];
			b[p] = q - d; 
		} else {
			int q, l, r, d;
			cin >> q >> l >> r >> d;
			--l;
			for (int j = 0; j < n; ++j)
				b[j] = q - a[j];
			for (int j = l; j < r; ++j)
				b[j] -= d;
		}
		for (int j = 0; j < n; ++j) b[j] = (b[j] % mod + mod) % mod;
		memset(res, 0, sizeof res);
		solve(0, n, b);
		cout << res[0][k] << '\n';
	}
}