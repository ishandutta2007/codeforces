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
const int Mod = 998244353;


int sum(const int &a, const int &b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}

int mul(const int &a, const int &b) {
	return (1LL * a * b) % Mod;
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


int n;
vector<int> g[MAXN];
int dp[MAXN][2];


void dfs(int u) {
	dp[u][0] = 1;
	int f = 1;
	for (auto h: g[u]) {
		dfs(h);
		f = mul(f, dp[h][0]);
		dp[u][0] = mul(dp[u][0], sum(dp[h][0], dp[h][1]));
	}
	dp[u][1] = dp[u][0];
	for (auto h: g[u]) {
		int kek = mul(f, powm(dp[h][0], Mod - 2));
		kek = mul(kek, dp[h][1]);
		dp[u][0] = sum(dp[u][0], Mod - kek);
	}
	int kek = 1;
	for (auto h: g[u]) {
		kek = mul(kek, dp[h][0]);
	}
	if (sz(g[u])) {
		dp[u][1] = sum(dp[u][1], Mod - kek);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;
		g[p].pb(i);
	}
	dfs(0);
	//cout << dp[1][0] << ' ' << dp[1][1] << endl;
	cout << dp[0][0] << '\n';
	return 0; 	
}