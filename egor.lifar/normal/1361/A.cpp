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
vector<int> g[MAXN];
int t[MAXN];
int c[MAXN];
int uk = 0;
int used[MAXN];


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
	vector<pair<int, int> > st;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		st.pb({t[i], i});
	}
	sort(all(st));
	vector<int> res;
	for (auto xx: st) {
		int x = xx.second;
		res.pb(x);
		uk++;
		for (auto y: g[x]) {
			if (c[y]) {
				used[c[y]] = uk;
			}
		}
		c[x] = 1;
		while (used[c[x]] == uk) {
			c[x]++;
		}
		if (c[x] != t[x]) {
			cout << -1 << '\n';;
			return 0;
		}
	}
	for (auto x: res) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0; 	
}