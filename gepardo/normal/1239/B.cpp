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

const int sparseDepth = 20;

class SparseTable {
private:
	int n;
	vector< vector<int> > a;
	vector<int> lg;
public:
	inline int rmq(int l, int r) {
		int w = lg[r - l + 1];
		return min(a[w][l], a[w][r - (1 << w) + 1]);
	}
	
	SparseTable(const vector<int> &v)
		: n(v.size()), a(sparseDepth, vector<int>(n)), lg(n+1) {
		lg[1] = 0;
		for (int i = 2; i <= n; i++) {
			lg[i] = lg[i/2] + 1;
		}
		for (int i = 0; i < n; i++) {
			a[0][i] = v[i];
		}
		for (int i = 1; i < sparseDepth; i++) {
			for (int j = 0; j <= n - (1 << i); j++) {
				a[i][j] = min(a[i-1][j], a[i-1][j + (1 << (i-1))]);
			}
		}
	}
};

#ifdef DEBUG
inline int brute(string s) {
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		for (int j = 0; j < (int)s.size(); ++j) {
			swap(s[i], s[j]);
			int knt = 0;
			for (int k = 0; k < (int)s.size(); ++k) {
				bool ok = true;
				int bal = 0;
				for (int l = 0; l < (int)s.size(); ++l) {
					int item = s[(k+l) % n];
					bal += (item == '(' ? +1 : -1);
					if (bal < 0) {
						ok = false;
						break;
					}
				}
				if (bal != 0) ok = false;
				knt += ok;
			}
			ans = max(ans, knt);
			swap(s[i], s[j]);
		}
	}
	return ans;
}
#endif

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	string s; cin >> s;
	string a = s + s;
	vector<int> b(2*n+1);
	b[0] = 0;
	for (int i = 0; i < 2*n; ++i) {
		b[i+1] = b[i] + (a[i] == '(' ? +1 : -1);
	}
	if (b[n] != 0) {
		#ifdef DEBUG
		assert(brute(s) == 0);
		#endif
		cout << 0 << endl << "1 1" << endl;
		return 0;
	}
	vector< vector<int> > items(2*n+1);
	for (int i = 0; i < (int)b.size(); ++i) {
		assert(-n <= b[i] && b[i] <= n);
		items[b[i] + n].push_back(i);
	}
	
	auto kount = [&](int it, int l, int r) -> int {
		if (l > r) return 0;
		it += n;
		return upper_bound(begin(items[it]), end(items[it]), r) -
		       lower_bound(begin(items[it]), end(items[it]), l);
	};
	
	SparseTable bst(b);
	tuple<int, int, int> ans {0, 0, 0};
	bool hadZero = false;
	for (int loop = 0; loop < n; ++loop) {
		int minBal = bst.rmq(loop, loop + n) - b[loop];
		assert(b[loop+n] == b[loop] && minBal <= 0);
		if (minBal < -2) {
			continue;
		}
		if (minBal == 0) {
			if (hadZero) continue;
			hadZero = true;
			int knt = 0;
			for (int i = loop; i < loop+n; ++i) {
				knt += b[i] == b[loop];
			}
			ans = max(ans, make_tuple(knt, 0, 0));
			for (int i = loop; i < loop+n;) {
				if (b[i] != b[loop] + 2) {
					++i;
					continue;
				}
				int l = i;
				while (b[i] >= b[l]) {
					assert(i < loop+n);
					++i;
				}
				int k2 = 0;
				for (int j = l; j < i; ++j) k2 += b[j] == b[l];
				ans = max(ans, make_tuple(k2+knt, l-1, i-1));
			}
			continue;
		}
		auto &st = items[n+b[loop]-1];
		auto lit = lower_bound(begin(st), end(st), loop);
		auto rit = upper_bound(begin(st), end(st), loop+n);
		assert(lit != end(st) && rit != begin(st));
		--rit;
		int lem = *lit, rem = *rit;
		int knt = kount(b[loop], loop, lem-1) + kount(b[loop]-2, lem, rem) + kount(b[loop], rem+1, loop+n-1);
		ans = max(ans, make_tuple(knt, lem-1, rem));
	}
	{
		auto [a, b, c] = ans;
		#ifdef DEBUG
		assert(brute(s) == a);
		#endif
		cout << a << endl << b%n+1 << " " << c%n+1 << endl;
	}
	return 0;
}