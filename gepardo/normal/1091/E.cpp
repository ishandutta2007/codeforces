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

#define int int64_t

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
	int n; cin >> n; ++n;
	vector<int> v(n-1);
	for (int i = 0; i < n-1; ++i) {
		cin >> v[i];
	}
	sort(begin(v), end(v));
	reverse(begin(v), end(v));
	vector<int64_t> pinl(n), pinr(n);
	vector<int64_t> soom(n);
	for (int i = 0; i < n-1; ++i) {
		soom[i+1] = soom[i] + v[i];
	}
	
	auto sufSum = [&](int first, int k) {
		int pos = lower_bound(begin(v), end(v), k, greater<int>()) - begin(v);
		pos = max(pos, first);
		return soom.back() - soom[pos] + int64_t(k) * (pos-first);
	};
	
	for (int i = 1; i < n; ++i) {
		int64_t lPart = soom[i-1];
		int64_t rPart = int64_t(i) * (i-1) + sufSum(i-1, i);
		//~ cout << "i = " << i << " lpart = " << lPart << " rpart = " << rPart << endl;
		int64_t toAdd = rPart - lPart;
		pinl[i-1] = toAdd;
	}
	pinl[n-1] = n;
	
	for (int i = 1; i < n; ++i) {
		int64_t lPart = soom[i];
		int64_t rPart = int64_t(i) * (i-1) + sufSum(i, i);
		int64_t toAdd = lPart - rPart;
		//~ cout << "i = " << i << " lpart = " << lPart << " rpart = " << rPart << endl;
		pinr[i] = toAdd;
		if (pinr[i] > i) {
			pinr[i] = n + 42;
		}
	}
	pinr[0] = 0;
	
	//~ for (int i = 0; i < n; ++i) {
		//~ cout << pinl[i] << " ";
	//~ }
	//~ cout << endl;
	//~ for (int i = 0; i < n; ++i) {
		//~ cout << pinr[i] << " ";
	//~ }
	//~ cout << endl;
	
	for (int i = n-1; i > 0; --i) {
		pinl[i-1] = min(pinl[i-1], pinl[i]);
	}
	for (int i = 1; i < n; ++i) {
		pinr[i] = max(pinr[i], pinr[i-1]);
	}
	
	set<int> values;
	for (int i = 0; i < n; ++i) {
		int64_t lBound = max(int64_t(i == n-1 ? 0 : v[i]), pinr[i]);
		int64_t rBound = min(int64_t(i == 0 ? n-1 : v[i-1]), pinl[i]);
		if (lBound > rBound) {
			continue;
		}
		assert(0 <= lBound && lBound <= rBound && rBound < n);
		for (int j = lBound; j <= rBound; ++j) {
			values.insert(j);
		}
	}
	
	bool smth = false;
	for (int i: values) {
		if (i % 2 == soom.back() % 2) {
			cout << i << " ";
			smth = true;
		}
	}
	if (!smth) {
		cout << -1;
	}
	cout << endl;
	
	return 0;
}