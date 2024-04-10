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
#include <random>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int Mod = 1000000007;
const int MAXN = 2005;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return (ll)a * b % Mod;
}


int n, m, r;
int x[MAXN], y[MAXN], cost[MAXN];
bitset<2002> b[MAXN];
int c[MAXN][MAXN];
int dp[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> cost[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				c[i][j] = 1;
			} else {
				c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (max(abs(x[i] - x[j]), abs(y[i] - y[j])) <= r) {
				b[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= min(i, m); j++) {
			dp[i] = sum(dp[i], mul(c[i][j], c[n - i][m - j]));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int val = (b[i] & b[j]).count();
			int val1 = n - (b[i] | b[j]).count();
			int val2 = b[i].count() - val;
			int val3 = b[j].count() - val;
			int cnt = 0;
			cnt = sum(cnt, dp[val]);
			int cnt1 = c[n - val][m];
			cnt1 = sum(cnt1, c[val1][m]);
			cnt1 = sum(cnt1, Mod - c[val1 + val2][m]);
			cnt1 = sum(cnt1, Mod - c[val1 + val3][m]);
			cnt = sum(cnt, cnt1);
			ans = sum(ans, mul(cnt, mul(2, mul(cost[i], cost[j]))));
		}
		int val = b[i].count();
		int val1 = n - val;
		int cnt = 0;
		for (int i = 1; i <= min(m, val); i++) {
			cnt = sum(cnt, mul(c[val][i], c[val1][m - i]));
		}
		ans = sum(ans, mul(cnt, mul(cost[i], cost[i])));
	}
	cout << ans << '\n';
}