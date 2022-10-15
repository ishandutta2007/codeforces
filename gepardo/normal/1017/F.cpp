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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	uint32_t n, A, B, C, D; cin >> n >> A >> B >> C >> D;
	uint32_t ans = 0;
	const uint32_t rng = 100000;
	vector<char> prime(rng, true);
	prime[0] = prime[1] = false;
	assert((uint64_t)rng * rng > n);
	for (uint32_t i = 2; i < rng; i++) {
		if (prime[i]) {
			uint32_t f = D + i*(C + i*(B + i*A));
			uint32_t j = n, knt = 0;
			while (j) {
				j /= i;
				knt += j;
			}
			if (knt != 0) {
				//cout << i << " " << knt << endl;
				ans += f * knt;
			}
			for (uint32_t j = i*i; j < rng; j += i) {
				prime[j] = false;
			}
		}
	}
	for (uint32_t l = rng; l <= n; l += rng) {
		uint32_t r = min(l + rng, n+1);
		vector<char> pp(r-l, true);
		for (uint32_t i = 2; i < rng; i++) {
			if (prime[i]) {
				for (uint32_t j = (l+i-1) / i * i; j < r; j += i) {
					pp[j-l] = false;
				}
			}
		}
		for (uint32_t i = l; i < r; i++) {
			if (pp[i-l]) {
				uint32_t f = D + i*(C + i*(B + i*A));
				uint32_t knt = n/i;
				if (knt != 0) {
					//cout << i << " " << knt << endl;
					ans += f * knt;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}