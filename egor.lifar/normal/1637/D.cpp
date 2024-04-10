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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
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
const int MAXN = 105;


int n;
int a[MAXN];
int b[MAXN];
ll dp[102][10002];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans += a[i] * a[i];
			ans += a[j] * a[j];
			ans += b[i] * b[i];
			ans += b[j] * b[j];
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			dp[i][j] = 1e18;
		}
	}
	dp[0][0] = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (dp[i][j] > 1e17) {
				continue;
			}
			chkmin(dp[i + 1][j + a[i]], dp[i][j] + a[i] * j + b[i] * (cur - j));
			chkmin(dp[i + 1][j + b[i]], dp[i][j] + b[i] * j + a[i] * (cur - j));
		}
		cur += a[i] + b[i];
	}
	ll add = 1e18;
	for (int j = 0; j <= 10000; j++) {
		chkmin(add, dp[n][j]);
	}
	cout << ans + add * 2 << '\n';
}		


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}