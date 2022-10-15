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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n, m; cin >> n >> m;
	vector< vector<int> > g(n);
	vector< vector<int> > gg(n);
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
		gg[b].push_back(a);
	}
	
	{
		vector<int> ts(n);
		int cnt = 0;
		vector<char> used(n, false);
		function<void(int)> dfs1 = [&](int v) {
			if (used[v]) return;
			used[v] = true;
			for (int to : g[v]) {
				dfs1(to);
			}
			ts[v] = cnt++;
		};
		for (int i = 0; i < n; ++i) {
			dfs1(i);
		}
		for (int v = 0; v < n; ++v) {
			for (int to : g[v]) {
				if (ts[v] <= ts[to]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	
	vector<char> up(n, false);
	vector<char> down(n, false);
	string ans(n, 'E');
	int knt = 0;
	
	function<void(int)> d1 = [&](int v) {
		if (up[v]) return;
		up[v] = true;
		for (int to : gg[v]) {
			d1(to);
		}
	};
	
	function<void(int)> d2 = [&](int v) {
		if (down[v]) return;
		down[v] = true;
		for (int to : g[v]) {
			d2(to);
		}
	};
	
	for (int v = 0; v < n; ++v) {
		if (!up[v] && !down[v]) {
			ans[v] = 'A';
			++knt;
		}
		d1(v);
		d2(v);
	}
	cout << knt << endl << ans << endl;
	
	return 0;
}