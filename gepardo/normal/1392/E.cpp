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
	//~ #define LOCAL_INPUT_FILE
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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int64_t a[25][25] = {};
	for (int i = 0; i < 25; ++i) {
		a[0][i] = i == 0 ? 0 : ((int64_t)1 << (i-1));
	}
	for (int i = 1; i < 25; ++i) {
		a[i][0] = 0;
		for (int j = 1; j < 25; ++j) {
			a[i][j] = a[i][j-1] + a[i-1][j];
		}
	}
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	uint64_t C[60][60] = {};
	for (int i = 0; i < 60; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
	int q; cin >> q;
	while (q--) {
		uint64_t vv; cin >> vv;
		for (int i = 0; i < n-1; ++i) {
			vv -= C[2*n-2][i];
		}
		string s;
		int x = 0, y = 0;
		for (int i = 0; i < 2*n-2; ++i) {
			if (x == n-1) {
				++y;
				s += 'R';
			} else if (y == n-1) {
				++x;
				s += 'D';
			} else {
				int qn = 2*n-2 - i - 1;
				int qk = n-1 - y - 1;
				if (vv >= C[qn][qk]) {
					++x;
					s += 'D';
					vv -= C[qn][qk];
				} else {
					++y;
					s += 'R';
				}
			}
		}
		reverse(begin(s), end(s));
		x = 1; y = 1;
		cout << x << " " << y << endl;
		for (char c : s) {
			++(c == 'R' ? y : x);
			cout << x << " " << y << endl;
		}
	}
	return 0;
}