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
		cin.tie(nullptr);
	#endif
	int test; cin >> test;
	while (test--) {
		int n; cin >> n;
		vector<int> v(n);
		vector< pair<int, int> > kompr;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			kompr.emplace_back(v[i], i);
		}
		sort(begin(kompr), end(kompr));
		int k = 0;
		for (int i = 0; i < n; ++i) {
			if (i != 0 && kompr[i-1].first != kompr[i].first) {
				++k;
			}
			v[kompr[i].second] = k;
		}
		++k;
		vector<int> le(k, -1), ri(k);
		for (int i = 0; i < n; ++i) {
			if (le[v[i]] < 0) le[v[i]] = i;
			ri[v[i]] = i;
		}
		int subAns = 0;
		
		/*for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < k; ++i) {
			cout << le[i] << " " << ri[i] << endl;
		}*/
		
		for (int l = 0, r = 0; l < k; ++l) {
			if (r < l) r = l;
			while (r+1 < k && ri[r] < le[r+1]) {
				++r;
			}
			//~ cout << l << " - " << r << endl;
			subAns = max(subAns, r-l+1);
		}
		cout << k - subAns << "\n";
	}
	return 0;
}