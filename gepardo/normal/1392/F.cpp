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

inline vector<int64_t> naiveStep(vector<int64_t> v) {
	int n = v.size();
	auto res = v;
	for (int i = 0; i < n; ++i) {
		if (v[i] >= 2) {
			res[i] -= 2;
			if (i != 0) ++res[i-1];
			if (i != n-1) ++res[i+1];
		}
	}
	return res;
}

inline void out(vector<int64_t> v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		if (i) cout << " ";
		cout << v[i];
	}
	cout << endl;
}

inline vector<int64_t> calc(vector<int64_t> d) {
	int n = d.size();
	reverse(begin(d), end(d));
	int64_t sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += ((d[i]-1) % (n+1)) * (i+1);
		sum %= n+1;
	}
	sum += n;
	sum %= n+1;
	vector<int64_t> ans(n, 1);
	if (sum != n) ans[sum] = 0;
	return ans;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n; cin >> n;
	vector<int64_t> v(n);
	int64_t sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	vector<int64_t> d(n-1);
	for (int i = 0; i+1 < n; ++i) {
		d[i] = v[i+1] - v[i];
	}
	auto res = calc(d);
	vector<int64_t> ans(n);
	int64_t sum2 = 0;
	for (int i = 0; i+1 < n; ++i) {
		ans[i+1] = ans[i] + res[i];
		sum2 += ans[i+1];
	}
	sum -= sum2;
	assert(sum % n == 0);
	for (int i = 0; i < n; ++i) {
		ans[i] += sum / n;
	}
	out(ans);
	
	return 0;
}