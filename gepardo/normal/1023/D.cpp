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

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

class FenwickTree {
private:
	int n;
	vector<int64_t> a;
public:
	inline void update(int v, int64_t delta) {
		for (; v < n; v |= v+1) {
			a[v] += delta;
		}
	}
	
	inline int64_t sum(int v) {
		int64_t res = 0;
		for (; v >= 0; v &= v+1, v--) {
			res += a[v];
		}
		return res;
	}
	
	inline int64_t sum(int l, int r) {
		return sum(r) - sum(l-1);
	}
	
	FenwickTree(int n)
		: n(n), a(n, 0) {
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, q; cin >> n >> q;
	vector<int> v(n);
	set<int> unassigned;
	vector< vector<int> > byEl(q+1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (!v[i]) {
			unassigned.insert(i);
		}
		byEl[v[i]].push_back(i);
	}
	FenwickTree f(n);
	for (int i = 0; i < n; i++) {
		f.update(i, v[i]);
	}
	bool noDel = true;
	for (int i = q; i > 0; i--) {
		if (i != 1 && byEl[i].empty()) {
			if (noDel) {
				if (unassigned.empty()) {
					cout << "NO\n";
					return 0;
				}
				noDel = false;
				int w = *unassigned.begin(); unassigned.erase(w);
				v[w] = i;
			}
		} else {
			noDel = false;
			int l, r;
			if (i == 1) {
				l = 0, r = n-1;
			} else {
				l = byEl[i][0], r = byEl[i].back();
			}
			for (int j: byEl[i]) {
				f.update(j, -i);
			}
			if (f.sum(l, r) != 0) {
				cout << "NO\n";
				return 0;
			}
			while (true) {
				auto iter = unassigned.lower_bound(l);
				if (iter == unassigned.end() || *iter > r) {
					break;
				}
				v[*iter] = i;
				unassigned.erase(iter);
			}
		}
	}
	assert(unassigned.empty());
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	return 0;
}