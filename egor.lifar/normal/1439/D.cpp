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
const int MAXN = 505;
int Mod;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


ll n, m;
ll dp1[MAXN], dp2[MAXN];
ll dp3[MAXN][MAXN], dp4[MAXN][MAXN];
ll C[MAXN][MAXN];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m >> Mod;
	int border = max(n, m) + 1;
	for (int i = 0; i < border; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				C[i][j] = 1;
			} else {
				C[i][j] = sum(C[i - 1][j], C[i - 1][j - 1]);
			}
		}
	}
	dp1[0] = 1;
	for (int n = 1; n < border; n++) {
		for (int i = 1; i <= n; i++) {
			dp1[n] = sum(dp1[n], mul(mul(dp1[i - 1], dp1[n - i]), C[n - 1][i - 1]));
		}
		dp1[n] = mul(n + 1, dp1[n]);
		for (int i = 1; i <= n; i++) {
			int val = sum(mul(dp1[i - 1], dp2[n - i]), mul(dp2[i - 1], dp1[n - i]));
			dp2[n] = sum(dp2[n], mul(mul(n + 1, C[n - 1][i - 1]), val));
			int ways = i * (i - 1) / 2 + (n - i) * (n - i + 1) / 2; 
			dp2[n] = sum(dp2[n], mul(mul(C[n - 1][i - 1], dp1[i - 1]), mul(dp1[n - i], ways)));
		}
	}
	dp3[0][0] = 1;
	for (int n = 1; n < border; n++) {
		for (int m = 0; m < n; m++) {
			dp3[n][m] = dp3[n - 1][m];
			dp4[n][m] = dp4[n - 1][m];
			for (int i = 1; i <= m; i++) {
				dp3[n][m] = sum(dp3[n][m], mul(mul(dp3[n - i - 1][m - i], dp1[i]), C[m][i]));
				dp4[n][m] = sum(dp4[n][m], mul(mul(dp3[n - i - 1][m - i], dp2[i]), C[m][i]));
				dp4[n][m] = sum(dp4[n][m], mul(mul(dp4[n - i - 1][m - i], dp1[i]), C[m][i]));
			}
			dp3[n][n] = dp1[n];
			dp4[n][n] = dp2[n];
		}
	}
	cout << dp4[n][m] << '\n';	
}