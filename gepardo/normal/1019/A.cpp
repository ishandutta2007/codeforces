// Code written by gepardo
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
	int n, m; cin >> n >> m;
	int v1 = 0;
	vector< vector<int> > v(m);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; a--;
		if (a == 0) {
			v1++;
		} else {
			v[a].push_back(b);
		}
	}
	for (int i = 0; i < m; i++) {
		sort(v[i].begin(), v[i].end());
		reverse(v[i].begin(), v[i].end());
	}
	int64_t ans = LLONG_MAX;
	for (int nv = max(1, v1); nv <= n; nv++) {
		int64_t cur = 0;
		vector<int64_t> q;
		q.reserve(n);
		int qv = v1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < nv-1 && j < (int)v[i].size(); j++) {
				q.push_back(v[i][j]);
			}
			for (int j = nv-1; j < (int)v[i].size(); j++) {
				qv++;
				cur += v[i][j];
			}
		}
		if (qv < nv) {
			sort(q.begin(), q.end());
			for (int i = 0; i < nv - qv; i++) {
				cur += q[i];
			}
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
	return 0;
}