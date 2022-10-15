// The code was written by gepardo
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
#define int int64_t

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
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

inline void raiseError(const string &description) {
	cerr << "Error : " << description << endl;
	exit(42);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector<int64_t> x(n), y(n);
	vector< pair<int64_t, int> > q(n);
	int64_t sx = 0;
	vector<int64_t> ans(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		sx += x[i];
		q[i] = {y[i] - x[i], i};
	}
	sort(begin(q), end(q));
	
	vector<int64_t> pq;
	pq.push_back(0);
	for (auto it : q) {
		pq.push_back(pq.back() + it.first);
	}
	
	auto inc = [&](int a, int b, int sgn) {
		int64_t sum = min(x[a] + y[b], y[a] + x[b]);
		ans[a] += sgn*sum;
		if (a != b) {
			ans[b] += sgn*sum;
		}
	};
	
	for (int i = 0; i < n; ++i) {
		inc(i, i, -1);
	}
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b; a--; b--;
		inc(a, b, -1);
	}
	
	for (int i = 0; i < n; ++i) {
		ans[i] += n*x[i] + sx;
	}
	for (int i = 0; i < n; ++i) {
		int pos = lower_bound(begin(q), end(q), make_pair(y[i] - x[i], (int)INT_MAX)) - begin(q);
		ans[i] += (n - pos) * (y[i] - x[i]) + pq[pos];
	}
	
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}