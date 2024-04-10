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
	vector<int64_t> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		v[i] = min(v[i], v[i-1]);
	}
	reverse(v.begin(), v.end());
	
	vector<int64_t> dp(n);
	dp[0] = n * (v[0] - 1);
	for (int i = 1; i < n; i++) {
		int pos = i;
		int64_t add = 0;
		int64_t range = v[i] - 1;
		dp[i] = -1;
		while (true) {
			if (pos == 0) {
				dp[i] = max(dp[i], range * n + add);
				break;
			}
			int64_t dewither = range / v[pos-1];
			int64_t module = range % v[pos-1];
			dp[i] = max(dp[i], dp[pos-1] + add + (n - pos) * (dewither - 1) * v[pos-1]);
			add += (n - pos) * dewither * v[pos-1];
			pos = lower_bound(v.begin(), v.end(), module+1) - v.begin();
			range = module;
		}
	}
	
	cout << dp[n-1] << endl;
	return 0;
}