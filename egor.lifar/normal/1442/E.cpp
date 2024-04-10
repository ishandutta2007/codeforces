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
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {if (a < b) {a = b; return true;}return false;}
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
const int MAXN = 200228;


int n;
int a[MAXN];
vector<int> g[MAXN];
int rt, rtw;
int ans;



void dfs(int u, int now, int pr = -1, int dis = 0){
	if (chkmax(ans, dis) || !rtw) {
		rt = u;
		rtw = now;
	}
	for (auto h: g[u]) {
		if (h != pr) {
			dfs(h, a[h] ? : now, u, dis + (now != a[h] && now && a[h]));
		}
	}
}


void solve() {
	ans = rtw = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		g[i].clear();
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, a[1]);
	dfs(rt, rtw);
	cout << (ans + 3) / 2 << '\n';
}
 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}