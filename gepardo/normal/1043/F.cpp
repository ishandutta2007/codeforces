// The code was written by gepardo
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

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(const string &description) {
	cerr << "Error : " << description << endl;
	exit(42);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	const int nknt = 314159;
	vector<char> has(nknt, false);
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		has[v[i]] = true;
	}
	vector< vector<int> > divs(nknt);
	vector<int> dc(nknt);
	for (int i = 1; i < nknt; ++i) {
		for (int j = i; j < nknt; j += i) {
			dc[i] += has[j];
			divs[j].push_back(i);
		}
	}
	vector<int> dp(nknt, INT_MAX);
	dp[1] = 0;
	
	vector<int> qp(nknt);
	
	for (int v = 2; v < nknt; ++v) {
		auto rdivs = divs[v];
		reverse(begin(rdivs), end(rdivs));
		for (int i : rdivs) {
			qp[i] += dc[i];
			for (int j : divs[i]) {
				if (i != j) {
					qp[j] -= qp[i];
				}
			}
		}
		dp[v] = INT_MAX;
		for (int i : rdivs) {
			if (qp[i] != 0 && dp[i] != INT_MAX) {
				dp[v] = min(dp[v], dp[i] + 1);
			}
		}
		for (int i : divs[v]) {
			qp[i] = 0;
		}
	}
	
	int ans = INT_MAX;
	for (int i = 0; i < nknt; ++i) {
		if (has[i]) {
			ans = min(ans, dp[i]);
		}
	}
	cout << (ans == INT_MAX ? -1 : ans+1) << endl;
	return 0;
}