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
#include <complex>


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
string s;
int a[MAXN];
int dp[MAXN][2][2];


void solve() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < sz(s); i++) {
		a[i] = s[i] == 'L';
	}
	int res = 1e9;
	for (int c = 0; c < 2; c++) {
		for (int c1 = 0; c1 < 2; c1++) {
			for (int i = 2; i <= n; i++) {
				for (int t = 0; t < 2; t++) {
					for (int t1 = 0; t1 < 2; t1++) {
						dp[i][t][t1] = 1e9;
					}
				}
			}
			dp[2][c][c1] = (c != a[0]) + (c1 != a[1]);
			for (int i = 2; i < n; i++) {
				for (int t = 0; t < 2; t++) {
					for (int t1 = 0; t1 < 2; t1++) {
						for (int nt = 0; nt < 2; nt++) {
							if (nt == t && nt == t1) {
								continue;
							}
							chkmin(dp[i + 1][t1][nt], dp[i][t][t1] + (nt != a[i]));
						}
					}
				}
			}
			for (int t = 0; t < 2; t++) {
				for (int t1 = 0; t1 < 2; t1++) {
					if (t1 == c && t1 == c1) {
						continue;
					}
					if (t == t1 && t1 == c) {
						continue;
					}
					chkmin(res, dp[n][t][t1]);
				}
			}
		}
	}
	cout << res << '\n';
}	


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}