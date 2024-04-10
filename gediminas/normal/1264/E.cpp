#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
3 1
1 2
*/
/*input
4 2
1 2
1 3
*/
/*input
5 0
*/
/*input
6 0
*/
/*input
7 0
*/

struct Edge {
	int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int> &d, vector<int> &p) {
	d.assign(n, INF);
	d[v0] = 0;
	vector<bool> inq(n, false);
	queue<int> q;
	q.push(v0);
	p.assign(n, -1);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;

		for (int v : adj[u]) {
			if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
				d[v] = d[u] + cost[u][v];
				p[v] = u;

				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
}

pair<int, int> min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
	adj.assign(N, vector<int>());
	cost.assign(N, vector<int>(N, 0));
	capacity.assign(N, vector<int>(N, 0));

	for (Edge e : edges) {
		adj[e.from].push_back(e.to);
		adj[e.to].push_back(e.from);
		cost[e.from][e.to] = e.cost;
		cost[e.to][e.from] = -e.cost;
		capacity[e.from][e.to] = e.capacity;
	}

	int flow = 0;
	int cost = 0;
	vector<int> d, p;

	while (flow < K) {
		shortest_paths(N, s, d, p);

		if (d[t] == INF) {
			break;
		}

		// find max flow on that path
		int f = K - flow;
		int cur = t;

		while (cur != s) {
			f = min(f, capacity[p[cur]][cur]);
			cur = p[cur];
		}

		// apply flow
		flow += f;
		cost += f * d[t];
		cur = t;

		while (cur != s) {
			capacity[p[cur]][cur] -= f;
			capacity[cur][p[cur]] += f;
			cur = p[cur];
		}
	}

	return {flow, cost};
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int N = 2;
	int a[n][n] = {};
	int cnt[n] = {};

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x][y] = 1;
		a[y][x] = -1;
		cnt[x]++;
	}

	int b[n][n];
	int t[n];
	int op[n];

	vector<Edge> edges;

	for (int i = 0; i < n; ++i) {
		op[i] = N++;
		edges.push_back({op[i], 1, n, 0});
	}

	for (int i = 0; i < n; ++i) {
		t[i] = N++;

		for (int k = cnt[i]; k < n - 1; ++k) {
			int cur = (k + 1) * (k + 1) - (k * k);
			edges.push_back({t[i], op[k], 1, cur});
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i][j] == 0 and i != j) {
				b[i][j] = N++;
				edges.push_back({0, b[i][j], 1, 0});
				edges.push_back({b[i][j], t[i], 1, 0});
				edges.push_back({b[i][j], t[j], 1, 0});
			}
		}
	}

	auto ans = min_cost_flow(N, edges, INF, 0, 1);
	debug(ans);
	debug(dbgarr(op, n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == 0 and i != j) {
				if (i < j) {
					cout << capacity[b[i][j]][t[j]];
				}
				else {
					cout << capacity[b[j][i]][t[j]];
				}
			}
			else {
				cout << (a[i][j] > 0);
			}
		}

		cout << "\n";
	}
}