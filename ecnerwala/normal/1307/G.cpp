#include<bits/extc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

const int MAXN = 60;
const int MAXM = MAXN * MAXN;
int N, M;

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

	vector<pair<flow_t, cost_t>> maxflow(int s, int t) {
		assert(s != t);
		flow_t totFlow = 0; cost_t totCost = 0;
		vector<pair<flow_t, cost_t>> res;
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

			res.emplace_back(totFlow, totCost);
		}
		return res;
	}
};

const int MAXV = 1.1e5;
const int V = int(1e5) + 100;
double ans[MAXV];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	MCMF_SSPA<> mf(N);
	for (int e = 0; e < M; e++) {
		int u, v; ll w; cin >> u >> v >> w; u--, v--;
		mf.addEdge(u, v, 1, w);
	}
	auto flows = mf.maxflow(0, N-1);
	int i = 0;
	for (int v = 0; v <= V; v++) {
		while (i+1 < int(flows.size()) && (v + flows[i+1].second) * flows[i].first < (v + flows[i].second) * flows[i+1].first) i++;
		ans[v] = double(v + flows[i].second) / flows[i].first;
	}
	int Q; cin >> Q;
	while (Q--) {
		int x; cin >> x;
		cout << fixed << setprecision(10) << ans[x] << '\n';
	}

	return 0;
}