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
	//~ #define LOCAL_INPUT_FILE
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

pair<int64_t, int64_t> findNextSum_internal(int64_t r, int64_t k);

pair<int64_t, int64_t> findNextSum(int64_t r, int64_t k) {
	int64_t baza = k*(k+1)/2;
	r -= baza;
	if (r <= 0) return {baza, 0};
	auto res = findNextSum_internal(r, k);
	res.first += baza;
	return res;
}

pair<int64_t, int64_t> findNextSum_internal(int64_t r, int64_t k) {
	int64_t bigGroupSz = k * (k*k + 1);
	int64_t bigGroupNum = r / bigGroupSz;
	int64_t bigGroupPos = r % bigGroupSz;
	int64_t lmargin = (k-2) / 2, rmargin = (k-1) / 2;
	if (k % 2 == 1 && bigGroupNum % k > k/2) {
		swap(lmargin, rmargin);
	}
	if (bigGroupPos <= k*k*lmargin) {
		int64_t rem = k*k - bigGroupPos % (k*k);
		if (rem == k*k) rem = 0;
		return {r + rem, k * bigGroupNum + (bigGroupPos + k*k - 1) / (k*k)};
	}
	if (bigGroupSz-bigGroupPos < k*k*(rmargin+1)) {
		int64_t rem = k*k - (bigGroupPos-k) % (k*k);
		if (rem == k*k) rem = 0;
		return {r + rem, k * bigGroupNum + (bigGroupPos + k*k - k - 1) / (k*k)};
	}
	int64_t last = bigGroupNum * (k*k + 1) + k * lmargin + k;
	int64_t split = k*k + last + k + 1 - findNextSum(last+1, k).first;
	int64_t needSplit = bigGroupPos - k*k*lmargin;
	if (needSplit <= split) {
		return {r - needSplit + split, k * bigGroupNum + lmargin + 1};
	}
	return {r - needSplit + 2*k*k + k, k * bigGroupNum + lmargin + 2};
}

int64_t detect_internal(int64_t r, int64_t k) {
	int64_t bigGroupSz = (k*k + 1);
	int64_t bigGroupNum = r / bigGroupSz;
	int64_t bigGroupPos = r % bigGroupSz;
	int64_t lmargin = (k-2) / 2, rmargin = (k-1) / 2;
	int64_t add = bigGroupNum * (k*k + k);
	if (k % 2 == 1 && bigGroupNum % k > k/2) {
		swap(lmargin, rmargin);
	}
	if (bigGroupPos <= k*lmargin) {
		return add + bigGroupPos + (bigGroupPos + k - 1) / k - 1;
	}
	if (bigGroupSz-bigGroupPos < k*(rmargin+1)) {
		return add + k*k + k - bigGroupSz + bigGroupPos - (bigGroupSz - bigGroupPos) / k - 1;
	}
	int64_t ans = add + bigGroupPos + lmargin;
	int64_t nxtSum = findNextSum(bigGroupNum * bigGroupSz + k*lmargin, k).first;
	if (r+k > nxtSum) --ans;
	return ans;
}

int64_t detect(int64_t r, int64_t k) {
	auto q = findNextSum(r, k);
	if (q.first == r) {
		return (q.second+1)*(k+1) - 1;
	}
	if (r <= k) return r-1;
	return k + detect_internal(r-k, k);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int t; cin >> t;
	while (t--) {
		int64_t n, k; cin >> n >> k;
		cout << detect(n, k) + 1 << endl;
	}
	
	return 0;
}