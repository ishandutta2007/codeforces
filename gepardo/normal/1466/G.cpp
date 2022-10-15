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
const int mod = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

int mod1, mod2;

struct Hash {
	int _1, _2;
	
	Hash()
		: _1(0), _2(0) {
	}
	
	Hash(int64_t a, int64_t b)
		: _1(a % mod1), _2(b % mod2) {
	}
};

Hash hashPow;
Hash hashInvPow;
vector<Hash> hashPows;

inline bool isPrime(int x) {
	for (int i = 2; i*i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

inline int nextPrime(int v) {
	while (!isPrime(v)) {
		++v;
	}
	return v;
}

inline void genTwoPrimes(int le, int ri, int &a, int &b) {
	do {
		a = nextPrime(randGen() % (ri-le+1) + le);
		b = nextPrime(randGen() % (ri-le+1) + le);
	} while (a == b);
}

inline int powr(int64_t a, int n, int mod) {
	int64_t res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return res % mod;
}

inline bool operator==(const Hash &a, const Hash &b) {
	return a._1 == b._1 && a._2 == b._2;
}

inline Hash operator+(const Hash &a, const Hash &b) {
	return Hash(a._1 + b._1, a._2 + b._2);
}

inline Hash &operator+=(Hash &a, const Hash &b) {
	return a = a + b;
}

inline Hash operator-(const Hash &a, const Hash &b) {
	return Hash(a._1 + mod1 - b._1, a._2 + mod2 - b._2);
}

inline Hash &operator-=(Hash &a, const Hash &b) {
	return a = a - b;
}

inline Hash operator*(const Hash &a, int b) {
	return Hash((int64_t)a._1 * b, (int64_t)a._2 * b);
}

inline Hash operator*(const Hash &a, const Hash &b) {
	return Hash((int64_t)a._1 * b._1, (int64_t)a._2 * b._2);
}

inline void initHashes(int maxLen) {
	genTwoPrimes(900'000'000, 1'050'000'000, mod1, mod2);
	genTwoPrimes(200, 1'000, hashPow._1, hashPow._2);
	hashInvPow = Hash(powr(hashPow._1, mod1 - 2, mod1), powr(hashPow._2, mod2 - 2, mod2));
	hashPows.assign(maxLen + 1, Hash());
	hashPows[0] = Hash(1, 1);
	for (int i = 1; i <= maxLen; i++) {
		hashPows[i] = hashPows[i-1] * hashPow;
	}
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	initHashes(2'000'000);
	
	vector<int> pws(200'001), ipws(200'001);
	pws[0] = 1;
	ipws[0] = 1;
	const int i2 = (mod + 1) / 2; 
	for (int i = 1; i < (int)pws.size(); ++i) {
		pws[i] = pws[i-1] * 2 % mod;
		ipws[i] = (int64_t)ipws[i-1] * i2 % mod;
	}
	
	int n, q; cin >> n >> q;
	string s; cin >> s;
	string tt; cin >> tt;
	
	static int cnt[150001][26] = {};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			cnt[i+1][j] = cnt[i][j];
		}
		cnt[i+1][tt[i] - 'a'] += ipws[i];
		cnt[i+1][tt[i] - 'a'] %= mod;
	}
	
	for (int qry = 0; qry < q; ++qry) {
		int w; cin >> w;
		string e; cin >> e;
		string song = s;
		int lvl = 0;
		while (lvl < w && song.size() < e.size()) {
			song += tt[lvl] + song;
			++lvl;
		}
		
		Hash tgt;
		for (int i = 0; i < (int)e.size(); ++i) {
			tgt += hashPows[i] * e[i];
		}
		
		Hash cur;
		int sz = 0;
		
		auto append = [&](char ch) {
			cur += hashPows[sz] * ch;
			++sz;
		};
		
		auto remove = [&](char ch) {
			cur -= hashPows[0] * ch;
			cur = cur * hashInvPow;
			--sz;
		};
		
		int add = (lvl == w) ? 1 : pws[w - lvl];
		
		int64_t ans = 0;
		for (int i = 0; i < (int)song.size(); ++i) {
			append(song[i]);
			if (sz > (int)e.size()) {
				remove(song[i - sz + 1]);
			}
			if (tgt == cur) {
				ans += add;
				ans %= mod;
			}
		}
		if (lvl == w) {
			cout << ans << "\n";
			continue;
		}
		
		append(0);
		for (int i = 0; i < (int)e.size(); ++i) {
			if (sz > (int)e.size()) {
				remove(song[(int)song.size() + i - sz + 1]);
			}
			Hash star = hashPows[(int)e.size() - i - 1];
			for (char ch = 'a'; ch <= 'z'; ++ch) {
				if (tgt == cur + star * ch) {
					ans += pws[w-1] * (int64_t)(cnt[w][ch - 'a'] - cnt[lvl][ch - 'a'] + mod) % mod;
					ans %= mod;
				}
			}
			append(song[i]);
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}