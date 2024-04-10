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
bool used[MAXN];
int dp[MAXN][MAXN];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		memset(used, 0, sizeof(used));
		int uk = 0;
		for (int j = i; j < n; j++) {
			if (a[j] <= 100) {
				used[a[j]] = true;
			}
			while (used[uk]) {
				uk++;
			}
			dp[i][j] = 1 + uk;
			for (int k = i; k < j; k++) {
				chkmax(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
			ans += dp[i][j];
		}
	}
	cout << ans << '\n';
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