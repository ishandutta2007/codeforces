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

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

inline int64_t sm(int64_t a, int64_t b) {
	return a == LLONG_MAX || b == LLONG_MAX ? LLONG_MAX : a+b;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int t; cin >> t;
	while (t--) {
		int h, g; cin >> h >> g;
		vector<int> a(1 << h);
		vector< vector<int64_t> > dp(1 << h);
		vector< vector<int> > sorted(1 << h);
		for (int i = 1; i < (1 << h); ++i) {
			cin >> a[i];
		}
		vector<int> d(1 << h);
		for (int i = 1; i < (1 << h); ++i) {
			d[i] = 31 - __builtin_clz(i);
		}
		
		for (int i = (1 << h) - 1; i > 0; --i) {
			if (d[i] == h-1) {
				sorted[i] = vector<int>(1, a[i]);
				continue;
			}
			int sz = (1 << (h-d[i])) - 1;
			sorted[i].resize(sz);
			sorted[i].shrink_to_fit();
			
			auto &le = sorted[2*i];
			auto &ri = sorted[2*i+1];
			auto &cur = sorted[i];
			
			merge(begin(le), end(le), begin(ri), end(ri), begin(cur) + 1, greater<>());
			cur[0] = a[i];
			
			if (d[i] > g-1) continue;
			dp[i].resize(sz);
			if (d[i] == g-1) {
				for (int j = 0; j < sz; ++j) {
					dp[i][j] = cur[j];
				}
				continue;
			}
			
			int pl = sz/2 - 1, pr = sz/2 - 1;
			int64_t mxl = LLONG_MAX, mxr = LLONG_MAX;
			for (int j = sz-1; j > 0; --j) {
				dp[i][j] = sm(sm(mxl, mxr), cur[j]);
				if (pl >= 0 && cur[j] == le[pl]) {
					mxl = min(mxl, dp[i*2][pl]);
					--pl;
				} else if (pr >= 0 && cur[j] == ri[pr]) {
					mxr = min(mxr, dp[i*2+1][pr]);
					--pr;
				} else {
					assert(false);
				}
			}
			dp[i][0] = sm(sm(mxl, mxr), cur[0]);
			le.clear();
			ri.clear();
			le.shrink_to_fit();
			ri.shrink_to_fit();
		}
		
		int idx = min_element(begin(dp[1]), end(dp[1])) - begin(dp[1]);
		set<int, greater<>> res;
		
		vector<int> indices((1 << h) - 1);
		iota(begin(indices), end(indices), 1);
		sort(begin(indices), end(indices), [&](int x, int y) { return a[x] > a[y]; });
		
		function<void(int, int, vector<int>)> restoreAns = [&](int v, int pos, vector<int> indices) {
			
			/*cout << "!!! " << v << " " << pos << endl;
			for (int i : indices) cout << i << " ";
			cout << endl;
			for (auto i : dp[v]) cout << i << " ";
			cout << endl;
			for (auto i : dp[v*2]) cout << i << " ";
			cout << endl;
			for (auto i : dp[v*2+1]) cout << i << " ";
			cout << endl;
			cout << "-----" << endl;*/
			
			int sz = indices.size();
			if (d[v] == g-1) {
				for (int i = sz-1; i >= 0; --i) {
					if (i != sz-1) {
						res.insert(indices[i]);
					}
				}
				return;
			}
			vector<int> le, ri;
			le.reserve(sz/2);
			ri.reserve(sz/2);
			pair<int64_t, int> mxl(LLONG_MAX, -1), mxr(LLONG_MAX, -1);
			int pl = sz/2 - 1, pr = sz/2 - 1;
			int fpl = -1, fpr = -1;
			int ipos = indices[pos];
			for (int ppi = sz-1; ppi >= 0; --ppi) {
				if (ppi == pos) {
					fpl = mxl.second;
					fpr = mxr.second;
				}
				if (ppi == 0) break;
				int ii = indices[ppi];
				int trunc = (ii >> (d[ii] - d[v] - 1));
				if (!(trunc & 1)) {
					mxl = min(mxl, make_pair(dp[v*2][pl], pl));
					--pl;
				} else {
					mxr = min(mxr, make_pair(dp[v*2+1][pr], pr));
					--pr;
				}
				(trunc & 1 ? ri : le).push_back(ii);
			}
			reverse(begin(le), end(le));
			reverse(begin(ri), end(ri));
			
			indices.clear();
			indices.shrink_to_fit();
			assert(fpl >= 0 && fpr >= 0);
			restoreAns(v*2, fpl, move(le));
			restoreAns(v*2+1, fpr, move(ri));
			res.insert(v);
			//~ cout << "ret " << v << " :: " << ipos << endl;
			assert(res.count(ipos));
			res.erase(ipos);
		};
		restoreAns(1, idx, move(indices));
		
		cout << dp[1][idx] << "\n";
		for (int i : res) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}