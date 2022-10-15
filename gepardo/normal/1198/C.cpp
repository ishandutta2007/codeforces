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
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> mt;
		mt.reserve(3*n);
		vector<char> used(3*n, false);
		for (int i = 0; i < m; ++i) {
			int a, b; cin >> a >> b; --a; --b;
			if (!used[a] && !used[b]) {
				used[a] = used[b] = true;
				mt.push_back(i+1);
			}
		}
		vector<int> ind;
		ind.reserve(3*n);
		for (int i = 0; i < 3*n; ++i) {
			if (!used[i]) {
				ind.push_back(i+1);
			}
		}
		if ((int)mt.size() >= n) {
			cout << "Matching\n";
			for (int i = 0; i < n; ++i) {
				cout << mt[i] << " ";
			}
			cout << "\n";
		} else if ((int)ind.size() >= n) {
			cout << "IndSet\n";
			for (int i = 0; i < n; ++i) {
				cout << ind[i] << " ";
			}
			cout << "\n";
		} else {
			assert(false);
		}
	}
	return 0;
}