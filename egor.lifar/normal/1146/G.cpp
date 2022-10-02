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
const string FILENAME = "input";
const int MAXN = 55;


int n, h, m;
int l[MAXN], r[MAXN], x[MAXN], c[MAXN];
int dp[MAXN][MAXN][MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n >> h >> m;
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i] >> x[i] >> c[i];
		l[i]--, r[i]--;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j <= n; j++) {
			for (int cc = 0; cc <= h; cc++) {
				dp[i][j][cc] = -1e9;
				for (int f = i; f <= j; f++) {
					int sum = 0;
					for (int k = 0; k < m; k++) {
						if (l[k] <= f && f <= r[k] && l[k] >= i && r[k] <= j && x[k] < cc) {
							sum += c[k];
						} 
					}
				//	cout << sum << endl;
					chkmax(dp[i][j][cc], (f  - 1 < i ? 0: dp[i][f - 1][cc]) + (f + 1 > j ? 0: dp[f + 1][j][cc]) + cc * cc - sum);
				}
				if (cc) {
					chkmax(dp[i][j][cc], dp[i][j][cc - 1]);
				}
			}
		}
	}
	cout << dp[0][n - 1][h] << '\n'; 
	return 0; 	
}