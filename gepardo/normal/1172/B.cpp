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
const int mod = 998244353; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n; cin >> n;
	vector< vector<int> > g(n);
	int a = -1, b = -1;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v; --u; --v;
		if (i == 1) {
			a = u;
			b = v;
		}
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int64_t> f(n+1);
	f[0] = 1;
	for (int i = 1; i <= n; ++i) {
		f[i] = f[i-1] * i % mod;
	}
	
	function<int64_t(int, int)> prt = [&](int v, int p) {
		int edges = g[v].size();
		int64_t ans = f[edges];
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			ans *= prt(to, v);
			ans %= mod;
		}
		return ans;
	};
	
	int64_t ans = n % mod;
	ans *= prt(a, b); ans %= mod;
	ans *= prt(b, a); ans %= mod;
	
	cout << ans << endl;
	
	return 0;
}