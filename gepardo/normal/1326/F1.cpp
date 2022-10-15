#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
	
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	
	vector<int> masks;
	vector<int> mid(1 << n, -1);
	
	int p1 = n/2;
	int p2 = n - p1;
	
	static int d[3500][150][14] = {};
	for (int i = 0; i < (1 << n); ++i) {
		int pc = __builtin_popcount(i);
		if (pc != p1 && pc != p2) continue;
		mid[i] = masks.size();
		masks.push_back(i);
		int idx = mid[i];
		
		int arr[14];
		int sz = 0;
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				arr[sz++] = j;
			}
		}
		sort(arr, arr + pc);
		
		do {
			int msk = 0;
			for (int i = 1; i < pc; ++i) {
				msk <<= 1;
				msk |= v[arr[i-1]][arr[i]] - '0';
			}
			++d[idx][msk][arr[0]];
		} while (next_permutation(arr, arr + pc));
	}
	
	static vector< pair<int, int> > avail[3500];
	for (int i = 0; i < (int)masks.size(); ++i) {
		for (int j = 0; j < 150; ++j) {
			for (int k = 0; k < n; ++k) {
				if (d[i][j][k] != 0) {
					avail[i].emplace_back(j, k);
				}
			}
		}
	}
	
	/*for (int mm = 0; mm < (int)masks.size(); ++mm) {
		cout << "mask " << masks[mm] << endl;
		int sz = __builtin_popcount(masks[mm]) - 1;
		for (int i = 0; i < (1 << sz); ++i) {
			for (int j = 0; j < n; ++j) {
				cout << d[mm][i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
	
	vector<int> rev(1 << (p2-1));
	vector<int64_t> ans(1 << (n-1));
	
	for (int i = 0; i < (1 << (p2-1)); ++i) {
		int msk = 0;
		for (int j = 0; j+1 < p2; ++j) {
			msk <<= 1;
			msk |= (i >> j) & 1;
		}
		rev[i] = msk;
	}
	
	for (int mm = 0; mm < (int)masks.size(); ++mm) {
		if (__builtin_popcount(masks[mm]) != p1) continue;
		int pmm = mid[((1 << n) - 1) ^ masks[mm]];
		assert(pmm >= 0);
		for (int lm = 0; lm < (1 << (p1-1)); ++lm) {
			for (int i = 0; i < n; ++i) {
				if (!d[mm][lm][i]) continue;
				for (auto [rm, j] : avail[pmm]) {
					ans[lm | ((v[i][j] - '0') << (p1-1)) | (rev[rm] << p1)] += (int64_t)d[mm][lm][i] * d[pmm][rm][j];
				}
			}
		}
	}
	
	for (int64_t i : ans) {
		cout << i << " ";
	}
	cout << endl;
	
	/*for (int msk = 0; msk < (1 << (n-1)); ++msk) {
		int lm = msk & ((1 << (p1-1)) - 1);
		int bit = (msk >> (p1-1)) & 1;
		int rm = 0;
		for (int i = p1; i+1 < n; ++i) {
			rm <<= 1;
			rm |= (msk >> i) & 1;
		}
		assert(rm == (rev[msk >> p1]));
		
		int64_t ans = 0;
		for (int mm = 0; mm < (int)masks.size(); ++mm) {
			if (__builtin_popcount(masks[mm]) != p1) continue;
			int pmm = mid[((1 << n) - 1) ^ masks[mm]];
			assert(pmm >= 0);
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (v[i][j] - '0' != bit) continue;
					ans += (int64_t)d[mm][lm][i] * d[pmm][rm][j];
					//~ cout << masks[mm] << " " << masks[pmm] << " : " << i << " " << j << " : " << ans << endl;
				}
			}
		}
		//~ cout << "!!! ";
		cout << ans << " ";
		//~ cout << endl;
	}
	cout << endl;*/
	
	return 0;
}