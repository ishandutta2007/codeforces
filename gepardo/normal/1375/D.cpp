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

inline int mex(const vector<int>& a) {
	int n = a.size();
	vector<int> has(n+1, 0);
	for (int i : a) {
		++has[i];
	}
	int p = 0;
	while (has[p]) ++p;
	return p;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> idx;
		for (int p = 0; p < n; ++p) {
			if (a[p] == p) {
				continue;
			}
			while (true) {
				int mx = mex(a);
				if (mx == n) break;
				assert(a[mx] != mx);
				idx.push_back(mx);
				a[mx] = mx;
			}
			if (a[p] == p) {
				continue;
			}
			for (int i = 0; i < n; ++i) {
				if (a[i] == p) {
					assert(mex(a) == n);
					idx.push_back(i);
					a[i] = n;
					break;
				}
			}
			assert(mex(a) == p);
			idx.push_back(p);
			a[p] = p;
		}
		assert((int)idx.size() <= 2*n);
		for (int i = 0; i < n; ++i) {
			assert(a[i] == i);
		}
		cout << idx.size() << "\n";
		for (int i : idx) {
			cout << i+1 << " ";
		}
		cout << "\n";
	}
	return 0;
}