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
const int MAXN = 100228;




int n;
vector<int> g[MAXN];
int sz[MAXN];
ll ans = 0;
int deep[MAXN];
vector<vector<int> > cur;
vector<int> st;
int res[MAXN];


void dfs(int u, int pr = -1) {
	sz[u] = 1;
	for (auto h: g[u]) {
		if (h == pr) {
			continue;
		}
		deep[h] = deep[u] + 1;
		dfs(h, u);
		ans += min(sz[h], n - sz[h]) * 2;
		sz[u] += sz[h];
	}
}

void dfs1(int u, int pr) {
	st.pb(u);
	for (auto h: g[u]) {
		if (h == pr) {
			continue;
		}
		dfs1(h, u);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0);
	int c = -1;
	for (int i = 0; i < n; i++) {
		if (sz[i] >= (n + 1) / 2) {
			if (c == -1 || deep[c] < deep[i]) {
				c = i;
			}
		}
	}
	cout << ans << '\n';
	for (auto h: g[c]) {
		st.clear();
		dfs1(h, c);
		cur.pb(st);
	}
	set<pair<int, int> > s;
	cur.pb(vector<int>{c});
	for (int i = 0; i < sz(cur); i++) {
		s.insert(mp(sz(cur[i]), i));
	}
	if (n % 2 == 1) {
		auto x = *s.rbegin();
		s.erase(x);
		auto x1 = *s.rbegin();
		s.erase(x1);
		auto x2 = *s.rbegin();
		s.erase(x2);
		int a = cur[x.second].back();
		cur[x.second].pop_back();
		int b = cur[x1.second].back();
		cur[x1.second].pop_back();
		int c = cur[x2.second].back();
		cur[x2.second].pop_back();
		res[a] = b;
		res[b] = c;
		res[c] = a;
		x.first--, x1.first--, x2.first--;
		if (x.first) {
			s.insert(x);
		}
		if (x1.first) {
			s.insert(x1);
		}
		if (x2.first) {
			s.insert(x2);
		}
	}
	while (!s.empty()) {
		auto x = *s.rbegin();
		s.erase(x);
		auto x1 = *s.rbegin();
		s.erase(x1);
		x.first--;
		x1.first--;
		int a = cur[x.second].back();
		cur[x.second].pop_back();
		int b = cur[x1.second].back();
		cur[x1.second].pop_back();
		res[a] = b;
		res[b] = a;
		if (x.first) {
			s.insert(x);
		}
		if (x1.first) {
			s.insert(x1);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] + 1 << ' ';
	}
	cout << '\n';
}