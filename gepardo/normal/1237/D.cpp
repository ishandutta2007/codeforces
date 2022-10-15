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

class MaxSparseTable {
private:
	int n;
	vector< vector<int> > a;
	vector<int> lg;
public:
	inline int rmq(int l, int r) {
		int w = lg[r - l + 1];
		return max(a[w][l], a[w][r - (1 << w) + 1]);
	}
	
	MaxSparseTable(const vector<int> &v)
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
				a[i][j] = max(a[i-1][j], a[i-1][j + (1 << (i-1))]);
			}
		}
	}
};

class MinSparseTable {
private:
	int n;
	vector< vector<int> > a;
	vector<int> lg;
public:
	inline int rmq(int l, int r) {
		int w = lg[r - l + 1];
		return min(a[w][l], a[w][r - (1 << w) + 1]);
	}
	
	MinSparseTable(const vector<int> &v)
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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector<int> v(2*n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i+n] = v[i];
	}
	int mx = *max_element(begin(v), end(v));
	int mn = *min_element(begin(v), end(v));
	MaxSparseTable vmx(v);
	MinSparseTable vmn(v);
	if (2*mn >= mx) {
		for (int i = 0; i < n; ++i) {
			cout << -1 << " ";
		}
		cout << endl;
		return 0;
	}
	vector<int> nxt(n+1), len(n+1);
	for (int i = 0; i < n; ++i) {
		int l = i, r = n+i;
		while (l != r) {
			int m = (l + r) / 2;
			if (vmx.rmq(i, m) > v[i]) {
				r = m;
			} else {
				l = m+1;
			}
		}
		assert(l != i);
		int val = l;
		if (2*vmn.rmq(i, l-1) < v[i]) {
			int l = i, r = val-1;
			while (l != r) {
				int m = (l + r) / 2;
				if (2*vmn.rmq(i, m) < v[i]) {
					r = m;
				} else {
					l = m+1;
				}
			}
			nxt[i] = n;
			len[i] = l-i;
			continue;
		}
		nxt[i] = l%n;
		len[i] = l-i;
	}
	nxt[n] = n;
	len[n] = 0;
	
	vector< vector<int> > dnx(sparseDepth, vector<int>(n+1)), dln(sparseDepth, vector<int>(n+1));
	dnx[0] = nxt;
	dln[0] = len;
	for (int i = 1; i < sparseDepth; ++i) {
		for (int j = 0; j <= n; ++j) {
			dnx[i][j] = dnx[i-1][dnx[i-1][j]];
			dln[i][j] = dln[i-1][j] + dln[i-1][dnx[i-1][j]];
		}
	}
	
	for (int i = 0; i < n; ++i) {
		cout << dln.back()[i] << " ";
	}
	cout << endl;
	
	return 0;
}