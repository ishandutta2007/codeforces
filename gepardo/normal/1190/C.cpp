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
const int mod = module;
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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	string saved = s;
	set<int> zero;
	set<int> one;
	
	auto setStr = [&](string ln) {
		s = ln;
		zero.clear();
		one.clear();
		for (int i = 0; i < int(s.size()); ++i) {
			(s[i] == '0' ? zero : one).insert(i);
		}
	};
	
	auto change = [&](int pos, char val) {
		(s[pos] == '0' ? zero : one).erase(pos);
		(val == '0' ? zero : one).insert(pos);
		s[pos] = val;
	};
	
	auto canWin = [&]() {
		assert(!zero.empty() && !one.empty());
		int zl = *zero.begin(), zr = *zero.rbegin();
		int el = *one.begin(), er = *one.rbegin();
		return zr-zl+1 <= k || er-el+1 <= k;
	};
	
	
	setStr(saved);
	if (zero.empty() || one.empty() || canWin()) {
		cout << "tokitsukaze" << endl;
		return 0;
	}
	
	bool winnable = true;
	for (char fill = '0'; fill <= '1'; ++fill) {
		setStr(saved);
		for (int i = 0; i < k; ++i) {
			change(i, fill);
		}
		#ifdef DEBUG
		cerr << s << endl;
		#endif
		winnable &= canWin();
		for (int i = k; i < n; ++i) {
			change(i-k, saved[i-k]);
			change(i, fill);
			#ifdef DEBUG
			cerr << s << endl;
			#endif
			winnable &= canWin();
		}
	}
	if (winnable) {
		cout << "quailty" << endl;
		return 0;
	}
	
	cout << "once again" << endl;
	return 0;
}