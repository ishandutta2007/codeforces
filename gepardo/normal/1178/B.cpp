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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	string s; cin >> s;
	int n = s.size();
	vector<int64_t> d0(n+1), d1(n+1), d2(n+1);
	for (int i = 1; i < n; ++i) {
		d0[i+1] += d0[i];
		if (s[i] == 'v' && s[i-1] == 'v') {
			++d0[i+1];
		}
	}
	for (int i = 0; i < n; ++i) {
		d1[i+1] += d1[i];
		if (s[i] == 'o') {
			d1[i+1] += d0[i];
		}
	}
	for (int i = 1; i < n; ++i) {
		d2[i+1] += d2[i];
		if (s[i] == 'v' && s[i-1] == 'v') {
			d2[i+1] += d1[i];
		}
	}
	
	/*for (int i = 0; i <= n; ++i) {
		cout << d0[i] << " ";
	}
	cout << endl;
	for (int i = 0; i <= n; ++i) {
		cout << d1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i <= n; ++i) {
		cout << d2[i] << " ";
	}
	cout << endl;*/
	
	cout << d2.back() << endl;
	return 0;
}