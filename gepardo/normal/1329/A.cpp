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
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

#define int int64_t

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector<int> a(m);
	int soom = 0;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		soom += a[i];
		if (a[i] + i > n) {
			cout << -1 << endl;
			return 0;
		}
	}
	if (soom < n) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> place(m+1, 0);
	for (int i = m-1; i >= 0; --i) {
		place[i] = max(place[i+1] + 1, a[i]);
	}
	vector<int> res(m);
	int got = 0;
	for (int i = 0; i < m; ++i) {
		if (got + place[i] >= n) {
			for (int j = i; j < m; ++j) {
				res[j] = n - place[i] - i + j;
			}
			break;
		}
		res[i] = got;
		got += a[i];
	}
	for (int i = 0; i < m; ++i) {
		cout << res[i]+1 << " ";
	}
	cout << endl;
	return 0;
}