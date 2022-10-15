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
	int n; cin >> n;
	vector<int> v(n);
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	res.push_back(1);
	int soom = v[0], rest = 0;
	for (int i = 1; i < n; ++i) {
		bool take = v[0] >= 2*v[i];
		if (take) {
			res.push_back(i+1);
			soom += v[i];
		} else {
			rest += v[i];
		}
	}
	if (soom <= rest) {
		cout << 0 << endl;
		return 0;
	}
	cout << res.size() << endl;
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}