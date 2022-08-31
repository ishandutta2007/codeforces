#include<bits/stdc++.h>
using namespace std;

#include<bits/extc++.h>
template <typename flow_t = int, typename cost_t = long long>
struct MCMF_SSPA {
	int N;
	vector<vector<int>> adj;
	struct edge_t {
		int dest;
		flow_t cap;
		cost_t cost;
	};
	vector<edge_t> edges;

	vector<char> seen;
	vector<cost_t> pi;
	vector<int> prv;

	explicit MCMF_SSPA(int N_) : N(N_), adj(N), pi(N, 0), prv(N) {}

	void addEdge(int from, int to, flow_t cap, cost_t cost) {
		assert(cap >= 0);
		int e = int(edges.size());
		edges.emplace_back(edge_t{to, cap, cost});
		edges.emplace_back(edge_t{from, 0, -cost});
		adj[from].push_back(e);
		adj[to].push_back(e+1);
	}

	const cost_t INF_COST = numeric_limits<cost_t>::max() / 4;
	const flow_t INF_FLOW = numeric_limits<flow_t>::max() / 4;
	vector<cost_t> dist;
	__gnu_pbds::priority_queue<pair<cost_t, int>> q;
	vector<typename decltype(q)::point_iterator> its;
	void path(int s) {
		dist.assign(N, INF_COST);
		dist[s] = 0;

		its.assign(N, q.end());
		its[s] = q.push({0, s});

		while (!q.empty()) {
			int i = q.top().second; q.pop();
			cost_t d = dist[i];
			for (int e : adj[i]) {
				if (edges[e].cap) {
					int j = edges[e].dest;
					cost_t nd = d + edges[e].cost;
					if (nd < dist[j]) {
						dist[j] = nd;
						prv[j] = e;
						if (its[j] == q.end()) {
							its[j] = q.push({-(dist[j] - pi[j]), j});
						} else {
							q.modify(its[j], {-(dist[j] - pi[j]), j});
						}
					}
				}
			}
		}

		swap(pi, dist);
	}

	pair<flow_t, cost_t> maxflow(int s, int t) {
		assert(s != t);
		flow_t totFlow = 0; cost_t totCost = 0;
		while (path(s), pi[t] < INF_COST) {
			flow_t curFlow = numeric_limits<flow_t>::max();
			for (int cur = t; cur != s; ) {
				int e = prv[cur];
				int nxt = edges[e^1].dest;
				curFlow = min(curFlow, edges[e].cap);
				cur = nxt;
			}
			totFlow += curFlow;
			totCost += pi[t] * curFlow;
			for (int cur = t; cur != s; ) {
				int e = prv[cur];
				int nxt = edges[e^1].dest;
				edges[e].cap -= curFlow;
				edges[e^1].cap += curFlow;
				cur = nxt;
			}
		}
		return {totFlow, totCost};
	}
};

const int MAXN = 60;
int N;
int M;
int inDeg[MAXN];
int outDeg[MAXN];
bool wins[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b; a--, b--;
		wins[a][b] = true;
		outDeg[a]++;
		inDeg[b]++;
	}

	MCMF_SSPA<> mcmf(2 + N + N * (N-1) / 2);
	int S = 0;
	int T = 1;
	for (int i = 0; i < N; i++) {
		for (int v = 0; v < N-1; v++) {
			mcmf.addEdge(S, 2+i, 1, v);
		}
	}

	int numE = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int eId = 2 + N + (numE++);
			bool unset = !wins[i][j] && !wins[j][i];
			if (wins[i][j] || unset) {
				mcmf.addEdge(2+i, eId, 1, 0);
			}
			if (wins[j][i] || unset) {
				mcmf.addEdge(2+j, eId, 1, 0);
			}

			mcmf.addEdge(eId, T, 1, 0);
		}
	}

	assert(numE == N * (N-1) / 2);

	auto res = mcmf.maxflow(S, T);
	//cerr << res.first << ' ' << res.second << '\n';
	assert(res.first == N * (N-1) / 2);

	numE = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int eId = 2 + N + (numE++);
			if (wins[i][j] || wins[j][i]) continue;
			auto edges = mcmf.adj[eId];
			assert(int(edges.size()) == 3);
			assert(mcmf.edges[edges[0]].dest == 2+i);
			assert(mcmf.edges[edges[1]].dest == 2+j);
			if (mcmf.edges[edges[0]].cap == 1) {
				wins[i][j] = true;
			} else if (mcmf.edges[edges[1]].cap == 1) {
				wins[j][i] = true;
			} else assert(false);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << int(wins[i][j]);
		}
		cout << '\n';
	}

	return 0;
}