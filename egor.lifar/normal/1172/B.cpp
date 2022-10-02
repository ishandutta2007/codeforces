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


int n;
vector<int> g[MAXN];
int dp[MAXN];
int fact[MAXN];


void dfs(int u, int pr = -1) {
	dp[u] = 1;
	int cnt = 0;
	for (auto h: g[u]) {
		if (h == pr) {
			continue;
		}
		dfs(h, u);
		dp[u] = mul(dp[u], dp[h]);
		cnt++;
	}
	if (u == 0) {
		cnt--;
	}
	dp[u] = mul(dp[u], fact[cnt + 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	dfs(0);
	cout << mul(n, dp[0]) << endl;
}