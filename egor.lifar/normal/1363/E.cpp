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
const int MAXN = 300228;


int n;
int a[MAXN], b[MAXN], c[MAXN];
vector<int> g[MAXN];
ll ans = 0;


pair<int, int> dfs(int u, int pr = -1, int curm = 1e9) {
	chkmin(curm, a[u]);
	int cnt0 = 0, cnt1 = 0;
	for (auto h: g[u]) {
		if (h != pr) {
			auto x = dfs(h, u, curm);
			cnt0 += x.first;
			cnt1 += x.second;
		}
	}
	if (b[u] != c[u]) {
		if (b[u] == 0) {
			cnt0++;
		} else {
			cnt1++;
		}
	}
	if (curm == a[u]) {
		int d = min(cnt0, cnt1);
		cnt0 -= d;
		cnt1 -= d;
		ans += 2LL * d * a[u];
	}
	return mp(cnt0, cnt1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n;
	int t = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		if (b[i] != c[i]) {
			t++;
			if (b[i] == 0) {
				cnt++;
			}
		}
	}
	if (cnt != t - cnt) {
		cout << -1 << '\n';
		return 0;
	}
	if (t == 0) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0);
	cout << ans << '\n';
	return 0; 	
}