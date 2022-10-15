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
#define int int64_t

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
const int mod = module;
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

struct Fenwick {
	int n;
	vector<int64_t> a;
	
	inline void modify(int v, int64_t delta) {
		for (; v < n; v |= v+1) {
			a[v] += delta;
		}
	}
	
	inline int64_t sum(int v) {
		int64_t res = 0;
		for (; v >= 0; v &= v+1, --v) {
			res += a[v];
		}
		return res;
	}
	
	Fenwick(int n)
		: n(n), a(n) {}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int64_t n, m, k; cin >> n >> m >> k;
	vector<int64_t> v(m);
	for (int i = 0; i < m; ++i) {
		cin >> v[i]; --v[i];
	}
	/*Fenwick f(m);
	f.modify(0, v[0]);
	for (int i = 1; i < m; ++i) {
		f.modify(i, v[i] - v[i-1]);
	}*/
	int64_t glob = 0;
	int64_t ans = 0;
	for (int ptr = 0; ptr < m; ) {
		int idx = ptr;
		int64_t pg = (v[ptr] - glob) / k;
		while (idx < m && pg == (v[idx] - glob) / k) {
			++idx;
		}
		++ans;
		glob += idx - ptr;
		ptr = idx;
	}
	cout << ans << endl;
	return 0;
}