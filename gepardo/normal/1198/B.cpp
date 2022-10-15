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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector < pair<int, int> > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = 0;
	}
	int time = 0;
	vector<int> xs {0};
	int q; cin >> q;
	while (time < q) {
		++time;
		int type; cin >> type;
		if (type == 1) {
			int p, v; cin >> p >> v; --p;
			a[p] = {v, time};
			xs.push_back(0);
		} else if (type == 2) {
			int x; cin >> x;
			xs.push_back(x);
		} else {
			assert(false);
		}
	}
	for (int i = int(xs.size()) - 2; i >= 0; --i) {
		xs[i] = max(xs[i], xs[i+1]);
	}
	for (int i = 0; i < n; ++i) {
		cout << max(a[i].first, xs[a[i].second]) << " ";
	}
	cout << endl;
	return 0;
}