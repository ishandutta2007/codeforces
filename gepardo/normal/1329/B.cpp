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

#define int int64_t
signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int t; cin >> t;
	while (t--) {
		int d, m; cin >> d >> m;
		vector<int> cb(30);
		for (int i = 0; i < 30; ++i) {
			int le = (1 << i), ri = (2 << i) - 1;
			if (le > d) break;
			ri = min(ri, d);
			cb[i] = (ri - le + 1) % m;
		}
		static int dp[30][30] = {};
		for (int i = 0; i < 30; ++i) {
			for (int j = 0; j < 30; ++j) {
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < 30; ++i) {
			dp[0][i] = cb[i];
		}
		for (int i = 1; i < 30; ++i) {
			for (int j = 0; j < 30; ++j) {
				for (int k = 0; k < j; ++k) {
					dp[i][j] += (dp[i-1][k] * cb[j]) % m;
					dp[i][j] %= m;
				}
			}
		}
		int soom = 0;
		for (int i = 0; i < 30; ++i) {
			for (int j = 0; j < 30; ++j) {
				soom += dp[i][j];
				soom %= m;
			}
		}
		cout << soom << "\n";
	}
	return 0;
}