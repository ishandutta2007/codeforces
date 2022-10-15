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
const int mod = module;
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

const string win1 = "sjfnb";
const string win2 = "cslnb";

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector<int64_t> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	set<int64_t> st(begin(v), end(v));
	sort(begin(v), end(v));
	int eq = 0, eid = -1;
	for (int i = 1; i < n; ++i) {
		if (v[i] == v[i-1]) {
			++eq;
			eid = v[i];
		}
	}
	if (eq > 1) {
		cout << win2 << endl;
		return 0;
	}
	if (eq == 1 && (eid == 0 || st.count(eid-1))) {
		cout << win2 << endl;
		return 0;
	}
	int64_t knt = 0;
	for (int i = 0; i < n; ++i) {
		assert(v[i] >= i);
		knt += v[i] - i;
	}
	cout << ((knt & 1) ? win1 : win2) << endl;
	return 0;
}