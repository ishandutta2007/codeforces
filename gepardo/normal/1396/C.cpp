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

const int S1 = 0;
const int S2B = 1;
const int S2 = 2;
const int S3B = 3;
const int S3 = 4;

inline void upd(int64_t &a, int64_t b, int64_t c) {
	if (b != LLONG_MAX) {
		a = min(a, b+c);
	}
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	const int mx = 1000042;
	static int64_t dp[mx][5];
	for (int i = 0; i < mx; ++i) {
		for (int j = 0; j < 5; ++j) {
			dp[i][j] = LLONG_MAX;
		}
	}
	int n;
	int64_t r1, r2, r3, d;
	cin >> n >> r1 >> r2 >> r3 >> d;
	vector<int64_t> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	dp[0][S1] = 0;
	for (int i = 0; i < n; ++i) {
		int64_t x = r1*a[i] + r3;
		int64_t o = min(r1 * (a[i]+1), r2) + r1;
		
		//~ cout << i << " : " << x << " " << o << endl;
		
		upd(dp[i+1][S1], dp[i][S1], x);
		upd(dp[i+1][S2B], dp[i][S1], min(x, o));
		upd(dp[i+1][S3B], dp[i][S1], min(x, o));
		
		upd(dp[i+1][S2], dp[i][S2B], min(x, o) + d);
		
		upd(dp[i+1][S3], dp[i][S3B], min(x, o) + 2*d);
		upd(dp[i+1][S1], dp[i][S3B], min(x, o) + 2*d);
		
		upd(dp[i+1][S2], dp[i][S2], min(x, o) + d);
		
		upd(dp[i+1][S3], dp[i][S3], min(x, o) + 2*d);
		upd(dp[i+1][S1], dp[i][S3], x);
		
		if (i == n-1) {
			upd(dp[i+1][S1], dp[i][S2], x + d);
			upd(dp[i+1][S1], dp[i][S2B], x + d);
		}
		
		//~ cout << dp[i+1][S1] << " - " << dp[i+1][S2B] << " " << dp[i+1][S2] << " - " << dp[i+1][S3B] << " " << dp[i+1][S3] << endl;
	}
	cout << min(dp[n][S1], min(dp[n][S3], dp[n][S3B] + 2*d)) + (n-1)*d << endl;
	return 0;
}