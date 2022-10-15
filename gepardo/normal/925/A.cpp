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
	//#define LOCAL_INPUT_FILE
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
	int n, m, cl, ce, v; cin >> n >> m >> cl >> ce >> v;
	vector<int> l(cl), e(ce);
	for (int i = 0; i < cl; i++) {
		cin >> l[i]; l[i]--;
	}
	for (int i = 0; i < ce; i++) {
		cin >> e[i]; e[i]--;
	}
	sort(l.begin(), l.end());
	sort(e.begin(), e.end());
	int q; cin >> q;
	for (int w = 0; w < q; w++) {
		int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2; x1--; y1--; x2--; y2--;
		int l1 = lower_bound(l.begin(), l.end(), x1) - l.begin();
		int l2 = lower_bound(l.begin(), l.end(), x2) - l.begin();
		int e1 = lower_bound(e.begin(), e.end(), x1) - e.begin();
		int e2 = lower_bound(e.begin(), e.end(), x2) - e.begin();
		int ans = INT_MAX;
		if (y1 == y2) {
			ans = abs(x1 - x2);
		}
		for (int i = max(0, l1-1); i <= l1+1 && i < cl; i++) {
			ans = min(ans, abs(y1 - y2) + abs(x1 - l[i]) + abs(l[i] - x2));
		}
		for (int i = max(0, l2-1); i <= l2+1 && i < cl; i++) {
			ans = min(ans, abs(y1 - y2) + abs(x1 - l[i]) + abs(l[i] - x2));
		}
		for (int i = max(0, e1-1); i <= e1+1 && i < ce; i++) {
			ans = min(ans, abs(y1 - y2) + abs(x1 - e[i]) + abs(e[i] - x2));
		}
		for (int i = max(0, e2-1); i <= e2+1 && i < ce; i++) {
			ans = min(ans, (abs(y1 - y2) + v - 1) / v + abs(x1 - e[i]) + abs(e[i] - x2));
		}
		cout << ans << "\n";
	}
	return 0;
}