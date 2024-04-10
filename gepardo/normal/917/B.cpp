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
	
	int n, m; cin >> n >> m;
	vector < vector< pair<int, char> > > g(n);
	for (int i = 0; i < m; i++) {
		int a, b; char c; cin >> a >> b >> c; a--; b--; 
		g[a].push_back({b, c});
	}
	
	vector<int> order;
	vector<char> used(n, false);
	
	function<void(int)> dfs = [&](int v) {
		if (used[v]) {
			return;
		}
		used[v] = true;
		for (auto i: g[v]) {
			dfs(i.first);
		}
		order.push_back(v);
	};
	for (int i = 0; i < n; i++) {
		dfs(i);
	}
	
	static bool dp[127][127][26][2] = {};
	
	for (int i: order) {
		for (int j: order) {
			for (int k = 25; k >= 0; k--) {
				dp[i][j][k][0] = dp[i][j][k][1] = false;
				if (k != 25) {
					dp[i][j][k][0] = dp[i][j][k+1][0];
					dp[i][j][k][1] = dp[i][j][k+1][1];
				}
				for (auto to: g[i]) {
					if (to.second - 'a' >= k && !dp[to.first][j][to.second - 'a'][1]) {
						dp[i][j][k][0] = true;
						break;
					}
				}
				for (auto to: g[j]) {
					if (to.second - 'a' >= k && !dp[i][to.first][to.second - 'a'][0]) {
						dp[i][j][k][1] = true;
						break;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (dp[i][j][0][0] ? "A" : "B");
		}
		cout << endl;
	}
	
	return 0;
}