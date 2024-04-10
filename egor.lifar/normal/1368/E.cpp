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


int n, m;
vector<int> g[MAXN], rg[MAXN];
int clr[MAXN];



void solve() {
	cin >> n >> m;
	for (int it = 1; it <= n; it++) {
		g[it].clear();
		rg[it].clear();
		clr[it] = -1;
	}
	for (int it = 0; it < m; it++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		rg[b].pb(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(all(g[i]));
		g[i].resize(distance(g[i].begin(), unique(all(g[i]))));
	}
	vector<int> kek;
	for (int i = 1; i <= n; i++) {
		bool bad = false;
		for (auto h: rg[i]) {
			if (clr[h] == 1) {
				bad = true;
			}
		}
		if (!bad) {
			if (clr[i] == -1) {
				clr[i] = 0;
				for (auto h: g[i]) {
					if (clr[h] == -1) {
						clr[h] = 1;
					}
				}
			}
		} else {
			clr[i] = 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (clr[i] == 2) {
			kek.pb(i);
		}
	}
	cout << sz(kek) << '\n';
	for (auto x: kek) {
		cout << x << ' ';
	}
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 //	read(FILENAME);
 	int t;
 	cin >> t;
 	while (t--) {
 		solve();
 	}
	return 0;	 	
}