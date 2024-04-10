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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	
	auto canTake = [&](vector<int> v) {
		vector<char> has(n+1, false);
		assert(int(v.size()) == 2*n);
		for (int i = 0; i < n; ++i) {
			has[v[i]] = true;
		}
		for (int i = 0; i < n; ++i) {
			if (!has[i+1]) {
				return false;
			}
			has[v[n+i]] = true;
		}
		return true;
	};
	
	if (b.back() != 0) {
		vector<int> substr(end(b) - b.back(), end(b));
		bool ok = true;
		for (int i = 0; i < b.back(); ++i) {
			if (substr[i] != i+1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			vector<int> full = a;
			full.insert(end(full), begin(b), end(b) - b.back());
			full.insert(begin(full), begin(substr), end(substr));
			if (canTake(full)) {
				cout << n-b.back() << endl;
				return 0;
			}
		}
	}
	
	auto ok = [&](int zero) {
		vector<int> q;
		for (int i = 0; i < n; ++i) {
			if (!a[i] && zero) {
				--zero;
			} else {
				q.push_back(a[i]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!b[i] && zero) {
				--zero;
			} else {
				q.push_back(b[i]);
			}
		}
		q.resize(2*n, 0);
		return canTake(q);
	};
	
	int l = 0, r = n;
	while (l != r) {
		int m = (l + r) / 2;
		if (ok(m)) {
			r = m;
		} else {
			l = m+1;
		}
	}
	cout << n+l << endl;
	
	return 0;
}