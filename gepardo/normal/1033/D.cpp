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

#define int int64_t

inline int64_t isPowOf(int64_t val, int pp) {
	int64_t res = (pp == 2) ? sqrt((long double)val) : pow((long double)val, (long double)1 / pp);
	for (int64_t a = max((int64_t)0, res-60); a <= res+60; a++) {
		int64_t pa = 1;
		for (int j = 0; j < pp; ++j) {
			pa *= a;
		}
		if (pa == val) {
			return a;
		}
	}
	return -1;
}

inline int64_t gcd(int64_t a, int64_t b) {
	return b ? gcd(b, a%b) : a;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	map<int64_t, int> mp;
	set<int64_t> divs;
	const int mod = 998244353;
	vector<int64_t> v;
	for (int i = 0; i < n; ++i) {
		int64_t q; cin >> q;
		int64_t p2 = isPowOf(q, 2);
		int64_t p3 = isPowOf(q, 3);
		int64_t p4 = isPowOf(q, 4);
		if (p4 >= 0) {
			mp[p4] += 4;
			divs.insert(p4);
		} else if (p3 >= 0) {
			mp[p3] += 3;
			divs.insert(p3);
		} else if (p2 >= 0) {
			mp[p2] += 2;
			divs.insert(p2);
		} else {
			v.push_back(q);
		}
	}
	n = v.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[i] == v[j]) {
				continue;
			}
			int64_t g = gcd(v[i], v[j]);
			if (g != 1) {
				divs.insert(g);
			}
		}
	}
	map<int64_t, int> an1, an2;
	for (int64_t val : v) {
		int64_t zz = val;
		int dtime = 2;
		for (int64_t i : divs) {
			while (val % i == 0) {
				dtime--;
				val /= i;
				mp[i]++;
			}
		}
		if (dtime >= 1) {
			an1[zz]++;
		}
		if (dtime >= 2) {
			an2[zz]++;
		}
	}
	int64_t ans = 1;
	for (auto it : an1) {
		ans *= it.second+1;
		ans %= mod;
	}
	for (auto it : an2) {
		ans *= it.second+1;
		ans %= mod;
	}
	for (auto it : mp) {
		ans *= it.second+1;
		ans %= mod;
	}
	cout << ans % mod << endl;
	return 0;
}