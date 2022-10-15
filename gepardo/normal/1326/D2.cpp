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

inline vector<int> manacherOdd(const string &s) {
	int n = s.length();
	vector<int> p1(n, 0);
	for (int i = 0, l = 0, r = 0; i < n; i++) {
		if (i < r) {
			p1[i] = min(p1[2*l - i], r - i);
		}
		while (0 <= i-p1[i] && i+p1[i] < n && s[i-p1[i]] == s[i+p1[i]]) {
			p1[i]++;
		}
		if (i+p1[i] > r) {
			l = i;
			r = i+p1[i];
		}
	}
	return p1;
}

inline vector<int> manacherEven(const string &s) {
	int n = s.length();
	vector<int> p2(n, 0);
	for (int i = 0, l = 0, r = 0; i < n; i++) {
		if (i < r) {
			p2[i] = min(p2[2*l - i], r - i);
		}
		while (0 <= i-p2[i]-1 && i+p2[i] < n && s[i-p2[i]-1] == s[i+p2[i]]) {
			p2[i]++;
		}
		if (i+p2[i] > r) {
			l = i;
			r = i+p2[i];
		}
	}
	return p2;
}

mt19937_64 rnd(chrono::system_clock().now().time_since_epoch().count());

inline bool isPrime(int x) {
	for (int i = 2; i*i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}

inline int getPrime(int a, int b) {
	int baza = rnd() % a + b;
	while (!isPrime(baza)) ++baza;
	return baza;
}

const int mod1 = getPrime((int)1.1e9, (int)0.9e9);
const int mod2 = getPrime((int)1.1e9, (int)0.9e9);

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
	return Hash((int64_t)a._1 + b._1, (int64_t)a._2 + b._2);
}

inline Hash operator-(const Hash &a, const Hash &b) {
	return Hash((int64_t)a._1 + mod1 - b._1, (int64_t)a._2 + mod2 - b._2);
}

inline Hash operator*(const Hash &a, int b) {
	return Hash((int64_t)a._1 * b, (int64_t)a._2 * b);
}

inline Hash operator*(const Hash &a, const Hash &b) {
	return Hash((int64_t)a._1 * b._1, (int64_t)a._2 * b._2);
}

const Hash hashPow = {getPrime(200, 100), getPrime(200, 100)};

vector<Hash> hashPows;

inline void initHashes(int maxLen) {
	hashPows.resize(maxLen + 1);
	hashPows[0] = Hash(1, 1);
	for (int i = 1; i <= maxLen; i++) {
		hashPows[i] = hashPows[i-1] * hashPow;
	}
}

inline vector<Hash> getHash(const string &s) {
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
	
	initHashes(1'200'000);
	
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		string rs = s;
		int n = s.size();
		reverse(begin(rs), end(rs));
		auto hs = getHash(s);
		auto hrs = getHash(rs);
		auto m1 = manacherOdd(s);
		auto m2 = manacherEven(s);
		
		tuple<int, int, int> ans(0, 0, 0);
		
		auto tryAdd = [&](int p, int s) {
			if (p < 0 || s < 0 || p+s > n) return;
			Hash dh = hs[n] - hs[n-s] + hs[p] * hashPows[n-s-p];
			Hash rh = hrs[n] - hrs[n-p] + hrs[s] * hashPows[n-s-p];
			if (dh == rh) {
				ans = max(ans, make_tuple(p+s, p, s));
			}
		};
		
		for (int i = 0; i < n; ++i) {
			tryAdd(i+m1[i], 2*i+1 - (i+m1[i]));
			tryAdd(i+m2[i], 2*i - (i+m2[i]));
		}
		for (int i = 0; i < n; ++i) {
			tryAdd(2*(n-i-1)+1 - (n-i+m1[i]-1), n-i+m1[i]-1);
			tryAdd(2*(n-i) - (n-i+m2[i]), n-i+m2[i]);
		}
		
		auto [len, p, ss] = ans;
		assert(len != 0);
		cout << s.substr(0, p) + s.substr(n-ss, ss) << "\n";
	}
	
	return 0;
}