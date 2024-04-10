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
const int64_t mod = 998244353; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

int64_t extGcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int64_t x1, y1;
	int64_t g = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}

inline int64_t inverse(int64_t a, int64_t m) {
	int64_t x, y;
	int64_t g = extGcd(a, m, x, y);
	assert(g == 1);
	return (x % m + m) % m;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> w(n);
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	
	int64_t sp = 0, sm = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			sm += w[i];
		} else {
			sp += w[i];
		}
	}
	
	static int64_t dp[3042][3042] = {};
	dp[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (dp[i][j] == 0) {
				continue;
			}
			int64_t w1 = sm - i + j, w2 = sp + j;
			int64_t iw = inverse((w1+w2) % mod, mod);
			dp[i+1][j] += dp[i][j] * w1 % mod * iw % mod;
			dp[i+1][j] %= mod;
			dp[i+1][j+1] += dp[i][j] * w2 % mod * iw % mod;
			dp[i+1][j+1] %= mod;
		}
	}	
	
	static int64_t d2[3042][3042] = {};
	for (int p = 0; p < n; ++p) {
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= m; ++j) {
				d2[i][j] = 0;
			}
		}
		int64_t res = 0;
		int sgn = a[p] ? +1 : -1;
		int64_t sum = a[p] ? sp : sm;
		d2[0][0] = 1;
		for (int i = 0; i <= m; ++i) {
			if (sum + sgn*i == 0) {
				break;
			}
			for (int j = 0; j <= i; ++j) {
				int64_t inv = inverse((sum + sgn*i + mod) % mod, mod);
				d2[i+1][j] += (sum + sgn*i - w[p] - sgn*j + 2*mod) % mod * d2[i][j] % mod * inv % mod;
				d2[i+1][j] %= mod;
				d2[i+1][j+1] += (w[p] + sgn*j + mod) % mod * d2[i][j] % mod * inv % mod;
				res += dp[m][a[p] ? i : m-i] * d2[i][j] % mod * (w[p] + sgn*j + mod) % mod;
				res %= mod;
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}