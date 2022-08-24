#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Graph {
	void read(int m) {
		e.resize(n);
		
		for (int i = 0; i < m; ++i) {
			int u = nxt(), v = nxt();
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	
	/* COMMON PART */
	
	int n;
	vector<vector<int>> e;
	
	int counter = 1;
	vector<int> inTime, minInTime;

	void dfs(int v, int p = -1) {
		minInTime[v] = inTime[v] = counter++;

		for (int u: e[v]) {
			if (u == p) continue;

			if (!inTime[u]) {
				dfs(u, v);
				minInTime[v] = min(minInTime[v], minInTime[u]);
			}
			else {
				minInTime[v] = min(minInTime[v], inTime[u]);
			}
		}
	}
	
	vector<char> used;
	
	/* COMPONENTS SEPARATED BY BRIDGES (COLORING) */
	
	int nColors;
	vector<int> color;
	
	void colorDfs(int v, int curColor) {
		color[v] = curColor;
		
		for (int u: e[v]) {
			if (color[u] != -1) continue;
			
			colorDfs(u, minInTime[u] > inTime[v] ? nColors++ : curColor);
		}
	}
	
	void findVertexComponents() {
		inTime.assign(n, 0);
		minInTime.assign(n, 0);
		counter = 1;

		for (int i = 0; i < n; ++i)
			if (!inTime[i])
				dfs(i);

		nColors = 0;
		color.assign(n, -1);
		for (int i = 0; i < n; ++i)
			if (color[i] == -1) {
				colorDfs(i, nColors++);
			}
	}

	/* COMPONENTS SEPARATED BY JOINTS (EDGE COMPONENTS) */
	
	struct Edge {
		int u, v;
	};
	
	// Cactus loops can be parsed as .u of every edge
	vector<vector<Edge>> edgeComps;
	
	vector<int> colorStack;
	
	void edgeCompDfs(int v, int p = -1) {
		used[v] = true;
		
		for (int u: e[v]) {
			if (used[u]) {
				if (inTime[u] < inTime[v] && u != p) {
					// NOTE:  && u != p makes one-edge components contain exactly one edge;
					// if you need them as two-edge loops, remove this part of if condition
					edgeComps[colorStack.back()].push_back({v, u});
				}
				
				continue;
			}

			bool newComp = minInTime[u] >= inTime[v];
			
			if (newComp) {
				colorStack.push_back(edgeComps.size());
				edgeComps.emplace_back();
			}
			
			edgeComps[colorStack.back()].push_back({v, u});
			edgeCompDfs(u, v);

			if (newComp) {
				colorStack.pop_back();
			}
		}
	}
	
	void findEdgeComponents() {
		inTime.assign(n, 0);
		minInTime.assign(n, 0);
		counter = 1;

		for (int i = 0; i < n; ++i)
			if (!inTime[i])
				dfs(i);

		used.assign(n, false);
		colorStack.clear();
		edgeComps.clear();
		for (int i = 0; i < n; ++i)
			if (!used[i]) {
				assert(colorStack.empty());
				edgeCompDfs(i);
			}
	}
};

struct MyEdge {
	int to, w;
};

struct Tree {
	int n;
	vector<vector<MyEdge>> a;
	vector<int> len;
	vector<int> level;
	vector<vector<int>> par;

	explicit Tree(int _n): n(_n), a(_n) {}

	void add_edge(int u, int v, int w) {
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}

	void dfsLen(int v, int p = -1) {
		for (auto e : a[v]) {
			if (e.to == p) continue;
			len[e.to] = len[v] + e.w;
			level[e.to] = level[v] + 1;
			par[e.to].push_back(v);
			dfsLen(e.to, v);
		}
	}

	void markAll() {
		len.assign(n, 0);
		level.assign(n, 0);
		par.resize(n);
		dfsLen(0);

		for (int i = 0;; ++i) {
			bool ok = false;
			for (int j = 0; j < n; ++j) {
				if ((int)par[j].size() <= i) {
					continue;
				}
				if ((int)par[par[j][i]].size() <= i) {
					continue;
				}
				int x = par[par[j][i]][i];
				par[j].push_back(x);
				ok = true;
			}
			if (!ok) {
				break;
			}
		}
	}

	int lca(int u, int v) {
		if (level[u] > level[v]) {
			swap(u, v);
		}
		for (int i = (int)par[v].size() - 1; i >= 0; --i) {
			if (i >= (int)par[v].size()) continue;
			if (level[par[v][i]] >= level[u]) {
				v = par[v][i];
			}
		}
		if (u == v) return v;
		for (int i = (int)par[v].size() - 1; i >= 0; --i) {
			if (i >= (int)par[v].size()) continue;
			if (par[v][i] != par[u][i]) {
				v = par[v][i];
				u = par[u][i];
			}
		}
		return par[v][0];
	}

	int dist(int u, int v) {
		return len[u] + len[v] - 2 * len[lca(u, v)];
	}
};

int main() {
	Graph g;
	g.n = nxt();
	int m = nxt(), q = nxt();
	g.read(m);

	g.findEdgeComponents();
	vector<set<int>> comps;
	for (const auto& v : g.edgeComps) {
		comps.emplace_back();
		for (const auto& e : v) {
			comps.back().insert(e.u);
			comps.back().insert(e.v);
		}
	}

	int n = g.n;
	vector<vector<int>> ids(n);
	for (int i = 0; i < (int)comps.size(); ++i) {
		for (int v : comps[i]) {
			ids[v].push_back(i);
		}
	}
	vector<int> joints;
	for (int i = 0; i < n; ++i) {
		if ((int)ids[i].size() > 1) {
			joints.push_back(i);
		}
	}

	Tree tree(comps.size() + joints.size());
	for (int i = 0; i < (int)joints.size(); ++i) {
		for (int j : ids[joints[i]]) {
			tree.add_edge(j, i + (int)comps.size(), 1);
		}
	}
	tree.markAll();

	while (q--) {
		int u = nxt() - 1, v = nxt() - 1;
		if (ids[u].size() < ids[v].size()) {
			swap(u, v);
		}
		if (u == v) {
			printf("0\n");
			continue;
		}
		int s = (int)ids[u].size() > 1 ? lower_bound(all(joints), u) - joints.begin() + comps.size() : ids[u][0];
		int f = (int)ids[v].size() > 1 ? lower_bound(all(joints), v) - joints.begin() + comps.size() : ids[v][0];
		int ans = tree.dist(s, f);
		if ((int)ids[u].size() == 1) {
			++ans;
		}
		if ((int)ids[v].size() == 1) {
			++ans;
		}
		printf("%d\n", ans / 2);
	}

	return 0;
}