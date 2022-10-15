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

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

inline uint64_t layer(uint64_t x) {
	uint64_t ans = 0;
	while (x) {
		ans++;
		x >>= 1;
	}
	return ans-1;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	vector<uint64_t> shifts(62);
	vector<uint64_t> ands(62);
	int n; cin >> n;
	for (int i = 0; i < 62; i++) {
		shifts[i] = 0;
		ands[i] = (uint64_t(1) << i) - 1;
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 1) {
			uint64_t q, k; cin >> q >> k;
			q = layer(q);
			k &= ands[q];
			shifts[q] += k;
			shifts[q] &= ands[q];
		} else if (x == 2) {
			uint64_t q, k; cin >> q >> k;
			q = layer(q);
			for (uint64_t j = q; j < 62; j++) {
				k &= ands[j];
				shifts[j] += k;
				shifts[j] &= ands[j];
				k *= 2;
			}
		} else if (x == 3) {
			uint64_t q; cin >> q;
			uint64_t l = layer(q);
			for (uint64_t j = l; j != 0; j--) {
				cout << q << " ";
				uint64_t shift = uint64_t(1) << j;
				uint64_t trunk = q - shift;
				trunk += shifts[j];
				trunk &= ands[j];
				q = (shift + trunk) >> 1;
				shift >>= 1;
				trunk = q - shift;
				trunk -= shifts[j-1];
				trunk &= ands[j-1];
				q = shift + trunk;
			}
			cout << 1 << "\n";
		} else {
			assert(false);
		}
		/*for (int i = 0; i < 5; i++) {
			cout << shifts[i] << " ";
		}
		cout << endl;*/
	}
	return 0;
}