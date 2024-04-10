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
const int mod = module;
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

class DinitzFlow {
private:
	struct Edge {
		int src, dst, cap, flow;
		
		Edge() {
		}
		
		Edge(int src, int dst, int cap, int flow)
			: src(src), dst(dst), cap(cap), flow(flow) {
		}
	};
	
	int n, s, t;
	vector<Edge> edges;
	vector< vector<int> > g;
	vector<int> layer;
	vector<int> ptr;
	
	inline bool bfs() {
		layer.assign(n, -1);
		queue<int> q;
		layer[s] = 0;
		q.push(s);
		while (!q.empty() && layer[t] < 0) {
			int v = q.front(); q.pop();
			for (int eid: g[v]) {
				int to = edges[eid].dst;
				if (edges[eid].cap > edges[eid].flow) {
					if (layer[to] < 0) {
						layer[to] = layer[v] + 1;
						q.push(to);
					}
				}
			}
		}
		return layer[t] >= 0;
	}
	
	int dfs(int v, int flow = infinity) {
		if (v == t) {
			return flow;
		}
		if (flow == 0) {
			return 0;
		}
		for (; ptr[v] < (int)g[v].size(); ptr[v]++) {
			int eid = g[v][ptr[v]];
			int to = edges[eid].dst;
			if (layer[to] == layer[v] + 1) {
				int can = edges[eid].cap - edges[eid].flow;
				int pushed = dfs(to, min(flow, can));
				if (pushed > 0) {
					edges[eid].flow += pushed;
					edges[eid^1].flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
public:
	inline int flow() {
		int ans = 0;
		while (bfs()) {
			ptr.assign(n, 0);
			int pushed = dfs(s);
			while (pushed != 0) {
				ans += pushed;
				pushed = dfs(s);
			}
		}
		return ans;
	}
	
	inline void addEdge(int src, int dst, int cap) {
		g[src].push_back(edges.size());
		edges.emplace_back(src, dst, cap, 0);
		g[dst].push_back(edges.size());
		edges.emplace_back(dst, src, 0, 0);
	}
	
	DinitzFlow(int n, int s, int t)
		: n(n), s(s), t(t), g(n), layer(n), ptr(n) {
	}
};

struct Rect {
	int x1, y1, x2, y2;
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, k; cin >> n >> k;
	set<int> xs {0, n}, ys {0, n};
	vector<Rect> v(k);
	for (Rect &r : v) {
		cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
		--r.x1; --r.y1;
		xs.insert(r.x1);
		xs.insert(r.x2);
		ys.insert(r.y1);
		ys.insert(r.y2);
	}
	int xc = (int)xs.size() - 1, yc = (int)ys.size() - 1;
	vector<int> xa(begin(xs), end(xs)), ya(begin(ys), end(ys));
	
	auto xind = [&](int val) {
		return lower_bound(begin(xa), end(xa), val) - begin(xa);
	};
	
	auto yind = [&](int val) {
		return lower_bound(begin(ya), end(ya), val) - begin(ya);
	};
	
	const int src = xc+yc, dst = xc+yc+1;
	DinitzFlow flow(xc+yc+2, src, dst);
	for (int i = 0; i < xc; ++i) {
		flow.addEdge(src, i, xa[i+1] - xa[i]);
	}
	for (int i = 0; i < yc; ++i) {
		flow.addEdge(i+xc, dst, ya[i+1] - ya[i]);
	}
	
	vector< vector<char> > used(xc, vector<char>(yc));
	auto eadd = [&](int x, int y) {
		if (!used[x][y]) {
			flow.addEdge(x, y+xc, infinity);
			used[x][y] = true;
		}
	};
	
	for (Rect r: v) {
		r.x1 = xind(r.x1);
		r.y1 = yind(r.y1);
		r.x2 = xind(r.x2);
		r.y2 = yind(r.y2);
		for (int i = r.x1; i < r.x2; ++i) {
			for (int j = r.y1; j < r.y2; ++j) {
				eadd(i, j);
			}
		}
	}
	cout << flow.flow() << endl;
	
	return 0;
}