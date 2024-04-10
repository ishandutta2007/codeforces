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
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 1000228;
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}



int mul(int a, int b) {
	return (1LL * a * b) % Mod;
}


int n;
pair<ll, int> dp[MAXN][2];
ll opt[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	dp[0][0] = mp(0, 1);
	dp[0][1] = mp(0, 1);
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			opt[i] = 0;
		} else {
			opt[i] = (i - 1) + opt[(i - 1) / 2] + opt[i - 1 - (i - 1) / 2];
		}
		for (int t = 0; t < 2; t++) {
			if (i == 1) {
				if (t == 0) {
					dp[i][t] = mp(1e18, 0);
				} else {
					dp[i][t] = mp(0, 1);
				}
			} else {
				int g = i / 2;
				int fl = max(0, g - 40);
				int fr = min(i - 1, g + 40);
				if (fl % 2 == t) {
					fl++;
				}
				if (fr % 2 == t) {
					fr--;
				}
				auto f = mp(1e18, 0);
				for (int j = fl; j <= fr; j+= 2) {
					auto x = dp[j][t ^ 1];
					auto y = dp[i - j - 1][t ^ ((j + 1) & 1)];
					x.first += y.first;
					x.second = mul(x.second, y.second);
					if (f.first > x.first) {
						f = x;
					} else if (f.first == x.first) {
						f.second = sum(f.second, x.second);
					}
				}
				f.first += i - 1;
				dp[i][t] = f;
				assert(f.first >= opt[i]);
				if (f.first != opt[i]) {
					dp[i][t].second = 0;
					dp[i][t].first = 1e18;
				}
			}
		}
	}
	auto x = dp[n][0];
	auto y = dp[n][1];
	ll k = min(x.first, y.first);
	int res = 0;
	if (k == x.first) {
		res = sum(res, x.second);
	}
	if (k == y.first) {
		res = sum(res, y.second);
	}
	cout << res << '\n';
 	return 0;
}