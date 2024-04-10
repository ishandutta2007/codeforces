// Code by gepardo
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
const int module = (int)1e9 + 9; 
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

inline int64_t binPow(int64_t a, int n) {
	int64_t res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= module;
		}
		a *= a;
		a %= module;
		n >>= 1;
	}
	return res % module;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int64_t n, a, b, k; cin >> n >> a >> b >> k;
	int64_t mul = binPow(a, n);
	string s; cin >> s;
	a = inverse(a, module);
	vector<int64_t> ktr(k);
	a *= b; a %= module;
	int64_t q = binPow(a, k);
	int64_t m = (n+1) / k;
	int64_t stp;
	if (q == 1) {
		stp = m;
	} else {
		stp = (binPow(q, m) + module - 1) % module *
			inverse((q + module - 1) % module, module);
	}
	stp %= module;
	for (int i = 0; i < k; i++) {
		if (i == 0) {
			ktr[i] = stp;
		} else {
			ktr[i] = (ktr[i-1] * a) % module;
		}
	}
	for (int i = 0; i < k; i++) {
		if (s[i] == '-') {
			ktr[i] = module - ktr[i];
			ktr[i] %= module;
		}
	}
	int64_t ans = 0;
	for (int i = 0; i < k; i++) {
		ans += ktr[i];
		ans %= module;
	}
	cout << (ans * mul) % module << endl;
	return 0;
}