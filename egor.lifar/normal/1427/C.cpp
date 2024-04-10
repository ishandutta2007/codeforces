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
const int MAXN = 200228;


int r, n;
int t[MAXN], x[MAXN], y[MAXN];
int dp[MAXN];
int c[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> r >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}
	int cur =-1e9;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		c[i] = -1e9;
	}
	for (int i = 0; i < n; i++) {
		dp[i] = -1e9;
	}
	for (int i = 0; i < n; i++) {
		chkmax(cur, c[i]);
		if (abs(1 - x[i]) + abs(1 - y[i]) <= t[i]) {
			chkmax(dp[i], 1);
		}
		chkmax(dp[i], cur);
		for (int j = i + 1; j <= min(n - 1, i + 1001); j++) {
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[j] - t[i]) {
			//	cout << i << ' ' << j << endl;
				chkmax(dp[j], dp[i] + 1);
			}
		}
		chkmax(c[i + 1002], dp[i] + 1);
		chkmax(ans, dp[i]);
	} 
	cout << ans << '\n';
}