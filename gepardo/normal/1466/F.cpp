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
	int n, m; cin >> n >> m;
	DisjointSetUnion dsu(m+1);
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		int a, b;
		if (x == 1) {
			cin >> a;
			b = 0;
		} else if (x == 2) {
			cin >> a >> b;
		} else {
			assert(false);
		}
		if (dsu.merge(a, b)) {
			ans.push_back(i+1);
		}
	}
	int res = 1;
	for (int _ : ans) {
		(void)_;
		res += res;
		res %= module;
	}
	cout << res << " " << ans.size() << "\n";
	for (int i : ans) {
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}