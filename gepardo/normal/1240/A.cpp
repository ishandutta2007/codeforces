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
	int test; cin >> test;
	while (test--) {
		int n; cin >> n;
		vector<int64_t> p(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
		}
		int64_t x, a, y, b; cin >> x >> a >> y >> b;
		if (x < y) {
			swap(x, y);
			swap(a, b);
		}
		int64_t both = a * b / gcd(a, b);
		int64_t k; cin >> k;
		sort(begin(p), end(p));
		reverse(begin(p), end(p));
		vector<int64_t> ps(n+1);
		ps[0] = 0;
		for (int i = 0; i < n; ++i) {
			ps[i+1] = ps[i] + p[i];
		}
		bool ok = false;
		for (int i = 0; i <= n; ++i) {
			int ka = i/a, kb = i/b, kab = i/both;
			int64_t earn = ps[ka] * x / 100 + (ps[ka+kb-kab] - ps[ka] + ps[kab]) * y / 100;
			if (k <= earn) {
				cout << i << "\n";
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << "-1\n";
		}
	}
	return 0;
}