// The code was written by gepardo
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

inline void raiseError(const string &description) {
	cerr << "Error : " << description << endl;
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

inline int64_t binPow(int64_t a, int64_t n, int64_t m) {
	int64_t res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;
	}
	return res;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n, m, a, b; cin >> n >> m >> a >> b;
	const int mod = int(1e9 + 7);
	
	int64_t mx = max(n, m) + 42;
	vector<int64_t> f(mx+1), r(mx+1), pm(mx+1), pn(mx+1);
	f[0] = 1;
	for (int i = 1; i <= mx; ++i) {
		f[i] = f[i-1] * i;
		f[i] %= mod;
	}
	for (int i = 0; i <= mx; ++i) {
		r[i] = inverse(f[i], mod);
	}
	pm[0] = 1;
	for (int i = 1; i <= mx; ++i) {
		pm[i] = pm[i-1] * m;
		pm[i] %= mod;
	}
	pn[0] = 1;
	for (int i = 1; i <= mx; ++i) {
		pn[i] = pn[i-1] * n;
		pn[i] %= mod;
	}
	
	auto C = [&](int n, int k) {
		if (k < 0 || k > n) {
			return int64_t(0);
		}
		return f[n] * r[k] % mod * r[n-k] % mod;
	};
	
	auto A = [&](int n, int k) {
		assert(k >= 0 && k <= n);
		return f[n] * r[n-k] % mod;
	};
	
	int64_t ans = 0;
	for (int k = 1; k < n && k <= m; ++k) {
		int64_t cur = C(m-1, k-1);
		cur *= A(n-2, k-1);
		cur %= mod;
		if (k != n-1) {
			cur *= k+1;
			cur %= mod;
			cur *= binPow(n, n-k-2, mod);
			cur %= mod;
		}
		cur *= pm[n-k-1];
		cur %= mod;
		ans += cur;
		ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}