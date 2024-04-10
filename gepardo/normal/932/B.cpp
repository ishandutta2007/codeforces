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

inline int f(int n) {
	if (n < 10) {
		return n;
	}
	int mul = 1;
	while (n) {
		int mod = n % 10;
		if (mod != 0) {
			mul *= mod;
		}
		n /= 10;
	}
	return f(mul);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	vector< vector<int> > kntOf((int)1e6 + 42, vector<int>(10));
	for (int i = 0; i < (int)kntOf.size(); i++) {
		kntOf[i][f(i)]++;
	}
	for (int i = 1; i < (int)kntOf.size(); i++) {
		for (int j = 0; j < 10; j++) {
			kntOf[i][j] += kntOf[i-1][j];
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, k; cin >> l >> r >> k;
		cout << kntOf[r][k] - kntOf[l-1][k] << "\n";
	}
	return 0;
}