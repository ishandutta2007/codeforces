// This code was written by alex256
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
	int64_t n, k; cin >> n >> k;
	int64_t wn = n;
	static int _knts[1000000] = {};
	int *knts = _knts + 500000;
	int nowSz = 0;
	int nowPos = 0;
	while (n) {
		knts[nowPos++] += n & 1;
		nowSz += n & 1;
		n >>= 1;
	}
	if (nowSz > k) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for (int i = nowSz; i < k; i++) {
		while (!knts[nowPos]) {
			nowPos--;
		}
		knts[nowPos]--;
		knts[nowPos-1]++;
		knts[nowPos-1]++;
		while (!knts[nowPos]) {
			nowPos--;
		}
	}
	int ans = nowPos;
	int bits = 0;
	vector<int> res;
	n = wn;
	while (n) {
		if (n & 1) {
			if (ans <= bits) {
				for (int i = 0; i < (1 << (bits - ans)); i++) {
					res.push_back(ans);
				}
			} else {
				res.push_back(bits);
			}
		}
		n >>= 1;
		bits++;
	}
	reverse(res.begin(), res.end());
	while ((int)res.size() < k) {
		int kur = res.back(); res.pop_back();
		res.push_back(kur-1);
		res.push_back(kur-1);
	}
	for (int i: res) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}