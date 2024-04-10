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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
	#endif
	int test; cin >> test;
	while (test--) {
		int n, k; cin >> n >> k;
		
		vector< vector< pair<int, int> > > g(n);
		for (int i = 1; i < n; ++i) {
			int a, b, c; cin >> a >> b >> c; --a; --b;
			g[a].emplace_back(b, c);
			g[b].emplace_back(a, c);
		}
		
		// 0 - no edge up
		// 1 - edge up (also counted in the DP)
		vector<int64_t> d0(n), d1(n);
		
		function<void(int, int)> dfs = [&](int v, int p) {
			
			int64_t sum = 0;
			vector<int64_t> diffs;
			int64_t eup = -1;
			
			for (auto [to, w] : g[v]) {
				if (to == p) {
					eup = w;
					continue;
				}
				dfs(to, v);
				sum += d0[to];
				int64_t diff = d1[to] - d0[to];
				if (diff > 0) {
					diffs.push_back(diff);
				}
			}
			if (p >= 0) {
				assert(eup >= 0);
			}
			
			int sz = diffs.size();
			sort(begin(diffs), end(diffs));
			reverse(begin(diffs), end(diffs));
			diffs.insert(begin(diffs), 0);
			for (int i = 1; i < (int)diffs.size(); ++i) {
				diffs[i] += diffs[i-1];
			}
			
			//~ cout << "v = " << v+1 << " : ";
			//~ for (int64_t i : diffs) {
				//~ cout << i << " ";
			//~ }
			//~ cout << endl;
			
			auto calcFor = [&](int k) {
				if (k > sz) k = sz;
				return diffs[k];
			};
			
			d0[v] = sum + calcFor(k);
			d1[v] = sum + eup + calcFor(k-1);
		};
		dfs(0, -1);
		
		//~ for (int i = 0; i < n; ++i) {
			//~ cout << d0[i] << " " << d1[i] << "\n";
		//~ }
		
		cout << d0[0] << "\n";
	}
	return 0;
}