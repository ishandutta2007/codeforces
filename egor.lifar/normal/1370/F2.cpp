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
const int MAXN = 1028;




int n;
vector<int> g[MAXN];
int deep[MAXN];
int who[MAXN];


pair<int, int> query(vector<int> v) {
	cout << "? " << sz(v);
	for (auto x: v) {
		cout << ' ' << x + 1;
	}
	cout << endl;
	int u, dist;
	cin >> u >> dist;
	u--;
	return mp(u, dist);
}
 

void dfs(int u, int pr) {
	for (auto h: g[u]) {
		if (h != pr) {
			deep[h] = deep[u] + 1;
			who[h] = (pr == -1 ? h: who[u]);
			dfs(h, u);
		}
	}
}


void solve() {
	cin >> n;
	for (int it = 0; it < n; it++) {
		g[it].clear();
	}
	for (int it = 0; it < n - 1; it++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<int> all;
	for (int i = 0; i < n; i++) {
		all.pb(i);
	}
	auto resp = query(all);
	int root = resp.first;
	int len = resp.second;
	deep[root] = 0;
	who[root] = -1;
	dfs(root, -1);
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (deep[pos] < deep[i]) {
			pos = i;
		}
	}
	int id = who[pos];
	int val = 0;
	for (int i = 0; i < n; i++) {
		if (who[i] != id) {
			chkmax(val, deep[i]);
		}
	}
	int l = 0;
	int r = val;
	int s = root;
	while (l < r) {
		int mid = (l + r) >> 1;
		vector<int> st;
		for (int i = 0; i < n; i++) {
			if (who[i] != id && deep[i] > mid) {
				st.pb(i);
			}
		}
		resp = query(st);
		if (resp.second == len) {
			s = resp.first;
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	int need = len - deep[s];
	vector<int> st;
	for (int i = 0; i < n; i++) {
		if (deep[i] == need) {
			if (who[i] != who[s]) {
				st.pb(i);
			}
		}
	}
	resp = query(st);
	int f = resp.first;
	cout << "! " << s + 1 << ' ' << f + 1 << endl;
	string res;
	cin >> res;
}


int main() {
	ios_base::sync_with_stdio(false);
 	//read(FILENAME);
 	int t;
 	cin >> t;
 	while (t--) {
 		solve();
 	}
	return 0;	 	
}