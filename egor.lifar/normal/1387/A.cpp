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
const int MAXN = 400228;



int n, m;
set<pair<int, int> > g[MAXN];
bool used[MAXN];
bool bad = false;
int c[MAXN];
vector<int> st;
int parent[MAXN];


void dfs(int u) {
	st.pb(u);
	used[u] = true;
	for (auto h: g[u]) {
		if (h.second == 0) {
			if (!used[h.first]) {
				c[h.first] = 1 - c[u];
				dfs(h.first);
			} else if (c[h.first] == c[u]) {
				bad = true;
			}
		}
	}
}



void dfs1(int u) {
	st.pb(u);
	used[u] = true;
	for (auto h: g[u]) {
		if (h.second == 1) {
			if (!used[h.first]) {
				c[h.first] = 1 - c[u];
				dfs1(h.first);
			} else if (c[h.first] == c[u]) {
				bad = true;
			}
		}
	}
}


int findset(int u) {
	if (parent[u] == u) {
		return u;
	}
	return parent[u] = findset(parent[u]);
}




void unite(vector<int> x) {
	for (int i = 1; i < sz(x); i++) {
		parent[findset(x[i])] = findset(x[0]);
	}
}



bool kek1[MAXN], kek5[MAXN];
vector<int> halfs, ones;
int a[MAXN];
double b[MAXN];
bool was = false;
double cs[MAXN];
double x;


void dfs2(int u, int pr = -1) {
	used[u] = true;
	st.pb(u);
	for (auto h: g[u]) {
		double a1, b1;
		if (h.second == 0) {
			a1 = -a[u];
			b1 = 1 - b[u];
		} else {	
			a1 = -a[u];
			b1 = 2 - b[u];
		}
		if (!used[h.first]) {
			a[h.first] = a1;
			b[h.first] = b1;
			dfs2(h.first, u);
		} else {
			if (h.first == pr) {
				continue;
			}
			if (a[h.first] == a1) {
				//cout << "opa" << ' ' << u << ' ' << h.first << endl;
				if (b[h.first] != b1) {
					cout << "NO\n";
					exit(0);
				}
			} else {
				was = true;
				x = double(b[h.first] - b1) / double(a1 - a[h.first]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 1) {
			g[a].insert(mp(b, 0));
			g[b].insert(mp(a, 0));
		} else {
			g[a].insert(mp(b, 1));
			g[b].insert(mp(a, 1));
		}
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}	
	// for (int i = 1; i <= n; i++) {
	// 	if (!used[i]) {
	// 		st.clear();
	// 		dfs(i);
	// 		if (bad) {
	// 			unite(st);
	// 			halfs.pb(st[0]);
	// 		} else {
	// 			vector<int> cur[2];
	// 			for (int j = 0; j < sz(st); j++) {
	// 				cur[c[st[j]]].pb(st[j]);
	// 			}
	// 			for (int t = 0; t < 2; t++) {
	// 				unite(cur[t]);
	// 			}
	// 		}
	// 	}
	// }
	// memset(used, 0, sizeof(used));
	// for (int i = 1; i <= n; i++) {
	// 	if (!used[i]) {
	// 		st.clear();
	// 		dfs1(i);
	// 		if (bad) {
	// 			unite(st);
	// 			ones.pb(st[0]);
	// 		} else {
	// 			vector<int> cur[2];
	// 			for (int j = 0; j < sz(st); j++) {
	// 				cur[c[st[j]]].pb(st[j]);
	// 			}
	// 			for (int t = 0; t < 2; t++) {
	// 				unite(cur[t]);
	// 			}
	// 		}
	// 	}
	// }
	// for (auto x: ones) {
	// 	kek1[findset(x)] = true; 
	// }
	// for (auto x: halfs) {
	// 	kek5[findset(x)] = true; 
	// }
	// for (int i = 1; i <= n; i++) {
	// 	if (kek1[findset(i)] && kek5[findset(i)]) {
	// 		cout << "NO\n";
	// 		exit(0);
	// 	}
	// }
	set<pair<int, int> > who[2];
	for (int i = 1; i <= n; i++) {
		for (auto h: g[i]) {
			int a = findset(i);
			int b = findset(h.first);
			if (a > b) {
				swap(a, b);
			}
			who[h.second].insert(mp(a, b));
		}
	}
	for (auto x: who[0]) {
		if (who[1].find(x) != who[1].end()) {
			cout << "NO\n";
			exit(0);
		}
	}
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; i++) {	
		if (!used[i]) {
			if (g[i].empty()) {
				continue;
			}
			a[i] = 1;
			b[i] = 0;
			st.clear();
			was = false;
			dfs2(i);
			if (was) {
				for (auto id: st) {
					cs[id] = a[id] * x + b[id];
				}
			} else {
				vector<int> str;
				for (auto id: st) {
					if (a[id] == 1) {
						str.pb(-b[id]);
					} else {
						str.pb(b[id]);
					}
				}
				sort(all(str));
				//cout << sz(st) << endl;
				x = str[sz(str) / 2];
				for (auto id: st) {
					cs[id] = a[id] * x + b[id];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {	
		for (auto h: g[i]) {
			if (abs(cs[i] + cs[h.first] - h.second - 1) > 1e-9) {
				cout << "NO\n";
				exit(0);
			}
 		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {	
		cout << fixed << cs[i] << ' ';
	}
	cout << '\n';
}