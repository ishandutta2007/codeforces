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
	vector<int> a(n);
	map<int, int> kompr;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		kompr[a[i]] = 42;
	}
	int k = 0;
	for (auto &it : kompr) {
		it.second = k++;
	}
	for (int &i : a) {
		i = kompr[i];
	}
	
	vector< pair<int, int> > ans;
	
	vector< pair<int, int> > must;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (a[i] > a[j]) {
				must.emplace_back(i+1, j+1);
			}
		}
	}
	
	for (int p = 1; p < k; ++p) {
		for (int i = 0; i < n; ++i) {
			if (a[i] != p) continue;
			a[i] = -1;
			for (int j = n-1; j > i; --j) {
				if (a[j] < p) {
					swap(a[i], a[j]);
					ans.emplace_back(i+1, j+1);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] < 0) a[i] = p;
		}
	}
	
	
	cout << ans.size() << endl;
	for (auto [a, b] : ans) {
		cout << a << " " << b << "\n";
	}
	
	assert(is_sorted(begin(a), end(a)));
	sort(begin(ans), end(ans));
	assert(must == ans);
	
	return 0;
}