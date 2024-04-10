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

template<typename T>
inline T abs(T a) {
	return a < 0 ? -a : a;
}

__int128 extGcd(__int128 a, __int128 b, __int128 &x, __int128 &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	__int128 x1, y1;
	__int128 g = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}

inline bool diophantSolve(
	__int128 a, __int128 b, __int128 c,
	__int128 &x, __int128 &y,
	__int128 &xStep, __int128 &yStep
) {
	__int128 g = extGcd(abs(a), abs(b), x, y);
	if (c % g != 0) {
		return false;
	}
	x *= c / g;
	y *= c / g;
	if (a < 0) {
		x *= -1;
	}
	if (b < 0) {
		y *= -1;
	}
	xStep = b / g;
	yStep = -a / g;
	return true;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector<int64_t> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	if (n == 1) {
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		cout << -v[0] << endl;
		return 0;
	}
	vector<int64_t> d1, d2;
	for (int i = 0; i < n-1; ++i) {
		__int128 x, y, xStep, yStep;
		bool ok = diophantSolve(n, n-1, -v[i], x, y, xStep, yStep);
		assert(ok);
		assert(abs((__int128)n * x) <= (__int128)1e18);
		assert(abs((__int128)(n-1) * y) <= (__int128)1e18);
		assert(n*x + (n-1)*y == -v[i]);
		d1.push_back(n*x);
		d2.push_back((n-1)*y);
	}
	d1.push_back(0);
	cout << 1 << " " << n << endl;
	for (int64_t i : d1) {
		cout << i << " ";
	}
	cout << endl;
	cout << 1 << " " << n-1 << endl;
	for (int64_t i : d2) {
		cout << i << " ";
	}
	cout << endl;
	cout << n << " " << n << endl;
	cout << -v.back() << endl;
	return 0;
}