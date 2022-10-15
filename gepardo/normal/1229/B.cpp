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

#define gcd nod

inline int64_t gcd(int64_t a, int64_t b) {
	return b ? gcd(b, a%b) : a;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n; cin >> n;
	vector<int64_t> x(n);
	vector< vector<int> > g(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	const int l = 20;
	vector< vector<int> > up(n, vector<int>(l));
	vector< vector<int64_t> > val(n, vector<int64_t>(l));
	vector<int> d(n);
	
	function<void(int, int)> dfs = [&](int v, int p) {
		if (v != p) d[v] = d[p] + 1;
		up[v][0] = p;
		val[v][0] = x[v];
		for (int i = 1; i < l; ++i) {
			up[v][i] = up[up[v][i-1]][i-1];
			val[v][i] = gcd(val[v][i-1], val[up[v][i-1]][i-1]);
		}
		for (int to : g[v]) {
			if (to != p) {
				dfs(to, v);
			}
		}
	};
	dfs(0, 0);
	
	int64_t ans = 0;
	
	//~ for (int i = 0; i < n; ++i) {
		//~ for (int j = 0; j < 20; ++j) {
			//~ cout << val[i][j] << " ";
		//~ }
		//~ cout << endl;
	//~ }
	
	for (int idd = 0; idd < n; ++idd) {
		int v = idd;
		int64_t qg = x[v];
		while (true) {
			int w = v;
			for (int i = l-1; i >= 0; --i) {
				if (gcd(qg, val[w][i]) == qg) {
					w = up[w][i];
				}
			}
			if (gcd(qg, val[w][0]) == qg) {
				//~ cout << idd+1 << " :: " << v+1 << " -> " << "end" << " :: " << qg << endl;
				assert(w == 0);
				ans += qg % mod * (d[v]+1) % mod;
				ans %= mod;
				//~ cout << ans << endl;
				break;
			}
			//~ cout << idd+1 << " :: " << v+1 << " -> " << w+1 << " :: " << qg << endl;
			ans += qg % mod * (d[v] - d[w]) % mod;
			ans %= mod;
			qg = gcd(qg, val[w][0]);
			//~ cout << ans << endl;
			v = w;
		}
	}
	cout << ans << endl;
	
	return 0;
}