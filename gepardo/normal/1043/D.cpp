// The code was written by gepardo
#ifdef DEBUG
	#define _GLIBCXX_DEBUG
#endif
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

mt19937_64 rnd(system_clock().now().time_since_epoch().count());

inline void raiseError(const string &description) {
	cerr << "Error : " << description << endl;
	exit(42);
}

inline bool prime(int x) {
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

inline int nextPrime(int x) {
	while (!prime(x)) {
		++x;
	}
	return x;
}

const int mod1 = nextPrime(rnd() % (int)1.5e8 + 9e8);
const int mod2 = nextPrime(rnd() % (int)1.5e8 + 9e8);

struct Hash {
	int _1, _2;
	
	Hash()
		: _1(0), _2(0) {
	}
	
	Hash(int64_t a, int64_t b)
		: _1(a % mod1), _2(b % mod2) {
	}
};

inline bool operator==(const Hash &a, const Hash &b) {
	return a._1 == b._1 && a._2 == b._2;
}

inline Hash operator+(const Hash &a, const Hash &b) {
	return Hash(a._1 + b._1, a._2 + b._2);
}

inline Hash operator-(const Hash &a, const Hash &b) {
	return Hash(a._1 + mod1 - b._1, a._2 + mod2 - b._2);
}

inline Hash operator*(const Hash &a, int b) {
	return Hash((int64_t)a._1 * b, (int64_t)a._2 * b);
}

inline Hash operator*(const Hash &a, const Hash &b) {
	return Hash((int64_t)a._1 * b._1, (int64_t)a._2 * b._2);
}

const Hash hashPow = {nextPrime(rnd() % (int)5e4 + 1e5), nextPrime(rnd() % (int)5e4 + 1e5)};

vector<Hash> hashPows;

inline void initHashes(int maxLen) {
	hashPows.resize(maxLen + 1);
	hashPows[0] = Hash(1, 1);
	for (int i = 1; i <= maxLen; i++) {
		hashPows[i] = hashPows[i-1] * hashPow;
	}
}

inline vector<Hash> getHash(const vector<int> &s) {
	int n = s.size();
	vector<Hash> hsh(n+1);
	hsh[0] = Hash(0, 0);
	for (int i = 0; i < n; i++) {
		hsh[i+1] = hsh[i] + hashPows[i] * s[i];
	}
	return hsh;
}

inline bool equalSubstrs(
	const vector<Hash> &a, const vector<Hash> &b,
	int pA, int pB, int len
) {
	Hash hA = a[pA + len] - a[pA];
	Hash hB = b[pB + len] - b[pB];
	if (pA < pB) {
		hA = hA * hashPows[pB - pA];
	} else {
		hB = hB * hashPows[pA - pB];
	}
	return hA == hB;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	initHashes(2e5 + 42);
	int n, m; cin >> n >> m;
	vector< vector<int> > p;
	vector< vector<int> > r;
	for (int iii = 0; iii < m; ++iii) {
		p.emplace_back(n);
		r.emplace_back(n);
		for (int j = 0; j < n; ++j) {
			cin >> p.back()[j];
			p.back()[j]--;
			r.back()[p.back()[j]] = j;
		}
	}
	vector< vector<Hash> > hashes(m);
	for (int i = 0; i < m; ++i) {
		hashes[i] = getHash(p[i]);
	}
	int64_t ans = 0;
	for (int iii = 0; iii < n; ++iii) {
		vector<int> poses(m);
		int mxp = 0;
		for (int j = 0; j < m; ++j) {
			poses[j] = r[j][iii];
			mxp = max(mxp, poses[j]);
		}
		int l = 0, r = n - mxp;
		int mmmm = m;
		while (l != r) {
			int m = (l + r + 1) / 2;
			bool ok = true;
			for (int k = 1; k < mmmm; ++k) {
				if (!equalSubstrs(hashes[0], hashes[k], poses[0], poses[k], m)) {
					ok = false;
					break;
				}
			}
			if (ok) {
				l = m;
			} else {
				r = m-1;
			}
		}
		ans += l;
	}
	cout << ans << endl;
	return 0;
}