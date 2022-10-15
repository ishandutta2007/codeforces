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

inline int init() {
	int n; cin >> n;
	return n;
}

inline int query(int a) {
	cout << "? " << a+1 << endl;
	int num; cin >> num;
	return num;
}

inline void accept(int x) {
	cout << "! " << (x < 0 ? -1 : x+1) << endl;
	exit(0);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n = init(), h = n / 2;
	if (h & 1) {
		accept(-1);
	}
	int a = query(0), b = query(h);
	if (a == b) {
		accept(0);
	}
	int s1 = 0, s2 = h;
	if (a > b) {
		swap(s1, s2);
	}
	int l = 0, r = h-1;
	while (l != r) {
		int m = (l + r + 1) / 2;
		int a = query(m + s1), b = query(m + s2);
		if (a == b) {
			accept(m);
		}
		if (a < b) {
			l = m;
		} else {
			r = m-1;
		}
	}
	if (query(l + s1) == query(l + s2)) {
		accept(l);
	}
	assert(false);
}