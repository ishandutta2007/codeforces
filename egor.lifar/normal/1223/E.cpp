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
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 500228;



int n, k;
vector<pair<int, int> > g[MAXN];
ll dp[MAXN][2];



void dfs(int u, int pr = -1) {
	vector<pair<int, int> > sons;
	for (auto h: g[u]) {
		if (h.first == pr) {
			continue;
		}
		dfs(h.first, u);
		sons.push_back(h);
	}
	for (int t = 0; t < 2; t++) {
		int have = k - t;
		chkmin(have, sz(sons));
		vector<ll> gt;
		dp[u][t] = 0;
		for (int i = 0; i < sz(sons); i++) {
			int h = sons[i].first;
			ll val = max(dp[h][0], dp[h][1]);
			dp[u][t] += val;
			ll val1 = dp[h][1] + sons[i].second;
			gt.pb(val1 - val);
		}
		ll sum = dp[u][t];
		sort(all(gt));
		reverse(all(gt));
		ll cur = 0;
		for (int i = 0; i < min(have, sz(gt)); i++) {
			cur += gt[i];
			chkmax(dp[u][t], sum + cur);
		}
	}
}


void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		g[i].clear();
		g[i].shrink_to_fit();
	}
	for (int i = 1; i < n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		g[a].pb({b, w});
		g[b].pb({a, w});
	}
	dfs(0);
	cout << max(dp[0][0], dp[0][1]) << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int q;
	cin >> q;
	for (int it = 0; it < q; it++) {
		solve();
	}
	return 0;
}