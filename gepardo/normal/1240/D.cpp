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
uniform_int_distribution<int> dist(7e8, 1.05e9);
uniform_int_distribution<int> powDist(4e5, 6e5);

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

inline bool prime(int x) {
	for (int i = 2; i*i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}

inline int nextPrime(int x) {
	while (!prime(x)) {
		++x;
	}
	return x;
}

const int mod1 = nextPrime(dist(randGen));
const int mod2 = nextPrime(dist(randGen));

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

inline Hash &operator+=(Hash &a, const Hash &b) {
	a = a + b;
	return a;
}

inline Hash operator-(const Hash &a, const Hash &b) {
	return Hash(a._1 + mod1 - b._1, a._2 + mod2 - b._2);
}

inline Hash &operator-=(Hash &a, const Hash &b) {
	a = a - b;
	return a;
}

inline Hash operator*(const Hash &a, int b) {
	return Hash((int64_t)a._1 * b, (int64_t)a._2 * b);
}

inline Hash operator*(const Hash &a, const Hash &b) {
	return Hash((int64_t)a._1 * b._1, (int64_t)a._2 * b._2);
}

inline Hash &operator*=(Hash &a, const Hash &b) {
	a = a * b;
	return a;
}

inline bool operator<(const Hash &a, const Hash &b) {
	return make_pair(a._1, a._2) < make_pair(b._1, b._2);
}

int64_t binPow(int64_t a, int n, int m) {
	int64_t res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;
	}
	return res % m;
}

const Hash hashPow = {powDist(randGen), powDist(randGen)};
const Hash hashRev = {binPow(hashPow._1, mod1-2, mod1), binPow(hashPow._2, mod2-2, mod2)};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
	#endif
	int test; cin >> test;
	while (test--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		
		int64_t ans = 0;
		function<void(int, int)> calc = [&](int l, int r) {
			if (l >= r) return;
			
			int m = (l + r) / 2;
			vector<Hash> h1(m-l+1);
			
			{
				vector<int> stk;
				Hash cur {0, 0};
				for (int i = m; i >= l; --i) {
					if (stk.empty() || stk.back() != v[i]) {
						cur *= hashPow;
						cur += Hash(v[i], v[i]);
						stk.push_back(v[i]);
					} else {
						stk.pop_back();
						cur -= Hash(v[i], v[i]);
						cur *= hashRev;
					}
					h1[i-l] = cur;
					//~ cout << i << " : " << cur._1 << " " << cur._2 << endl;
				}
			}
			sort(begin(h1), end(h1));
			
			vector< pair<Hash, int> > ph;
			ph.reserve(h1.size());
			for (int i = 0; i < (int)h1.size(); ++i) {
				if (i == 0 || !(h1[i-1] == h1[i])) {
					ph.emplace_back(h1[i], 1);
				} else {
					ph.back().second++;
				}
			}
			
			{
				vector<int> stk;
				Hash cur {0, 0};
				for (int i = m+1; i <= r; ++i) {
					if (stk.empty() || stk.back() != v[i]) {
						cur *= hashPow;
						cur += Hash(v[i], v[i]);
						stk.push_back(v[i]);
					} else {
						stk.pop_back();
						cur -= Hash(v[i], v[i]);
						cur *= hashRev;
					}
					//~ cout << i << " : " << cur._1 << " " << cur._2 << endl;
					auto iter = lower_bound(begin(ph), end(ph), make_pair(cur, -42));
					if (iter == end(ph) || !(iter->first == cur)) {
						continue;
					}
					ans += iter->second;
				}
			}
			
			//~ cout << "--- " << ans << " ---" << endl;
			
			calc(l, m);
			calc(m+1, r);
		};
		calc(0, n-1);
		
		cout << ans << endl;
		
	}
	
	return 0;
}