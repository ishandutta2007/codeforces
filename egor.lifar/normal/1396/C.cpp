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
const int MAXN = 1000228;


int n;
ll r1, r2, r3, d;
ll a[MAXN];
ll dp[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> r1 >> r2 >> r3 >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++) {
		dp[i] = 1e18;
	}
	dp[0] = 0;
	ll ans = 1e18;
	for (int i = 0; i < n; i++) {
		chkmin(dp[i + 1], dp[i] + a[i] * r1 + r3 + (i == n - 1 ? 0: d));
		if (i == n - 1) {
			chkmin(ans, dp[n - 1] + r2 + 2 * d + r1);
			chkmin(ans, dp[n - 1] + r1 * (a[i] + 1) + 2 * d + r1);
		} else {
			chkmin(dp[i + 1], dp[i] + r2 + r1 + 3 * d);
			chkmin(dp[i + 1], dp[i] + r1 * (a[i] + 1) + r1 + 3 * d);
			ll val = dp[i] + min(r2 + r1, r1 * (a[i] + 2)) + 3 * d + min(r2 + r1, r1 * (a[i + 1] + 2));
			if (i + 1 == n - 1) {
				chkmin(ans, val);
			} else {
				chkmin(dp[i + 2], val + d);
			}
			ll val1 = dp[i] + min(r2 + r1, r1 * (a[i] + 2)) + 2 * d + a[i + 1] * r1 + r3;
			if (i + 1 == n - 1) {
				chkmin(ans, val1);
			} else {
				chkmin(dp[i + 2], val1 + 2 * d);
			}
		}
	}
	chkmin(ans, dp[n]);
	cout << ans << '\n';
}