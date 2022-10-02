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
const string FILENAME = "input";
const int MAXN = 1001;
const int Mod =   998244353;

int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return (1LL * a * b) % Mod;
}

int n, k;
int a[MAXN];
int dp[MAXN][MAXN];
int pref[MAXN][MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int last = 0;
	int res = 0;
	for (int val = 100000 / (k - 1) + 1; val >= 0; val--) {
		int uk = -1;
		int kek = 0;
		for (int i = 0; i < n; i++) {
			while (uk + 1 < i && a[i] - a[uk + 1] >= val) {
				uk++;
			}
			for (int j = 1; j <= k; j++) {
				if (j == 1) {
					dp[i][j] = 1;
				} else {
					if (uk >= 0) {
						dp[i][j] = pref[uk][j - 1];
					} else {
						dp[i][j] = 0;
					}
				}
				pref[i][j] = dp[i][j];
				if (i) {
					pref[i][j] = sum(pref[i - 1][j], pref[i][j]);
				}
			}
			kek = sum(kek, dp[i][k]);
		}
		res = sum(res, mul(val, sum(kek, Mod - last)));
		last = kek;
	}
	cout << res << endl;
	return 0;
}