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



 
 

int n;
int a[MAXN];
ll dp[2][3][2];

 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << a[0] << '\n';
		return 0;
	}
	for (int j = 0; j < 3; j++) {
		for (int t = 0; t < 2; t++) {
			dp[0][j][t] = dp[1][j][t] = -1e18;
		}
	}
	dp[0][0][0] = 0;
	int g = 0;
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				for (int u = 0; u < 2; u++) {
					chkmax(dp[g ^ 1][(j + u >= 3 ? j + u - 3: j + u) ][k | (u != (i & 1))], dp[g][j][k] + (1 - 2 * u) * a[i]);
				}
			}
		}
		g ^= 1;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				dp[g ^ 1][j][k] = -1e18;
			}
		}
	}
	cout << dp[g][(2 * n + 1) % 3][1] << '\n';
}