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
const int MAXN = 105;


int n, m;
int ls[MAXN][MAXN], rs[MAXN][MAXN];
int dp[MAXN][MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int it = 0; it < k; it++) {
			int l, r;
			cin >> l >> r;
			for (int j = l; j <= r; j++) {
				ls[i][j] = l;
				rs[i][j] = r;
			}
		}
	}
	for (int i = m + 1; i >= 0; i--) {
		for (int j = i + 2; j <= m + 1; j++) {
			for (int k = i + 1; k < j; k++) {
				int ans = 0;
				for (int it = 0; it < n; it++) {
					if (i < ls[it][k] && rs[it][k] < j) {
						ans++;
					}
				}
				chkmax(dp[i][j], dp[i][k] + dp[k][j] + ans * ans);
			}
		}
	}
	cout << dp[0][m + 1] << '\n';
}