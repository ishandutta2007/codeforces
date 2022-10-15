#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <climits>

using namespace std;

const int inf = 1234567890;
const int64_t inf64 = 123456789012345678LL;

inline void raiseError(const string &text) {
	cerr << "Error: " << text;
	exit(42);
}

class SegTree {
private:
	int n;
	vector<int> tree;
	vector<char> lazy;
	
	inline void push(int x, int tl, int tr) {
		if (!lazy[x]) {
			return;
		}
		tree[x] = (tr - tl + 1) - tree[x];
		lazy[x] = false;
		if (tl != tr) {
			lazy[x*2] ^= 1;
			lazy[x*2+1] ^= 1;
		}
	}
	
	void update(int x, int tl, int tr, int l, int r) {
		push(x, tl, tr);
		if (l > r) {
			return;
		}
		if (l == tl && r == tr) {
			lazy[x] = true;
			push(x, tl, tr);
			return;
		}
		int tm = (tl + tr) / 2;
		update(x*2, tl, tm, l, min(r, tm));
		update(x*2+1, tm+1, tr, max(l, tm+1), r);
		tree[x] = tree[x*2] + tree[x*2+1];
	}
	
	int sum(int x, int tl, int tr, int l, int r) {
		push(x, tl, tr);
		if (l > r) {
			return 0;
		}
		if (l == tl && r == tr) {
			return tree[x];
		}
		int tm = (tl + tr) / 2;
		return (
			sum(x*2, tl, tm, l, min(r, tm)) + 
			sum(x*2+1, tm+1, tr, max(l, tm+1), r)
		);
	}
public:
	inline int size() {
		return n;
	}
	
	inline void update(int l, int r) {
		if (l > r) {
			swap(l, r);
		}
		update(1, 0, n-1, l, r);
	}
	
	inline int sum(int l, int r) {
		if (l > r) {
			swap(l, r);
		}
		return sum(1, 0, n-1, l, r);
	}
	
	SegTree(int _n)
		: n(_n), tree(4*_n, 0), lazy(4*_n, false) {
	}
	
	SegTree() {
	}
};

struct HeavyLightDecomposition {
	int n;
	vector< vector<int> > g;
	vector<int> depth;
	vector<int> par;
	vector<int> gPar;
	vector<int> size;
	vector<int> treeId;
	vector<int> pathId;
	vector< vector<int> > paths;
	SegTree tree;
	vector<int> loop;
	
	struct Query {
		int l, r;
	};
	
	void dfs(int v, int p = -1) {
		depth[v] = (p < 0) ? 0 : (depth[p] + 1);
		par[v] = p;
		gPar[v] = (p < 0) ? v : gPar[p];
		size[v] = 1;
		int bestSon = -1;
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			dfs(to, v);
			size[v] += size[to];
			if (bestSon < 0 || size[to] > size[bestSon]) {
				bestSon = to;
			}
		}
		if (bestSon < 0 || p < 0) {
			pathId[v] = paths.size();
			paths.emplace_back();
		} else {
			pathId[v] = pathId[bestSon];
		}
		paths[pathId[v]].push_back(v);
	}
	
	inline void build() {
		for (int i : loop) {
			dfs(i);
		}
		int ktr = 0;
		for (auto &path : paths) {
			for (int v : path) {
				treeId[v] = ktr++;
			}
		}
	}
	
	inline int lca(int u, int v) {
		while (pathId[u] != pathId[v]) {
			int hiU = paths[pathId[u]].back();
			int hiV = paths[pathId[v]].back();
			if (depth[hiU] > depth[hiV]) {
				u = par[hiU];
			} else {
				v = par[hiV];
			}
		}
		return (depth[u] < depth[v]) ? u : v;
	}
	
	inline vector<Query> querify(int u, int v) {
		vector<Query> front, back;
		while (pathId[u] != pathId[v]) {
			int hiU = paths[pathId[u]].back();
			int hiV = paths[pathId[v]].back();
			if (depth[hiU] > depth[hiV]) {
				front.push_back({treeId[u], treeId[hiU]});
				u = par[hiU];
			} else {
				back.push_back({treeId[hiV], treeId[v]});
				v = par[hiV];
			}
		}
		front.push_back({treeId[u], treeId[v]});
		front.insert(front.end(), back.rbegin(), back.rend());
		return front;
	}
	
	inline void invert(int u, int v) {
		for (const Query &query : querify(u, v)) {
			tree.update(query.l, query.r);
		}
	}
	
	inline int getOnVertex(int v) {
		return tree.sum(treeId[v], treeId[v]);
	}
	
	inline int sumAll() {
		return tree.sum(0, n-1);
	}
	
	HeavyLightDecomposition(int n)
		: n(n), g(n), depth(n), par(n), gPar(n), size(n), treeId(n), 
			pathId(n), paths(), tree(n), loop() {
	}
};

int main() {
	#ifdef __LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	
	int n, q; cin >> n >> q;
	vector< pair<int, int> > edg(n);
	vector<char> looped(n, false);
	vector<int> loopIdx(n, -1);
	vector<int> loop;
	vector< vector<int> > g(n);
	vector<char> used(n, false);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		edg[i] = {a, b};
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	function<bool(int, int)> dfs = [&](int v, int p) {
		used[v] = true;
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			if (used[to]) {
				looped[v] = looped[to] = true;
				loop.push_back(to);
				loop.push_back(v);
				return true;
			}
			if (dfs(to, v)) {
				if (looped[v]) {
					return false;
				}
				looped[v] = true;
				loop.push_back(v);
				return true;
			}
		}
		return false;
	};
	dfs(0, -1);
	
	HeavyLightDecomposition hld(n);
	hld.loop = loop;
	for (int i = 0; i < n; i++) {
		int a, b; tie(a, b) = edg[i];
		if (looped[a] && looped[b]) {
			continue;
		}
		hld.g[a].push_back(b);
		hld.g[b].push_back(a);
	}
	hld.build();
	int lS = loop.size();
	SegTree st(lS);
	for (int i = 0; i < lS; i++) {
		loopIdx[loop[i]] = i;
	}
	
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--; b--;
		int pA = hld.gPar[a], pB = hld.gPar[b];
		
		if (pA == pB) {
			int lca = hld.lca(a, b);
			hld.invert(a, b);
			hld.invert(lca, lca);
		} else {
			hld.invert(a, pA);
			hld.invert(pA, pA);
			hld.invert(b, pB);
			hld.invert(pB, pB);
			
			int lA = loopIdx[pA], lB = loopIdx[pB];
			int oLA = lA;
			bool inv = false;
			if (lA > lB) {
				swap(lA, lB);
				inv = true;
			}
			int dist1 = lB - lA;
			int dist2 = lA - lB + lS;
			bool take1 = dist1 < dist2;
			if (dist1 == dist2) {
				take1 = inv ^ (loop[(oLA + 1) % lS] < loop[(oLA + lS - 1) % lS]);
			}
			
			if (take1) {
				st.update(lA, lB-1);
			} else {
				if (lA != 0) {
					st.update(0, lA-1);
				}
				st.update(lB, lS-1);
			}
		}
		
		int sSum = st.sum(0, lS-1);
		if (sSum == lS) {
			sSum--;
		}
		cout << n - hld.sumAll() - sSum << "\n";
	}
	return 0;
}