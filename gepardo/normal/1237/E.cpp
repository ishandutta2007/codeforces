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

const int64_t mod = 998244353;
int64_t bases[24] = {};
int64_t rBases[24] = {};

inline void initBases() {
	bases[23] = 31;
	rBases[23] = 128805723;
	for (int i = 22; i >= 0; i--) {
		bases[i] = (bases[i+1] * bases[i+1]) % mod;
		rBases[i] = (rBases[i+1] * rBases[i+1]) % mod;
	}
}

inline int64_t d2m(int64_t v) {
	return (v + ((v&1) ? mod : 0)) >> 1;
}

inline vector<int64_t> ntt(int pow, const vector<int64_t> &v, bool inv = false) {
	if (pow == 0) {
		return v;
	}
	vector<int64_t> even(v.size() >> 1);
	vector<int64_t> odd(v.size() >> 1);
	for (int i = 0; i < (int)v.size(); i++) {
		((i & 1) ? odd : even)[i >> 1] = v[i];
	}
	auto evenRes = ntt(pow-1, even, inv);
	auto oddRes = ntt(pow-1, odd, inv);
	int64_t wPow = 1;
	vector<int64_t> res(v.size());
	for (int i = 0; i < (int)v.size(); i++) {
		int j = i & ~((int)v.size() >> 1);
		res[i] = evenRes[j] + wPow * oddRes[j];
		res[i] %= mod;
		wPow *= (inv ? rBases : bases)[pow];
		wPow %= mod;
		if (inv) {
			res[i] = d2m(res[i]);
		}
	}
	return res;
}

inline pair<vector<int64_t>, vector<int64_t>> polyMuls(vector<int64_t> a, vector<int64_t> b, vector<int64_t> c) {
	initBases();
	int nn = max(a.size(), b.size());
	int p = 0;
	while ((1 << p) < nn) {
		p++;
	}
	p++;
	a.resize(1 << p);
	b.resize(1 << p);
	c.resize(1 << p);
	vector<int64_t> buf(1 << p);
	auto ta = ntt(p, a, false);
	auto tb = ta;//ntt(p, b, false);
	auto tc = ntt(p, c, false);
	for (int i = 0; i < (1 << p); i++) {
		tb[i] *= ta[i];
		tb[i] %= mod;
		tc[i] *= ta[i];
		tc[i] %= mod;
	}
	return {ntt(p, tb, true), ntt(p, tc, true)};
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	vector<int> depth(2e6);
	depth[0] = 0;
	for (int i = 1; i < (int)depth.size(); ++i) {
		depth[i] = depth[i >> 1] + 1;
	}
	
	vector<int64_t> kur {1, 1, 1, 0, 1, 1, 0, 0};
	kur.reserve(1 << 21);
	for (int i = 3; i < 20; ++i) {
		vector<int64_t> lo, le;
		lo.reserve((int)kur.size()/2);
		le.reserve((int)kur.size()/2);
		for (int j = 0; j < (int)kur.size(); ++j) {
			int val = kur[j];
			if (depth[j+1]+1 <= i) val = 0;
			((j & 1) ? lo : le).push_back(val);
		}
		auto [konv1, konv2] = polyMuls(le, le, lo);
		for (int j = 0; j < (1 << i); ++j) {
			if (j & 1) {
				kur.push_back(konv1[(1 << (i-1)) + j/2]);
			} else {
				kur.push_back(konv2[(1 << (i-1)) + j/2 - 1]);
			}
		}
	}
	
	int n; cin >> n;
	cout << kur[n] << endl;
	
	/*const int n = 50000;
	
	vector<int64_t> dp(n);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (i % 2 != j % 2 && depth[j+1]+1 >= depth[i] && depth[j] < depth[i] && depth[i-j-1] < depth[i] && depth[i-j]+1 >= depth[i+1]) {
				dp[i] += (dp[j] * dp[i-j-1]) % mod;
				dp[i] %= mod;
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (dp[i] == 1) {
			cout << i << " ";
		}
	}
	cout << endl;*/
	
	return 0;
}