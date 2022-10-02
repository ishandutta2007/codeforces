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
const int MAXN = 5005;
const int Mod = 998244353;


int sum(const int &a, const int &b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(const int &a, const int &b) {
	return (1LL * a * b) % Mod;
}


int powm(int a, int b) {
	int cur = 1;
	while (b) {
		if (b & 1) {
			cur = mul(cur, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return cur;
}

int n;
int a[MAXN];
int cnt[MAXN];
int dp[MAXN][MAXN];
int fact[MAXN], rfact[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n;
 	for (int i = 0; i < n; i++) {
 		cin >> a[i];
 		cnt[a[i]]++;
 	}
	fact[0] = 1;
	rfact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = mul(fact[i - 1], i);
		rfact[i] = mul(rfact[i - 1], powm(i, Mod - 2));
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		for (int j = 0; j < n; j++) {
			dp[i][j + 1] = sum(dp[i][j + 1], mul(dp[i - 1][j], cnt[i]));
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] < 2) {
			continue;
		}
		for (int j = 0; j < n - 1; j++) {
			ans = sum(ans, mul(mul(dp[i - 1][j], fact[n - 2 - j]), mul(cnt[i], cnt[i] - 1)));
		}
	}
	ans = mul(ans, rfact[n]);
	cout << ans << '\n';
	return 0; 	
}