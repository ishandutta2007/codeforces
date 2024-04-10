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

inline bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

inline void generate(int n) {
	int add = 0;
	while (!isPrime(n + add)) {
		++add;
	}
	cout << n+add << endl;
	for (int i = 1; i < n; ++i) {
		cout << i << " " << i+1 << endl;
	}
	cout << n << " " << 1 << endl;
	int cur = 1;
	while (add != 0) {
		assert(cur <= n && cur+2 <= n);
		cout << cur << " " << cur+2 << endl;
		--add;
		if (!add) break;
		assert(cur+1 <= n && cur+3 <= n);
		cout << cur+1 << " " << cur+3 << endl;
		--add;
		if (!add) break;
		cur += 4;
	}
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	generate(n);
	return 0;
}