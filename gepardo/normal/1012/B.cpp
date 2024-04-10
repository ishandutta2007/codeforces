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

class DisjointSetUnion {
private:
	int n;
	vector<int> p;
	vector<int> sz;
public:
	int parent(int v) {
		if (p[v] < 0) {
			return v;
		} else {
			return p[v] = parent(p[v]);
		}
	}
	
	inline bool merge(int a, int b) {
		a = parent(a);
		b = parent(b);
		if (a == b) {
			return false;
		}
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		p[b] = a;
		sz[a] += sz[b];
		return true;
	}
	
	DisjointSetUnion(int n)
		: n(n), p(n, -1), sz(n, 1) {
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m, q; cin >> n >> m >> q;
	DisjointSetUnion dsu(n+m);
	vector<int> ux(n), uy(m);
	vector<int> x(q), y(q);
	for (int i = 0; i < q; i++) {
		cin >> x[i] >> y[i]; x[i]--; y[i]--;
		ux[x[i]]++; uy[y[i]]++;
		dsu.merge(x[i], y[i] + n);
	}
	set<int> kmp;
	for (int i = 0; i < n+m; i++) {
		kmp.insert(dsu.parent(i));
	}
	int ans = (int)kmp.size() - 1;
	cout << ans << endl;
	return 0;
}