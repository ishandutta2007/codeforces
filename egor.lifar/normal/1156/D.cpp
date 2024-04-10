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
const string FILENAME = "input";
const int MAXN = 200228;


int n;
vector<pair<int, int> > g[MAXN];
long long ans = 0;
long long dp[MAXN][2][2];
bool kek[MAXN];

void dfs(int u, int pr = -1) {
	vector<pair<int, int> > sons;
	for (auto h: g[u]) {
		if (h.first != pr) {
			dfs(h.first, u);
			sons.pb(h);
		}
	}
	if (sons.empty()) {
		kek[u] = true;
		return;
	}
	long long cur[2][2] = {{0, 0}, {0, 0}};
	for (auto x: sons) {
		long long t[2][2] = {{0, 0}, {0, 0}};
		if (x.second == 0) {
			t[0][0] = dp[x.first][0][0] + 1;
			t[0][1] = dp[x.first][0][1] + dp[x.first][1][0];
		} else {
			t[1][0] = dp[x.first][1][0] + 1;
			t[1][1] = dp[x.first][1][1] + dp[x.first][0][0];
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				dp[u][j][k] += t[j][k];
			}
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int j1 = 0; j1 < 2; j1++) {
					for (int k1 = 0; k1 < 2; k1++) {
						vector<int> kek;
						if (k) {
							kek.pb(j ^ 1);
						}
						kek.pb(j);
						kek.pb(j1);
						if (k1) {
							kek.pb(j1 ^ 1);
						}
						vector<int> st;
						for (auto x: kek) {
							if (!st.empty() && x == st.back()) {
								continue;
							}
							st.pb(x);
						}
						int cnt = 0;
						for (int g = 0; g < sz(st) - 1; g++) {
							if (st[g] != st[g + 1]) {
								cnt++;
							}
						}
						if (cnt == 0) {
							ans += cur[j][k] * t[j1][k1] * 2;
						} else {
							if (cnt == 1) {
								ans += cur[j][k] * t[j1][k1];
							}
						}
					}
				}
			}
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				cur[j][k] += t[j][k];
			}
		}
	}
	ans += dp[u][0][0] * 2 + dp[u][1][0] * 2 + dp[u][0][1] + dp[u][1][1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n;
 	for (int i = 0; i < n - 1; i++) {
 		int a, b, c;
 		cin >> a >> b >> c;
 		a--, b--;
 		g[a].pb({b, c});
 		g[b].pb({a, c});
 	}
 	dfs(0);
 	cout << ans << endl;
	return 0; 	
}