/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 3625;
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}



int mul(int a, int b) {
	return (1LL * a * b) % Mod;
}



int w, h, n;
bool bad[MAXN];
bool bads[MAXN];
int dp[MAXN][MAXN], dp1[MAXN][MAXN];
int c[MAXN][MAXN];
int fact[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> h >> w >> n;
	fact[0] = 1;
	for (int i = 1; i <= max(h, w); i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	for (int i = 0; i <= max(h, w); i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				c[i][j] = 1;
			} else {
				c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int r, c, r1, c1;
		cin >> r >> c >> r1 >> c1;
		r--, c--, r1--, c1--;
		bad[r] = true;
		bad[r1] = true;
		bads[c] = true;
		bads[c1] = true;
	}
	bad[h] = true;
	bads[w] = true;
	dp[0][0] = 1;
	int have = h;
	for (int i = 0; i < h; i++) {
		if (bad[i]) {
			have--;
		}
		for (int j = 0; j <= h / 2; j++) {
			if (!bad[i] && !bad[i + 1]) {
				dp[i + 2][j + 1] = sum(dp[i + 2][j + 1], dp[i][j]);
			}
			dp[i + 1][j] = sum(dp[i + 1][j], dp[i][j]);
		}
	}
	dp1[0][0] = 1;
	int have1 = w;
	for (int i = 0; i < w; i++) {
		if (bads[i]) {
			have1--;
		}
		for (int j = 0; j <= w / 2; j++) {
			if (!bads[i] && !bads[i + 1]) {
				dp1[i + 2][j + 1] = sum(dp1[i + 2][j + 1], dp1[i][j]);
			}
			dp1[i + 1][j] = sum(dp1[i + 1][j], dp1[i][j]);
		}
	}
	int res = 0;
	for (int i = 0; i <= h / 2; i++) {
		for (int j = 0; j <= w / 2; j++) {
			int f = mul(dp[h][i], dp1[w][j]);
 			int g = have - i * 2;
			int g1 = have1 - j * 2;
			if (g < 0 || g1 < 0) {
				continue;
			}
			f = mul(f, c[g][j]);
			f = mul(f, fact[j]);
			f = mul(f, c[g1][i]);
			f = mul(f, fact[i]);
			res = sum(res, f);
		}
	}
	cout << res << '\n';
 	return 0;
}