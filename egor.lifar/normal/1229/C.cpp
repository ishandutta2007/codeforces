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
const string FILENAME = "input";
const int MAXN = 100228;
const int BLOCK = 350;

int n, m;
vector<int> g[MAXN];
bool big[MAXN];
vector<int> gb[MAXN];
int cntless[MAXN];
int c[MAXN];
ll cntb[MAXN];
ll cntg[MAXN];
ll cntf[MAXN];
int kt[MAXN];
int last[MAXN];
vector<int> bigger[MAXN];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n >> m;
 	for (int i = 0; i < m; i++) {
 		int a, b;
 		cin >> a >> b;
 		g[a].pb(b);
 		g[b].pb(a);
 	}
 	for (int i = 1; i <= n; i++) {
 		c[i] = i;
 	}
 	int q;
 	cin >> q;
 	for (int i = 1; i <= n; i++) {
 		if (sz(g[i]) >= 1) {
 			big[i] = true;
 		}
 	}
 	for (int i = 1; i <= n; i++) {
 		for (auto x: g[i]) {
 			if (x < i) {
 				cntless[i]++;
 			}
 			if (big[x]) {
 				gb[i].pb(x);
 			}
 		}
 	}
 	long long res = 0;
 	for (int i = 1; i <= n; i++) {
 		for (auto x: g[i]) {
 			if (x < i) {
 				res += cntless[x];
 			} else {
 				bigger[i].pb(x);
 				cntb[i] += cntless[i];
 			}
 		}
 	}
 	cout << res << '\n';
 	int uk = n + 1;
 	int psum = 0;
 	for (int it = 1; it <= q; it++) {
 		int u;
 		cin >> u;
 		for (auto x: bigger[u]) {
 			cntb[x] -= sz(bigger[x]);
 			res -= sz(bigger[x]);
 			bigger[x].pb(u);
 			res += sz(g[x]) - sz(bigger[x]);
 			cntb[x] += sz(g[x]) - sz(bigger[x]);
 		}	
 		res -= cntb[u];
 		cntb[u] = 0;
 		bigger[u].clear();
 		cout << res << endl;
 	}
	return 0; 	
}