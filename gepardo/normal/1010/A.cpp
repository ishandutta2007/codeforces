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
	int n, m; cin >> n >> m;
	vector< pair<int64_t, int64_t> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	
	auto ok = [&](long double fuel) {
		auto process = [&](int64_t delta) {
			fuel -= (m + fuel) / delta;
		};
		for (int i = 0; i < n; i++) {
			process(v[i].second);
			if (fuel < 0) {
				return false;
			}
			process(v[(i+1) % n].first);
			if (fuel < 0) {
				return false;
			}
		}
		return fuel >= 0;
	};
	
	long double l = 0, r = 1e20;
	for (int i = 0; i < 140; i++) {
		long double m = (l + r) / 2;
		if (ok(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	
	if (l > 1e18) {
		cout << -1 << endl;
	} else {
		cout << fixed << setprecision(10) << l << endl;
	}
	return 0;
}