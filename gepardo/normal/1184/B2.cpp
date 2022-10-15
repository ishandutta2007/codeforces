#ifdef DEBUG
	#define _GLIBCXX_DEBUG
#endif
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//~ #define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

struct Kuhn {
	int n, m;
	vector< vector<int> > g;
	vector<int> mt;
	vector<char> used, used1;
	
	bool dfs(int v) {
		if (used[v]) {
			return false;
		}
		used[v] = true;
		for (int to: g[v]) {
			if (mt[to] < 0 || dfs(mt[to])) {
				mt[to] = v;
				return true;
			}
		}
		return false;
	}
	
	inline vector< pair<int, int> > findMatching() {
		for (int i = 0; i < n; i++) {
			for (int to: g[i]) {
				if (mt[to] < 0) {
					mt[to] = i;
					used1[i] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (!used1[i]) {
				used.assign(n, false);
				dfs(i);
			}
		}
		vector< pair<int, int> > ans;
		for (int i = 0; i < m; i++) {
			if (mt[i] >= 0) {
				ans.emplace_back(mt[i], i);
			}
		}
		return ans;
	}
	
	Kuhn(int n, int m)
		: n(n), m(m), g(n), mt(m, -1), used(n, false), used1(n, false) {
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	static int g[120][120];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			g[i][j] = (i == j) ? 0 : infinity;
		}
	}
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b; --a; --b;
		if (a != b) {
			g[a][b] = g[b][a] = 1;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][k] < infinity && g[k][j] < infinity) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
	}
	int s, b, k, h; cin >> s >> b >> k >> h;
	vector<int> sx(s), sa(s), sf(s);
	for (int i = 0; i < s; ++i) {
		cin >> sx[i] >> sa[i] >> sf[i]; --sx[i];
	}
	vector<int> bx(b), bd(b);
	for (int i = 0; i < b; ++i) {
		cin >> bx[i] >> bd[i]; --bx[i];
	}
	vector< vector<int> > g2(s);
	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < b; ++j) {
			if (sa[i] >= bd[j] && sf[i] >= g[sx[i]][bx[j]]) {
				g2[i].push_back(j);
			}
		}
	}
	Kuhn kk(s, b);
	kk.g = g2;
	int mt = kk.findMatching().size();
	int64_t ans = llInfinity;
	for (int i = 0; i <= s; ++i) {
		int attacked = min(s, mt+i);
		int64_t attackedReal = max(0, attacked - i);
		ans = min(ans, (int64_t)i * h + attackedReal * k);
	}
	cout << ans << endl;
	return 0;
}