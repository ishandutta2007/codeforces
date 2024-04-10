#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>
#define int int64_t

using namespace std;

const int64_t infinity = LLONG_MAX;

class MinCostFlow {
	private:
		struct Edge {
			int src, dst, cost, cap, flow;
			
			Edge() {
			}
			
			Edge(int src, int dst, int cost, int cap, int flow)
				: src(src), dst(dst), cost(cost), cap(cap), flow(flow) {
			}
		};
		
		int n, f, s, t;
		vector<Edge> edges;
		vector< vector<int> > g;
		vector<int> d, p, pEdge, phi;
		
		inline void assignPriorities() {
			phi.assign(n, infinity);
			phi[s] = 0;
			bool ok = true;
			while (ok) {
				ok = false;
				for (Edge edge: edges) {
					if (phi[edge.src] != infinity && edge.cap > edge.flow) {
						if (phi[edge.dst] > phi[edge.src] + edge.cost) {
							phi[edge.dst] = phi[edge.src] + edge.cost;
						}
					}
				}
			}
		}
		
		typedef pair<int, int> IntPair;
		
		inline bool dijkstra() {
			priority_queue<IntPair, vector<IntPair>, greater<IntPair> > q;
			d.assign(n, infinity);
			p.assign(n, -1);
			pEdge.assign(n, -1);
			d[s] = 0;
			p[s] = s;
			q.emplace(d[s], s);
			while (!q.empty()) {
				int way, v; tie(way, v) = q.top(); q.pop();
				if (d[v] != way) {
					continue;
				}
				for (int eid: g[v]) {
					if (edges[eid].cap > edges[eid].flow) {
						int to = edges[eid].dst;
						int len = edges[eid].cost + phi[v] - phi[to];
						if (d[to] > way + len) {
							d[to] = way + len;
							p[to] = v;
							pEdge[to] = eid;
							q.emplace(d[to], to);
						}
					}
				}
			}
			return p[t] >= 0;
		}
	public:
		inline pair<int, int> flowCost() {
			//assignPriorities();
			phi.assign(n, 0);
			int flow = 0, cost = 0;
			while (flow < f) {
				if (!dijkstra()) {
					break;
				}
				for (int i = 0; i < n; i++) {
					if (p[i] >= 0) {
						phi[i] += d[i];
					}
				}
				int add = f - flow;
				for (int v = t; v != s; v = p[v]) {
					int eid = pEdge[v];
					add = min(add, edges[eid].cap - edges[eid].flow);
				}
				flow += add;
				for (int v = t; v != s; v = p[v]) {
					int eid = pEdge[v];
					cost += add * edges[eid].cost;
					edges[eid].flow += add;
					edges[eid^1].flow -= add;
				}
			}
			return make_pair(flow, cost);
		}
		
		inline void addEdge(int src, int dst, int cost, int cap) {
			g[src].push_back(edges.size());
			edges.emplace_back(src, dst, cost, cap, 0);
			g[dst].push_back(edges.size());
			edges.emplace_back(dst, src, -cost, 0, 0);
		}	
	
		MinCostFlow(int n, int f, int s, int t)
			: n(n), f(f), s(s), t(t), g(n), d(n), p(n), pEdge(n), phi(n) {
		}
};

signed main() {
	string s; cin >> s;
	vector<int> must(26, 0);
	for (char c: s) {
		must[c - 'a']++;
	}
	int n; cin >> n;
	vector< vector<int> > v(n, vector<int>(26, 0));
	vector<int> f(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (char c: s) {
			v[i][c - 'a']++;
		}
		cin >> f[i];
	}
	const int src = 0;
	const int wordOffs = src + 1;
	const int letterOffs = wordOffs + n;
	const int dst = letterOffs + 26;
	const int cnt = dst + 1;
	MinCostFlow mcmf(cnt, infinity, src, dst);
	for (int i = 0; i < n; i++) {
		mcmf.addEdge(src, wordOffs + i, 0, f[i]);
		for (int j = 0; j < 26; j++) {
			mcmf.addEdge(wordOffs + i, letterOffs + j, i+1, v[i][j]);
		}
	}
	for (int i = 0; i < 26; i++) {
		mcmf.addEdge(letterOffs + i, dst, 0, must[i]);
	}
	int flow, cost; tie(flow, cost) = mcmf.flowCost();
	if (flow == (int)s.size()) {
		cout << cost << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}