// If graph is bipartite:
 // get any spanning tree, go greedy from leaves
 // actually, single DFS
 
// else:
 // there is odd-size cycle
 // sum of everything needs to be even

#include <bits/stdc++.h>
using namespace std;

struct test_case {
	vector<vector<int>> edges;
	vector<long long> value;
	vector<int> color; // 0 if not visited
	bool bipartite = true;
	void dfs(int a) {
		for(int b : edges[a]) {
			if(color[b] == 0) {
				color[b] = 3 - color[a];
				dfs(b);
				value[a] -= value[b];
			}
			else {
				if(color[a] == color[b]) {
					bipartite = false;
				}
			}
		}
	}
	void solve() {
		int n, m;
		scanf("%d%d", &n, &m);
		edges.resize(n);
		value.resize(n);
		for(int rep : {1, -1}) {
			for(int i = 0; i < n; ++i) {
				int x;
				scanf("%d", &x);
				value[i] += x * rep;
			}
		}
		for(int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			edges[a-1].push_back(b-1);
			edges[b-1].push_back(a-1);
		}
		color.resize(n);
		color[0] = 1;
		dfs(0);
		if(!bipartite) {
			value[0] %= 2;
		}
		puts(value[0] == 0 ? "YES" : "NO");
	}
};

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case x;
		x.solve();
	}
}