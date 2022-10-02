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
const int MAXN = 1000228;
const int Mod = 1000000007;



int mul(int a, int b) {
	return (1LL * a * b) % Mod;
}


int sum(int a, int b) {
	return (a + b) % Mod;
}

int n;
int fact[MAXN];
int kek[MAXN];
int dp[22][MAXN][2];
int dp1[MAXN][2];
int kekt[MAXN];
int keks = 0;


int calc() {
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;
	int curs = 0;
	for (int i = 0; i <= keks; i++) {
		memset(dp1, 0, sizeof(dp1));
		for (int cur = n; cur >= 0; cur--) {
			int have = cur + kek[keks - i] - 1;
			dp1[have][0] = mul(kek[keks - i], dp[i][cur][0]);
		}
		for (int cur = n; cur >= 0; cur--) {
			int have = cur + kekt[keks - i] - 1;
			dp1[have][1] = mul(kekt[keks - i], dp[i][cur][1]);
			if (i) {
				int val = kek[keks - i] - kekt[keks - i + 1] + curs;
				int have = cur + val - 1;
				dp1[have][0] = sum(dp1[have][0], mul(val, dp[i][cur][1]));
			}
		}
		for (int t = 0; t < 2; t++) {
	 		for (int cur = n; cur >= 0; cur--) {
				if (cur) {
					dp1[cur - 1][t] = sum(dp1[cur - 1][t], mul(dp1[cur][t], cur));
				}
				dp[i + 1][cur][t] = sum(dp[i + 1][cur][t], dp1[cur][t]);
			}
		}
		curs += kek[keks - i] - kekt[keks - i + 1];
	}
	//cout << dp[keks + 1][0][1] << endl;
	int ans = sum(dp[keks + 1][0][0], dp[keks + 1][0][1]);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n;
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	for (int i = 1; i <= n; i++) {
		int cur = i;
		int cnt = 0;
		while (cur % 2 == 0) {
			cur /= 2;
			cnt++;
		}
		kek[cnt]++;
		chkmax(keks, cnt);
		if (cur % 3 == 0) {
			kekt[cnt + 1]++;
		}
	}
	cout << calc() << '\n';
	return 0;
}