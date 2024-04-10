#include <bits/stdc++.h>

// #define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

void no() {
	cout << "NO\n";
	exit(0);
}

struct vertex {
	int id, dist, deg;

	bool operator<(const vertex &other) const {
		return tie(dist, deg, id) > tie(other.dist, other.deg, other.id);
	}

};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, d, k;
	cin >> n >> d >> k;
	if (d >= n) {
		no();
	}
	if (k < 2) {
		if (n == 2) {
			cout << "YES\n1 2\n";
			return 0;
		}
		no();
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < d; ++i) {
		graph[i].push_back(i + 1);
		graph[i + 1].push_back(i);
	}
	priority_queue<vertex> pq;
	for (int i = 1; i < d; ++i) {
                if (k > 2) pq.push({i, min(i, d - i), 2});
	}
	int need_vertices = n - d - 1;
	int idx = d; // index of last created vertex
	while (need_vertices && !pq.empty()) {
		auto best = pq.top();
		pq.pop();
		for (int i = 0; need_vertices && i < best.dist; ++i) {
			int from = (i ? idx : best.id);
			int to = ++idx;
			graph[from].push_back(to);
			graph[to].push_back(from);
			--need_vertices;
			if (!i) {
				int new_deg = best.deg + 1;
				if (new_deg < k) {
					pq.push({from, best.dist, new_deg});
				}
				continue;
			}
			int new_dist = best.dist - i;
			pq.push({from, new_dist, 2});
		}
	}
	if (need_vertices) {
		no();
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int u: graph[i]) {
			if (u > i) {
				cout << i + 1 << " " << u + 1 << "\n";
			}
		}
	}
	return 0;	
}