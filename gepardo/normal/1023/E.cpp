// Code written by gepardo
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

int n;

inline int init() {
	cin >> n; return n;
}

inline bool query(int x1, int y1, int x2, int y2) {
	cout << "? " << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << endl;
	assert(x1 <= x2 && y1 <= y2);
	assert((x2-x1) + (y2-y1) >= n-1);
	string s; cin >> s;
	assert(s == "YES" || s == "NO");
	return s == "YES";
}

inline void answer(string s) {
	cout << "! " << s <<  endl;
	exit(0);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n = init();
	string a1, a2;
	{
		int x = 0, y = 0;
		for (int i = 1; i < n; i++) {
			if (query(x+1, y, n-1, n-1)) {
				x++;
				a1 += 'D';
			} else {
				y++;
				a1 += 'R';
			}
		}
	}
	{
		int x = n-1, y = n-1;
		for (int i = 1; i < n; i++) {
			if (query(0, 0, x, y-1)) {
				y--;
				a2 += 'R';
			} else {
				x--;
				a2 += 'D';
			}
		}
	}
	reverse(a2.begin(), a2.end());
	answer(a1 + a2);
	return 0;
}