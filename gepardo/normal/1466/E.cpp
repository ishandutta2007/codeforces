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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int64_t> v(n);
		int mxb = 62;
		vector<int64_t> p2(mxb);
		p2[0] = 1;
		for (int i = 1; i < mxb; ++i) {
			p2[i] = p2[i-1] * 2 % module;
		}
		vector<int64_t> o(mxb);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			for (int j = 0; j < mxb; ++j) {
				o[j] += (v[i] >> j) & 1;
			}
		}
		int64_t ans = 0;
		for (int64_t x : v) {
			int64_t le = 0, ri = 0;
			for (int j = 0; j < mxb; ++j) {
				if ((x >> j) & 1) {
					le += o[j] * p2[j] % module;
					le %= module;
					ri += n * p2[j] % module;
					ri %= module;
				} else {
					ri += o[j] * p2[j] % module;
					ri %= module;
				}
			}
			ans += le * ri % module;
			ans %= module;
		}
		cout << ans << endl;
	}
	return 0;
}