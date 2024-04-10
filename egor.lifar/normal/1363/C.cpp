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


int n, x;
vector<int> g[MAXN];


int dfs(int u, int pr) {
	int val = 1;
	for (auto h: g[u]) {
		if (h != pr) {
			val += dfs(h, u);
		}
	}
	return val;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		cin >> n >> x;
		x--;
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			a--, b--;;
			g[a].pb(b);
			g[b].pb(a);
		}
		if (sz(g[x]) <= 1) {
			cout << "Ayush\n";
			continue;
		}
		vector<int> st;
		for (auto y: g[x]) {
			st.pb(dfs(y, x));
		}
		sort(all(st));
		int kek = 0;
		for (int i = 0; i < sz(st) - 1; i++) {
			kek += st[i];
		}
		if (n & 1) {
			cout << "Ashish\n";
		} else {
			cout << "Ayush\n";
		}
	}
	return 0; 	
}