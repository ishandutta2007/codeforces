#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

struct Graph {
	struct Edge {
		int high, low;
		Edge(int a, int b) {
			high = a;
			low = b;
		}
	};
	struct Path {
		int high, mid, low;
		Path(int a, int b, int c) {
			high = a;
			mid = b;
			low = c;
		}
	};
	vector<set<int>> g;
	vector<Path> cover;
	vector<bool> visited;
	Graph(int n) {
		g.resize(n+1);
		visited.resize(n+1);
	}
	void print_cover() {
		cout << cover.size() << nl;
		for (Path p: cover) {
			cout << p.high << " " << p.mid << " " << p.low << nl;
		}
	}
	void add_edge(int a, int b) {
		g[a].insert(b);
		g[b].insert(a);
	}
	bool dfs(int curr, int prev) {
		if (visited[curr]) {
			// end of dfs branch
			// remove reverse edge
			g[curr].erase(prev);
			return false;
		}
		visited[curr] = true;
		vector<Edge> extra;
		for (int neighbour: g[curr]) {
			if (neighbour != prev) {
				// add to cover
				if (!dfs(neighbour, curr)) {
					// found match
					extra.push_back(Edge(neighbour, curr));
				}
			}
		}
		if (prev != -1) {
			extra.push_back(Edge(prev, curr));
		}
		for (int i = 1; i < extra.size(); i+=2) {
			cover.push_back(Path(extra[i].high, extra[i].low, extra[i-1].high));
		}
		return (extra.size() % 2 == 0);
	}
};

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	int n, m, a, b;
	cin >> n >> m;
	Graph graph(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph.add_edge(a,b);
	}
	for (int i = 1; i <= n; i++) {
		if (!graph.visited[i]) {
			graph.dfs(i, -1);
		}
	}
	graph.print_cover();

	return 0;
}