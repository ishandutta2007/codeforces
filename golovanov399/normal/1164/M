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

struct Bipartite {
	int n, m;
	vector<vector<int>> a;

	Bipartite(int _n, int _m): n(_n), m(_m), a(_n) {}

	void addEdge(int u, int v) {
		a[u].push_back(v);
	}

	vector<char> used;
	vector<int> matching_left, matching_right;
	bool dfs(int u) {
		if (used[u]) {
			return false;
		}
		used[u] = true;
		for (int v : a[u]) {
			if (matching_right[v] == -1) {
				matching_left[u] = v;
				matching_right[v] = u;
				return true;
			}
		}
		for (int v : a[u]) {
			if (dfs(matching_right[v])) {
				matching_left[u] = v;
				matching_right[v] = u;
				return true;
			}
		}
		return false;
	}

	void fillGreedyMatching() {
		for (int i = 0; i < n; ++i) {
			for (int j : a[i]) {
				if (matching_right[j] == -1) {
					matching_left[i] = j;
					matching_right[j] = i;
					break;
				}
			}
		}
	}

	void kuhn() {
		matching_left.assign(n, -1);
		matching_right.assign(m, -1);
		fillGreedyMatching();
		for (int run = 1; run;) {
			run = 0;
			used.assign(n, false);
			for (int i = 0; i < n; ++i) {
				if (matching_left[i] == -1 && dfs(i)) {
					run = 1;
				}
			}
		}
	}

	array<vector<int>, 2> getVertexCover() {
		kuhn();
		vector<char> used_left(n), used_right(m);
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (matching_left[i] == -1) {
				q.push(i);
				used_left[i] = 1;
			}
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : a[u]) {
				if (used_right[v]) {
					continue;
				}
				used_right[v] = 1;
				if (matching_right[v] > -1 && !used_left[matching_right[v]]) {
					used_left[matching_right[v]] = true;
					q.push(matching_right[v]);
				}
			}
		}
		array<vector<int>, 2> res;
		for (int i = 0; i < n; ++i) {
			if (!used_left[i]) {
				res[0].push_back(i);
			}
		}
		for (int i = 0; i < m; ++i) {
			if (used_right[i]) {
				res[1].push_back(i);
			}
		}

		return res;
	}
};

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	int m = nxt();
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		b[i] = nxt();
	}

	Bipartite graph(n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (abs(a[i] - b[j]) <= 1) {
				graph.addEdge(i, j);
			}
		}
	}

	graph.kuhn();
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (graph.matching_left[i] > -1) {
			++ans;
		}
	}
	cout << ans << "\n";

	return 0;
}