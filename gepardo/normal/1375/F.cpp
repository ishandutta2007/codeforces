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
	int64_t w[3];
	cin >> w[0] >> w[1] >> w[2];
	cout << "First" << endl;
	
	// Step I: make him capture the greatest heap
	{
		const int64_t add = (int64_t)1e9 + 42;
		cout << add << endl;
		int x; cin >> x; --x;
		assert(x != -1);
		assert(x != -2);
		w[x] += add;
	}
	
	// Step II: convert it to (0, a, 2*a)
	{
		int64_t q[3] = {w[0], w[1], w[2]};
		sort(q, q+3);
		int64_t a = q[1]-q[0], b = q[2]-q[1];
		int64_t add = a + 2*b;
		cout << add << endl;
		int x; cin >> x; --x;
		if (x == -1) {
			return 0;
		}
		assert(x != -2);
		w[x] += add;
	}
	
	// Step III: get profit
	{
		int64_t q[3] = {w[0], w[1], w[2]};
		sort(q, q+3);
		int64_t a = q[1]-q[0], b = q[2]-q[1];
		assert(a == b);
		cout << a << endl;
		int x; cin >> x;
		assert(x == 0);
	}
	
	return 0;
}