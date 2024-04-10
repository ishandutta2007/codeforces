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

inline void no() {
	cout << -1 << endl;
	exit(0);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	
	int ch = 0, cv = 0;
	for (int i = 0; i < n; ++i) {
		int mn = -1, mx = -1, cnt = 0;
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == '.') continue;
			if (mn < 0) mn = j;
			mx = j;
			++cnt;
		}
		if (mn < 0) {
			++ch;
		} else if (cnt != mx-mn+1) {
			no();
		}
	}
	for (int j = 0; j < m; ++j) {
		int mn = -1, mx = -1, cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i][j] == '.') continue;
			if (mn < 0) mn = i;
			mx = i;
			++cnt;
		}
		if (mn < 0) {
			++cv;
		} else if (cnt != mx-mn+1) {
			no();
		}
	}
	if ((ch != 0 && cv == 0) || (ch == 0 && cv != 0)) {
		no();
	}
	
	vector< vector<char> > used(n, vector<char>(m, false));
	
	function<void(int, int)> dfs = [&](int x, int y) {
		if (!(0 <= x && x < n && 0 <= y && y < m && v[x][y] == '#')) return;
		if (used[x][y]) return;
		used[x][y] = true;
		dfs(x-1, y);
		dfs(x+1, y);
		dfs(x, y-1);
		dfs(x, y+1);
	};
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == '.' || used[i][j]) continue;
			dfs(i, j);
			++ans;
		}
	}
	cout << ans << endl;
	
	return 0;
}