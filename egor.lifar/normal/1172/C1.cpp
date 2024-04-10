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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 200228;
const int Mod = 998244353;


int mul(int a, int b) {
	return (1LL * a * b) % Mod;
}


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}


int n, m;
int a[MAXN];
int w[MAXN];
int dp[55][55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	int kek[2] = {0, 0};
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		kek[a[i]] = sum(kek[a[i]], w[i]);
	} 
	int sums = sum(kek[0], kek[1]);
	for (int k = 0; k < n; k++) {
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for (int i = 0; i <= m; i++) {
			for (int s = 0; s <= m; s++) {
				for (int g = 0; g <= m; g++) {
					int h = i - g;
					int gg = (w[k] + (a[k] ? s: -s));
					//+ g - h
					int cur = sums + g - h;
					chkmax(gg, 0);
					int cur1 = powm(cur, Mod - 2);
					int ver = mul(gg, cur1);
					ver = mul(ver, dp[i][s][g]);
					if (a[k]) {
						dp[i + 1][s + 1][g + 1] = sum(dp[i + 1][s + 1][g + 1], ver);
						ver = mul(dp[i][s][g], mul(kek[0] - h, cur1));
						dp[i + 1][s][g] = sum(dp[i + 1][s][g], ver);
						ver = mul(dp[i][s][g], mul(kek[1] + g - gg, cur1));
						dp[i + 1][s][g + 1] = sum(dp[i + 1][s][g + 1], ver);
					} else {
						dp[i + 1][s + 1][g] = sum(dp[i + 1][s + 1][g], ver);
						ver = mul(dp[i][s][g], mul(kek[1] + g, cur1));
						dp[i + 1][s][g + 1] = sum(dp[i + 1][s][g + 1], ver);
						ver = mul(dp[i][s][g], mul(kek[0] - h - gg, cur1));
						dp[i + 1][s][g] = sum(dp[i + 1][s][g], ver);
					}
				}
			}
	 	}
	 	int res = 0;
	 	for (int s = 0; s <= m; s++) {
			for (int g = 0; g <= m; g++) {
				int gg = w[k] + (a[k] ? s: -s);
				res = sum(res, mul(dp[m][s][g], gg));
			}
		}
		cout << res << '\n';
	}
}