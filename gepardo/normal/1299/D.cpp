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

struct VecSpace {
	vector<int> vs;
	vector<int> pos;
};

inline bool tryInclude(const VecSpace &sp, int &x) {
	for (int i = 0; i < (int)sp.pos.size(); ++i) {
		if (x & (1 << sp.pos[i])) {
			x ^= sp.vs[i];
		}
	}
	return x != 0;
}

inline void include(VecSpace &sp, int x) {
	bool res = tryInclude(sp, x);
	assert(res);
	sp.vs.push_back(x);
	sp.pos.push_back(__builtin_ctz(x));
}

inline uint32_t toMask(const VecSpace &sp) {
	uint32_t res = 0;
	for (int i = 0; i < 32; ++i) {
		int x = i;
		if (!tryInclude(sp, x)) {
			res |= (uint32_t)1 << (uint32_t)i;
		}
	}
	return res;
}

inline void printBin(uint32_t x) {
	for (int i = 0; i < 32; ++i) {
		cout << ((x >> i) & 1);
	}
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	map<uint32_t, int> spaceNums;
	vector<VecSpace> spaces;
	vector<int> spaceFromOne(32, -1);
	function<void(const VecSpace &)> rec = [&](const VecSpace &sp) {
		uint32_t msk = toMask(sp);
		if (spaceNums.count(msk)) return;
		if (sp.vs.size() == 1) spaceFromOne[sp.vs[0]] = spaces.size();
		spaceNums[msk] = spaces.size();
		spaces.push_back(sp);
		for (int i = 0; i < 32; ++i) {
			int x = i;
			if (!tryInclude(sp, x)) continue;
			VecSpace ns = sp;
			include(ns, x);
			rec(ns);
		}
	};
	VecSpace empty;
	rec(empty);
	
	int sps = spaces.size();
	vector<vector<int>> op(sps, vector<int>(sps));
	for (int i = 0; i < sps; ++i) {
		for (int j = 0; j < sps; ++j) {
			VecSpace a = spaces[i];
			bool ok = true;
			for (int x : spaces[j].vs) {
				if (!tryInclude(a, x)) {
					ok = false;
					break;
				}
				include(a, x);
			}
			if (!ok) {
				op[i][j] = -1;
				continue;
			}
			op[i][j] = spaceNums.at(toMask(a));
		}
	}
	
	int n, m; cin >> n >> m;
	vector< vector< pair<int, int> > > g(n);
	map< pair<int, int>, int> weights;
	for (int i = 0; i < m; ++i) {
		int a, b, w; cin >> a >> b >> w; --a; --b;
		g[a].emplace_back(b, w);
		g[b].emplace_back(a, w);
		weights[{a, b}] = weights[{b, a}] = w;
	}
	
	auto doOp = [&](int a, int b) {
		return a < 0 || b < 0 ? -1 : op[a][b];
	};
	
	vector<int> used(n, 0);
	used[0] = 2;
	int comp = -1;
	vector<int> cids(n, -1);
	vector<int> xr(n);
	vector<int> compSpaces, compSizes, compExtra, compRoots;
	
	function<void(int, int)> dfs = [&](int v, int p) {
		assert(cids[v] < 0 && used[v] == 0);
		used[v] = 1;
		cids[v] = comp;
		for (auto [to, w] : g[v]) {
			if (to == p || used[to] == 2) continue;
			if (used[to] == 1) {
				int val = xr[v] ^ xr[to] ^ w;
				compSpaces[comp] = doOp(compSpaces[comp], spaceFromOne[val]);
				continue;
			}
			xr[to] = xr[v] ^ w;
			dfs(to, v);
		}
		used[v] = 2;
	};
	
	for (auto [to, w] : g[0]) {
		if (cids[to] >= 0) {
			int cid = cids[to];
			assert(compSizes[cid] != 2);
			++compSizes[cid];
			int a = compRoots[cid], b = to;
			int val = weights.at({0, a}) ^ weights.at({0, b}) ^ weights.at({a, b});
			compExtra[cid] = spaceFromOne[val];
			continue;
		}
		++comp;
		compSpaces.push_back(0);
		compSizes.push_back(1);
		compExtra.push_back(0);
		compRoots.push_back(to);
		dfs(to, 0);
	}
	int cc = compSizes.size();
	
	vector<int> cnt(sps);
	
	auto acnt = [&](int x) {
		if (x >= 0) ++cnt[x];
	};
	
	const int mod = (int)1e9 + 7;
	
	vector<int64_t> dp(sps), pdp(sps);
	dp[0] = 1;
	for (int i = 0; i < cc; ++i) {
		if (compSizes[i] == 1) {
			if (compSpaces[i] == 0) {
				for (int64_t &x : dp) {
					x += x;
					if (x >= mod) x -= mod;
				}
			} else {
				acnt(compSpaces[i]);
			}
		} else {
			if (compSpaces[i] == 0) {
				pdp = dp;
				int xtra = compExtra[i];
				for (int j = 0; j < sps; ++j) {
					int nv = doOp(xtra, j);
					dp[j] += pdp[j] + pdp[j];
					while (dp[j] >= mod) dp[j] -= mod;
					if (nv >= 0) {
						dp[nv] += pdp[j];
						if (dp[nv] >= mod) dp[nv] -= mod;
					}
				}
			} else {
				acnt(compSpaces[i]);
				acnt(compSpaces[i]);
				acnt(doOp(compSpaces[i], compExtra[i]));
			}
		}
	}
	
	for (int i = 1; i < sps; ++i) {
		if (!cnt[i]) continue;
		pdp = dp;
		for (int j = 0; j < sps; ++j) {
			int nv = doOp(i, j);
			if (nv < 0) continue;
			dp[nv] += pdp[j] * cnt[i] % mod;
			dp[nv] %= mod;
		}
	}
	
	int64_t res = 0;
	for (int i = 0; i < sps; ++i) {
		res += dp[i];
		res %= mod;
	}
	cout << res << endl;
	
	return 0;
}