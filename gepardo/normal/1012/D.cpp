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

inline int predict(int a, int b, int c) {
	if (a > b) {
		swap(a, b);
	}
	if (c == 0) {
		if (a < 2) {
			if (b < 2) {
				return -1;
			} else {
				return b/2 + (b%4 != 2); 
			}
		} else {
			return (a+b) / 2;
		}
	} else if (c == 1) {
		if (a+b <= 1) {
			return -1;
		}
		if (a == 1 && b == 1) {
			return 0;
		}
		if (a < 2) {
			a = 2;
		}
		return (a+b) / 2 - (a%4 == b%4);
	} else {
		assert(false);
	}
}

struct State {
	int a, b, c;
};

inline int answer(const State &s) {
	return predict(s.a, s.b, s.c);
}

struct CutString {
	int base, len;
};

inline void split(CutString s, CutString &l, CutString &r, int pt) {
	l = {s.base, pt};
	r = {s.base ^ (pt & 1), s.len - pt};
}

inline void merge(CutString &s, CutString l, CutString r) {
	if (!l.len || !r.len) {
		s = l.len ? l : r;
	} else {
		s.base = l.base;
		s.len = l.len + r.len - (l.base ^ r.base ^ (l.len & 1));
	}
}

inline State move(const State &s, int da, int db) {
	assert(da <= s.a && db <= s.b);
	CutString sa {0, s.a}, sb {s.c, s.b};
	CutString la, ra, lb, rb;
	split(sa, la, ra, da);
	split(sb, lb, rb, db);
	merge(sa, la, rb);
	merge(sb, lb, ra);
	return {sa.len, sb.len, sa.base ^ sb.base};
}

struct RealString {
	vector< pair<int, char> > str;
	int offs = 0;
};

inline void append(RealString &s, char c, int pos) {
	if (s.str.empty() || s.str.back().second != c) {
		s.str.emplace_back(pos - s.offs, c);
	}
}

inline void doSwap(RealString &a, RealString &b, int da, int db) {
	assert(0 <= da && da <= (int)a.str.size());
	assert(0 <= db && db <= (int)b.str.size());
	vector< pair<int, char> > ap(a.str.end() - da, a.str.end());
	vector< pair<int, char> > bp(b.str.end() - db, b.str.end());
	a.str.erase(a.str.end() - da, a.str.end());
	b.str.erase(b.str.end() - db, b.str.end());
	int al = ap.empty() ? 0 : (ap[0].first + a.offs + 1);
	int bl = bp.empty() ? 0 : (bp[0].first + b.offs + 1);
	int ao = a.offs, bo = b.offs;
	a.offs -= al - bl;
	b.offs -= bl - al;
	cout << al << " " << bl << "\n";
	for (auto &it: ap) {
		append(b, it.second, it.first + ao);
	}
	for (auto &it: bp) {
		append(a, it.second, it.first + bo);
	}
}

inline State genState(const RealString &a, const RealString &b) {
	return State {(int)a.str.size(), (int)b.str.size(), a.str.back().second != b.str.back().second};
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	string a, b; cin >> a >> b;
	RealString ra, rb;
	for (int i = (int)a.size() - 1; i >= 0; i--) {
		append(ra, a[i], i);
	}
	for (int i = (int)b.size() - 1; i >= 0; i--) {
		append(rb, b[i], i);
	}
	int res = answer(genState(ra, rb));
	cout << res << "\n";
	while (res > 0) {
		State s = genState(ra, rb);
		assert(answer(s) == res);
		bool ok = false;
		for (int i = 0; i <= s.a && i <= 6; i++) {
			for (int j = 0; j <= s.b && j <= 6; j++) {
				State ns = move(s, i, j);
				if (answer(ns) == res-1) {
					doSwap(ra, rb, i, j);
					res--;
					ok = true;
					break;
				}
			}
			if (ok) {
				break;
			}
		}
		assert(ok);
	}
	return 0;
}