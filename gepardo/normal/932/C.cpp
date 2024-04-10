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
	int n, a, b; cin >> n >> a >> b;
	int kA = -1, kB = -1;
	for (int i = 0; i < n + 42; i++) {
		if (i*a > n) {
			break;
		}
		if ((n - i*a) % b != 0) {
			continue;
		}
		kA = i;
		kB = (n - i*a) / b;
		break;
	}
	if (kA < 0) {
		cout << -1 << endl;
		return 0;
	}
	int ptr = 0;
	vector<int> p(n);
	iota(p.begin(), p.end(), 1);
	
	auto apply = [&](int sz) {
		rotate(p.begin() + ptr, p.begin() + ptr + 1, p.begin() + ptr + sz);
		ptr += sz;
	};
	
	for (int i = 0; i < kA; i++) {
		apply(a);
	}
	for (int i = 0; i < kB; i++) {
		apply(b);
	}
	
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
	return 0;
}