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
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int mk = (n+1) / 2;
	static int dp[3000][8] = {}, pdp[3000][8] = {};
	for (int i = 0; i <= mk; i++) {
		for (int j = 0; j < 8; j++) {
			dp[i][j] = pdp[i][j] = INT_MAX;
		}
	}
	// left - 1, cur - 2, right - 4
	dp[0][0] = dp[0][4] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= mk; j++) {
			for (int k = 0; k < 8; k++) {
				pdp[j][k] = dp[j][k];
				dp[j][k] = INT_MAX;
			}
		}
		for (int j = 0; j <= mk; j++) {
			for (int k = 0; k < 8; k++) {
				if (pdp[j][k] == INT_MAX) {
					continue;
				}
				for (int l = 0; l < 2; l++) {
					int nk = (k >> 1) + (l << 2);
					if ((nk & 6) == 6 || (nk & 3) == 3) {
						continue;
					}
					int qVal = v[i];
					if (i != 0 && (nk & 1)) {
						qVal = min(qVal, v[i-1] - 1);
					}
					if (i != n-1 && (nk & 4)) {
						qVal = min(qVal, v[i+1] - 1);
					}
					int add = !!(nk & 2);
					dp[j+add][nk] = min(dp[j+add][nk], pdp[j][k] + v[i] - qVal);
				}
			}
		}
	}
	for (int i = 1; i <= mk; i++) {
		cout << *min_element(dp[i], dp[i] + 8) << " ";
	}
	cout << endl;
	return 0;
}