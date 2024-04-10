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

inline int isPrime(int x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	m -= n-1;
	int sum = n-1, last = 1;
	while (!isPrime(sum)) {
		last++;
		sum++;
	}
	cout << sum << " " << sum << "\n";
	for (int i = 1; i + 1 < n; i++) {
		cout << i << " " << i+1 << " " << 1 << "\n";
	}
	cout << n-1 << " " << n << " " << last << "\n";
	if (!m) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+2; j < n; j++) {
			cout << i+1 << " " << j+1 << " " << (int)1e9 << "\n";
			m--;
			if (!m) {
				return 0;
			}
		}
	}
	return 0;
}