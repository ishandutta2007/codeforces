// Code written by gepardo
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
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

#define int int64_t

inline basic_string<int64_t> arith(int64_t n, int64_t base, int64_t step) {
	basic_string<int64_t> res;
	for (int i = 0; i < n; i++) {
		res += base;
		base += step;
	}
	return res;
}

inline int ask(basic_string<int64_t> b) {
	cout << b.size();
	for (int64_t i: b) {
		cout << " " << i;
	}
	cout << endl;
	int x; cin >> x;
	if (x == -2) {
		exit(42);
	}
	if (x == -1) {
		exit(0);
	}
	return x;
}

inline void simpleGuess(int64_t l, int64_t r, int knt, int att) {
	for (int i = 0; i < att; i++) {
		if (r-l+1 <= knt) {
			ask(arith(r-l+1, l, 1));
			exit(42);
		}
		int64_t delta = (r-l+1-knt) / (knt+1);
		int64_t mod = (r-l+1-knt) % (knt+1);
		int64_t val = l;
		basic_string<int64_t> bounds;
		bounds += l-1;
		for (int i = 1; i <= knt; i++) {
			int64_t add = delta + (i <= mod);
			val += add;
			bounds += val;
			val++;
		}
		bounds += r+1;
		int q = ask(bounds.substr(1, knt));
		l = bounds[q]+1;
		r = bounds[q+1]-1;
	}
	exit(42);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	if (ask({204761410474}) == 0) {
		if (ask({2046}) == 0) {
			if (ask({6}) == 0) {
				if (ask({2}) == 0) {
					ask({1});
				} else {
					ask(arith(3, 3, 1));
				}
			} else {
				int64_t q = ask({14, 30, 62, 126, 254, 510, 1022});
				int64_t w = (8 << q) - 1;
				ask(arith(w, w, 1));
			}
		} else {
			int64_t base1 = 20468427, step1 = 100020001;
			int w1 = ask(arith(2047, base1, step1));
			if (w1 == 0) {
				int64_t base2 = 16382, step2 = 10001;
				int w2 = ask(basic_string<int64_t> {4094, 8190} + arith(2045, base2, step2));
				if (w2 <= 2) {
					int64_t abase = (2048 << w2) - 1;
					ask(arith(abase, abase, 1));
				} else {
					ask(arith(10000, base2 + (w2-3)*step2 + 1, 1));
				}
			} else {
				simpleGuess(base1 + (w1-1)*step1 + 1, base1 + w1*step1 - 1, 10000, 2);
			}
		}
	} else {
		simpleGuess(204761410475, 10004205361450474, 10000, 4);
	}
	return 42;
}