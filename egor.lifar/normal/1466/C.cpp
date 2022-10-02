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
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


const int MAXN = 100228;


int n;
string s;
int dp[MAXN][2][2];


void solve() {
	cin >> s;
	n = sz(s);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = -1e9;
			}
		}
	}	
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				if (dp[i][j][k] < 0) {
					continue;
				}
				for (int t = 0; t < 2; t++) {
					if (t == 0) {
						chkmax(dp[i + 1][k][t], dp[i][j][k]);
					} else {
						if (k == 1 && i >= 1 && s[i - 1] == s[i]) {
							continue;
						}
						if (j == 1 && i >= 2 && s[i - 2] == s[i]) {
							continue;
						}
						chkmax(dp[i + 1][k][t], dp[i][j][k] + 1);
					}
				}
			}
		}
	}
	int res = 0;
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++) {
			chkmax(res, dp[n][j][k]);
		}
	}
	cout << n - res << '\n';
} 


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
 	int t;
 	cin >> t;
 	while (t--) {
 		solve();
 	}
   	return 0;
}