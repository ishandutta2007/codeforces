// The code was written by gepardo
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

inline void raiseError(const string &description) {
	cerr << "Error : " << description << endl;
	exit(42);
}

inline bool isPalindrome(string s) {
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] != s[n-i-1]) {
			return false;
		}
	}
	return true;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	string s; cin >> s;
	map<char, int> lc;
	for (char c: s) {
		++lc[c];
	}
	int n = s.size();
	string t = s + s;
	for (int i = 0; i < n; ++i) {
		string q = t.substr(i, n);
		if (q != s && isPalindrome(q)) {
			cout << 1 << endl;
			return 0;
		}
	}
	if (s.size() % 2 == 0) {
		cout << (lc[s[0]] == n ? "Impossible" : "2") << endl;
		return 0;
	}
	if (lc[s[0]] == n || (lc[s[0]] == n-1 && s[n/2] != s[0])) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << 2 << endl;
	return 0;
}