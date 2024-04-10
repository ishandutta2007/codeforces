#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Edge {
	int from;
	int to;
	int cap;
	int cost;
	int flow;
};

struct Network {
	int n, s, t;
	vector<vector<int>> a;
	vector<Edge> edges;
	vector<int> phi;
	vector<int> pr;

	Network(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
		a.resize(n);
	}

	void add_edge(int from, int to, int cap, int cost) {
		a[from].push_back(edges.size());
		edges.push_back({from, to, cap, cost, 0});
		a[to].push_back(edges.size());
		edges.push_back({to, from, 0, -cost, 0});
	}

	void dijkstra() {
		vector<int> dist(n, INT_MAX / 2);
		dist[s] = 0;
		pr.assign(n, -1);
		set<pair<int, int>> S = {{0, s}};

		while (!S.empty()) {
			auto p = *S.begin();
			S.erase(S.begin());
			int v = p.second;

			for (auto ed_idx : a[v]) {
				auto ed = edges[ed_idx];
				if (ed.flow == ed.cap) {
					continue;
				}
				if (dist[ed.to] > dist[v] + ed.cost + phi[ed.from] - phi[ed.to]) {
					if (dist[ed.to] < INT_MAX / 3) {
						S.erase({dist[ed.to], ed.to});
					}
					dist[ed.to] = dist[v] + ed.cost + phi[ed.from] - phi[ed.to];
					pr[ed.to] = ed_idx;
					S.insert({dist[ed.to], ed.to});
				}
			}
		}

		phi.swap(dist);
	}

	void ford_bellman() {
		vector<int> ed_ids;
		queue<int> q;
		vector<char> used(n);
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (auto id : a[v]) {
				auto ed = edges[id];
				if (ed.cap == ed.flow) {
					continue;
				}
				ed_ids.push_back(id);
				if (used[ed.to]) {
					continue;
				}
				used[ed.to] = 1;
				q.push(ed.to);
			}
		}

		vector<int> dist(n, INT_MAX / 2);
		pr.assign(n, -1);
		dist[s] = 0;
		bool changed = false;
		do {
			changed = false;
			for (int id : ed_ids) {
				auto ed = edges[id];
				if (dist[ed.to] > dist[ed.from] + ed.cost) {
					dist[ed.to] = dist[ed.from] + ed.cost;
					pr[ed.to] = ed.from;
					changed = true;
				}
			}
		} while (changed);
	}

	int64_t mincostflow(int flow = INT_MAX) {
		int64_t cost = 0;
		phi.assign(n, 0);
		while (flow) {
			int cur_flow = flow;
			dijkstra();
			assert(pr[t] > -1);
			vector<int> ed_ids;
			int cur_v = t;
			while (cur_v != s) {
				ed_ids.push_back(pr[cur_v]);
				cur_flow = min(cur_flow, edges[pr[cur_v]].cap - edges[pr[cur_v]].flow);
				cur_v = edges[pr[cur_v]].from;
			}
			flow -= cur_flow;
			for (auto id : ed_ids) {
				cost += 1ll * edges[id].cost * cur_flow;
				edges[id].flow += cur_flow;
				edges[id ^ 1].flow -= cur_flow;
			}
		}

		return cost;
	}

	void show_flow() {
		for (int i = 0; i < n; ++i) {
			for (int id : a[i]) {
				auto ed = edges[id];
				if (ed.flow == 0) {
					continue;
				}
				cerr << ed.from << " -> " << ed.to << ": flow = " << ed.flow << " (cost = " << ed.cost << ")\n";
			}
		}
	}
};

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	Network net(2 * n + 2, 2 * n, 2 * n + 1);
	for (int i = 0; i < n; ++i) {
		net.add_edge(2 * n, 2 * i, 1, 0);
		net.add_edge(2 * i + 1, 2 * n + 1, 1, 0);
		net.add_edge(2 * i, 2 * i + 1, 1, -1);
		for (int j = i + 1; j < n; ++j) {
			if (a[j] == a[i] + 1) {
				net.add_edge(2 * i + 1, 2 * j, 1, 0);
				break;
			}
		}
		for (int j = i + 1; j < n; ++j) {
			if (a[j] == a[i] - 1) {
				net.add_edge(2 * i + 1, 2 * j, 1, 0);
				break;
			}
		}

		for (int j = i + 1; j < n; ++j) {
			if (a[i] == a[j]) {
				net.add_edge(2 * i, 2 * j, 1, 0);
				net.add_edge(2 * i + 1, 2 * j + 1, 1, 0);
				break;
			}
		}
		
		for (int j = i + 1; j < n; ++j) {
			if (a[j] % 7 == a[i] % 7) {
				net.add_edge(2 * i + 1, 2 * j + 1, 1, 0);
				net.add_edge(2 * i + 1, 2 * j, 1, 0);
				break;
			}
		}
	}

	cout << -net.mincostflow(2) << "\n";

	// net.show_flow();

	return 0;
}