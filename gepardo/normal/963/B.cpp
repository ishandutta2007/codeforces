// Code by gepardo
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
	//#define LOCAL_INPUT_FILE
#else
	//#define USE_FILE_IO
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
	int n; cin >> n;
	int root = 0;
	vector< vector<int> > g(n);
	bool rooted = false;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x != 0) {
			g[x-1].push_back(i);
			g[i].push_back(x-1);
		} else {
			assert(!rooted);
			rooted = true;
		}
	}
	
	vector<char> d0(n), d1(n);
	vector< basic_string<int> > bef(n);
	
	function<void(int, int)> dfs = [&](int v, int p) {
		basic_string<int> l0, l1;
		for (int to: g[v]) {
			if (to == p) {
				continue;
			}
			dfs(to, v);
			if (d0[to] && d1[to]) {
				assert(false);
			} else if (d0[to]) {
				l0.push_back(to);
			} else if (d1[to]) {
				l1.push_back(to);
			} else {
				assert(false);
			}
		}
		int p0 = (g[v].size() & 1);
		if (p >= 0) {
			p0 ^= 1;
		}
		bef[v] = l1 + v + l0;
		if (p0 ^ (l1.size() & 1)) {
			d1[v] = true;
		} else {
			d0[v] = true;
		}
	};
	dfs(root, -1);
	
	for (int i = 0; i < n; i++) {
		assert(d0[i] ^ d1[i]);
	}
	
	if (!d0[root]) {
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	function<void(int)> rkn = [&](int v) {
		for (int i: bef[v]) {
			if (i == v) {
				cout << v+1 << "\n";
			} else {
				rkn(i);
			}
		}
	};
	rkn(root);
	
	return 0;
}