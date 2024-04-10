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
const int mod = 998244353; 
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
	vector<int> a(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i]; --a[i];
	}
	
	assert(n == m);
	static int64_t dp[501][501] = {};
	for (int i = 1; i <= n; ++i) {
		dp[i][i-1] = 1;
	}
	for (int i = 0; i < n; ++i) {
		dp[i][i] = 1;
	}
	for (int l = n-1; l >= 0; --l) {
		for (int r = l+1; r < n; ++r) {
			dp[l][r] = 0;
			int mn = l;
			for (int k = l; k <= r; ++k) {
				if (a[k] < a[mn]) {
					mn = k;
				}
				int64_t q = (mn == 0) ? 1 : dp[l][mn-1];
				dp[l][r] += q * dp[mn+1][k] % mod * dp[k+1][r] % mod;
				dp[l][r] %= mod;
			}
		}
	}
	cout << dp[0][n-1] << endl;
	return 0;
}