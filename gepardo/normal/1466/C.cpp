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
	
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.size();
		if (n == 1) {
			cout << 0 << "\n";
			continue;
		}
		vector<vector<int>> dp(n-1, vector<int>(4, infinity));
		dp[0][0] = 0;
		dp[0][1] = 1;
		dp[0][2] = 1;
		dp[0][3] = 2;
		if (s[0] == s[1]) {
			dp[0][0] = infinity;
		}
		for (int i = 1; i < n-1; ++i) {
			dp[i][0] = min(dp[i-1][2], s[i+1] == s[i-1] ? infinity : dp[i-1][0]);
			dp[i][2] = min(dp[i-1][3], s[i+1] == s[i-1] ? infinity : dp[i-1][1]);
			dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + 1;
			dp[i][3] = min(dp[i-1][3], dp[i-1][1]) + 1;
			if (s[i] == s[i+1]) {
				dp[i][0] = infinity;
			}
		}
		cout << *min_element(dp.back().begin(), dp.back().end()) << "\n";
	}
	
	return 0;
}