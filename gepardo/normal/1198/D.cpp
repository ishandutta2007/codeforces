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
const int mod = module;
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
	static int dp[52][52][52][52] = {};
	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	static int s[52][52] = {};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + (a[i][j] == '#');
		}
	}
	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= n; ++k) {
				for (int l = 0; l <= n; ++l) {
					dp[i][j][k][l] = infinity;
				}
			}
		}
	}
	
	#define PRINT_CUR  // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " : " << dp[x1][y1][x2][y2] << endl;
	
	for (int x1 = n-1; x1 >= 0; --x1) {
		for (int y1 = n-1; y1 >= 0; --y1) {
			for (int x2 = x1; x2 < n; ++x2) {
				for (int y2 = y1; y2 < n; ++y2) {
					int ps = s[x2+1][y2+1] - s[x1][y2+1] - s[x2+1][y1] + s[x1][y1];
					if (ps == 0) {
						dp[x1][y1][x2][y2] = 0;
						PRINT_CUR;
						continue;
					}
					dp[x1][y1][x2][y2] = max(x2-x1+1, y2-y1+1);
					for (int sx = x1; sx < x2; ++sx) {
						//~ cout << "  -- split x at " << sx << " gave " << dp[x1][y1][sx][y2] + dp[sx+1][y1][x2][y2] << endl;
						assert(dp[x1][y1][sx][y2] != infinity);
						assert(dp[sx+1][y1][x2][y2] != infinity);
						dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dp[x1][y1][sx][y2] + dp[sx+1][y1][x2][y2]);
					}
					for (int sy = y1; sy < y2; ++sy) {
						//~ cout << "  -- split y at " << sy << " gave " << dp[x1][y1][x2][sy] + dp[x1][sy+1][x2][y2] << endl;
						assert(dp[x1][y1][x2][sy] != infinity);
						assert(dp[x1][sy+1][x2][y2] != infinity);
						dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dp[x1][y1][x2][sy] + dp[x1][sy+1][x2][y2]);
					}
					PRINT_CUR;
				}
			}
		}
	}
	
	cout << dp[0][0][n-1][n-1] << endl;
	return 0;
}