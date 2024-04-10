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
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 2000228;


const int Mod = 1000000007;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}

ll n;
int dp[MAXN][2];

 
void solve() {
	cin >> n;
	cout << dp[n][0] << '\n';
}
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 //	read(FILENAME);
	for (int i = 3; i < MAXN; i++) {
		dp[i][1] = sum(dp[i - 1][0], mul(dp[i - 2][0], 2));
		if (i <= 4 || i % 3 == 0) {
			dp[i][0] = sum(4, sum(dp[i - 1][1], mul(dp[i - 2][1], 2)));
		} else {
			dp[i][0] = dp[i][1];
		}
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;	 	
}