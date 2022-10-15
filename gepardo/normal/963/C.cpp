// Code by gepardo
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

inline int64_t gcd(int64_t a, int64_t b) {
	return b ? gcd(b, a%b) : a;
}

inline int64_t proportional(int64_t a, int64_t b, int64_t c, int64_t d) {
	for (int i = 0; i < 10; i++) {
		int64_t mod = (int)1e9 + i;
		int64_t q1 = (a % mod) * (d % mod) % mod;
		int64_t q2 = (b % mod) * (c % mod) % mod;
		if (q1 != q2) {
			return false;
		}
	}
	return true;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	map< int64_t, map<int64_t, int64_t> > mp;
	for (int i = 0; i < n; i++) {
		int64_t x, y, c; cin >> x >> y >> c;
		mp[x][y] += c;
	}
	vector< vector< pair<int64_t, int64_t> > > v;
	for (auto &it: mp) {
		v.emplace_back();
		for (auto &jt: it.second) {
			v.back().emplace_back(jt);
		}
	}
	int h = v.size(), w = v[0].size();
	for (int i = 0; i < h; i++) {
		if ((int)v[i].size() != w) {
			cout << 0 << endl;
			return 0;
		}
		for (int j = 0; j < w; j++) {
			if (v[i][j].first != v[0][j].first) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	
	int64_t g = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (
				!proportional(v[0][0].second, v[i][0].second, v[0][j].second, v[i][j].second) ||
				!proportional(v[0][0].second, v[0][j].second, v[i][0].second, v[i][j].second)
			) {
				cout << 0 << endl;
				return 0;
			}
			g = gcd(g, v[i][j].second);
		}
	}
	
	int ans = 0;
	for (int64_t i = 1; i*i <= g; i++) {
		if (g % i == 0) {
			ans += 1 + (i*i != g);
		}
	}
	cout << ans << endl;
	
	return 0;
}