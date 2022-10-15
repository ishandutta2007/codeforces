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

struct Query {
	int type, v;
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n, q; cin >> n >> q;
	vector< vector<int> > g(n);
	vector<int> p(n);
	for (int i = 1; i < n; i++) {
		cin >> p[i]; p[i]--;
		g[p[i]].push_back(i);
	}
	
	vector<Query> qry(q);
	for (int i = 0; i < q; i++) {
		cin >> qry[i].type >> qry[i].v; qry[i].v--;
	}
	
	const int l = 20;
	vector<int> d(n), tin(n), tout(n);
	vector< vector<int> > up(n, vector<int>(l));
	int timer = 0;
	
	function<void(int)> dfs1 = [&](int v) {
		up[v][0] = p[v];
		for (int i = 1; i < l; i++) {
			up[v][i] = up[up[v][i-1]][i-1];
		}
		tin[v] = timer++;
		for (int to: g[v]) {
			d[to] = d[v] + 1;
			dfs1(to);
		}
		tout[v] = timer++;
	};
	dfs1(0);
	
	auto upper = [&](int a, int b) {
		return tin[a] <= tin[b] && tout[b] <= tout[a];
	};
	
	auto lca = [&](int a, int b) {
		if (upper(a, b)) {
			return a;
		}
		if (upper(b, a)) {
			return b;
		}
		for (int i = l-1; i >= 0; i--) {
			if (!upper(up[a][i], b)) {
				a = up[a][i];
			}
		}
		return up[a][0];
	};
	
	vector<char> state(n, 0);
	const int block = 1000;
	
	for (int ql = 0; ql < q; ql += block) {
		int qr = min(q, ql + block);
		
		vector<char> active(n);
		for (int i = ql; i < qr; i++) {
			active[qry[i].v] = true;
		}
		vector<int> actives;
		
		vector< pair<int, int> > actSorted;
		for (int i = 0; i < n; i++) {
			if (active[i]) {
				actives.push_back(i);
				actSorted.emplace_back(tin[i], i);
			}
		}
		sort(actSorted.begin(), actSorted.end());
		
		for (int i = 1; i < (int)actSorted.size(); i++) {
			int l = lca(actSorted[i-1].second, actSorted[i].second);
			if (!active[l]) {
				active[l] = true;
				actives.push_back(l);
			}
		}
		
		int upmost = actives[0];
		for (int i: actives) {
			if (d[i] < d[upmost]) {
				upmost = i;
			}
		}
		
		int asz = actives.size();
		vector<int> aid(n, -1);
		for (int i = 0; i < asz; i++) {
			aid[actives[i]] = i;
		}
		
		vector< vector<int> > sg(asz);
		vector<char> purged(asz, false);
		vector<int> pre(asz), deg(asz), mdeg(asz);
		vector<int> pushed(asz);
		for (int i = 0; i < asz; i++) {
			int v = actives[i];
			if (v == upmost) {
				pre[i] = -1;
				continue;
			}
			v = p[v];
			int d = !state[v], md = 1;
			while (!active[v]) {
				v = p[v];
				d += !state[v];
				md++;
			}
			pre[i] = aid[v];
			deg[i] = d;
			mdeg[i] = md;
			sg[pre[i]].push_back(i);
		}
		
		function<void(int)> push = [&](int v) {
			pushed[v]++;
			for (int to: sg[v]) {
				if (deg[to] > 0) {
					deg[to]--;
				} else {
					push(to);
				}
			}
		};
		
		function<void(int)> clean = [&](int v) {
			pushed[v] = 0;
			purged[v] = true;
			for (int to: sg[v]) {
				deg[to] = mdeg[to];
				clean(to);
			}
		};
		
		auto ask = [&](int v) {
			bool res = purged[v] ? false : state[actives[v]];
			res |= pushed[v];
			return res;
		};
		
		for (int i = ql; i < qr; i++) {
			int type = qry[i].type, v = aid[qry[i].v];
			assert(v >= 0);
			switch (type) {
				case 1: {
					push(v);
				} break;
				case 2: {
					clean(v);
				} break;
				case 3: {
					cout << (ask(v) ? "black" : "white") << "\n";
				} break;
				default: {
					assert(false);
				}
			}
		}
		
		function<void(int, int, bool)> recalc = [&](int v, int push, bool del) {
			if (active[v]) {
				int w = aid[v];
				push = pushed[w];
				del = purged[w];
			}
			if (del) {
				state[v] = false;
			}
			if (!state[v] && push) {
				push--;
				state[v] = true;
			}
			for (int to: g[v]) {
				recalc(to, push, del);
			}
		};
		recalc(upmost, 0, false);
	}
	
	return 0;
}