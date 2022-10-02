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
const string FILENAME = "input";
const int MAXN = 100027;
 
 
int n;
vector<pair<int, int> > g[MAXN], v[MAXN];
vector<pair<pair<int, int>, int> > res;
int pr[MAXN];



void add(int a, int b, int c) {
	res.pb({{a, b}, c});
}


int pos;
int bad;
bool ok;


void dfst(int u, int frob) {
	if (sz(g[u]) == 1) {
		pos = u;
	}
	if (u == bad) {
		ok = false;
	}
	for (auto h: g[u]) {
		if (h.first == frob) {
			continue;
		}
		dfst(h.first, u);
 	}
}


void addtoleaf(int u, int k, int val) {
	if (sz(g[u]) == 1) {
		add(u, k, val);
	} else {
		pos = -1;
		bad = k;
		vector<int> ft;
		for (auto h: g[u]) {
			ok = true;
			dfst(h.first, u);
			if (ok) {
				ft.pb(pos);
			}
			if (sz(ft) == 2) {
				break;
			}
		}
		add(k, ft[0], val / 2);
		add(k, ft[1], val / 2);
		add(ft[0], ft[1], -val / 2);
	}
}


void dfs(int u, int pr = -1) {
	for (auto h: g[u]) {
		if (h.first == pr) {
			continue;
		}
		v[u].pb(h);
		dfs(h.first, u);
	}
}
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n;
	for (int i  = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	int root = 0;
	for (int i = 0; i < n; i++) {
		if (sz(g[i]) != 1) {
			root = i;
			break;
		}
	}
	if (n == 2) {
		cout << "YES\n";
		cout << 1 << '\n';
		cout << 1 << ' ' << 2 << ' ' << g[0][0].second << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (sz(g[i]) == 2) {
			cout << "NO\n";
			exit(0);
		}
	}	
	dfs(root);
	for (int i = 0; i < n; i++) {
		for (auto x: v[i]) {
			int j = x.first;
			pos = -1;
			bad = j;
			vector<int> ft;
			for (auto h: g[i]) {
				ok = true;
				dfst(h.first, i);
				if (ok) {
					ft.pb(pos);
				}
				if (sz(ft) == 1) {
					break;
				}
			}
			//assert(sz(g[ft[0]]) == 1);
			addtoleaf(j, ft[0], x.second);
			addtoleaf(i, ft[0], -x.second);
		}
	}
	cout << "YES\n";
	cout << sz(res) << '\n';
	for (auto x: res) {
		cout << x.first.first + 1 << ' ' << x.first.second + 1 << ' ' << x.second << '\n';
	}
	return 0;
}