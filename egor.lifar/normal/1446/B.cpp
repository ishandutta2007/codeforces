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
const int MAXN = 5005;



int n, m;
string a, b;
int dp[MAXN][MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n >> m;
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			chkmax(dp[i + 1][j + 1], 4 * (int)(a[i] == b[j]) - 2);
			chkmax(dp[i + 1][j], dp[i][j] - 1);
			chkmax(dp[i][j + 1], dp[i][j] - 1);
			chkmax(dp[i + 1][j + 1], dp[i][j] - 2 + 4 * (int)(a[i] == b[j]));
			chkmax(dp[i + 1][j + 1], dp[i][j] - 2);
		}
	}
	int res = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			chkmax(res, dp[i][j]);
		}
	}
	cout << res << '\n';
}