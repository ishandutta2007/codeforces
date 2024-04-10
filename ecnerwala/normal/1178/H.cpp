#include<bits/extc++.h>
using namespace std;

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
		//cerr << "path " << s << '\n';
		dist.assign(N, INF_COST);
		dist[s] = 0;

		its.assign(N, q.end());
		its[s] = q.push({0, s});

		while (!q.empty()) {
			int i = q.top().second; q.pop();
			cost_t d = dist[i];
			//cerr << i << ' ' << d << '\n';
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

	explicit MCMF_SSPA(int N_) : N(N_), adj(N), pi(N, 0), prv(N) {}
};

using ll = long long;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
	int N;
	vector<vi> ed, red;
	vector<unordered_map<int, ll>> cap, flow, cost;
	vi seen;
	VL dist, pi;
	vector<pii> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		//cerr << from << ' ' << to << ' ' << cap << ' ' << cost << '\n';
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, ll cap, ll cost, int dir) {
			ll val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			trav(i, ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			trav(i, red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		rep(i,0,N) trav(j, ed[i]) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
				trav(to, ed[i]) if (cap[i][to])
				if ((v = pi[i] + cost[i][to]) < pi[to])
					pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

const int MAXN = 2 * 3000;
ll A[MAXN], B[MAXN];
int N;

vector<pair<pair<ll, ll>, int>> startPts;

bool isGood(ll T) {
	vector<ll> goals;
	for (int k = N; k < 2 * N; k++) {
		goals.push_back(A[k] * T + B[k]);
	}
	vector<ll> cans;
#if 1
	ll bestEnd = -1;
	for (int z = 0; z < 2 * N; z++) {
		int i = startPts[z].second;
		bestEnd = max(bestEnd, B[i] + T * A[i]);
		if (i < N) {
			cans.push_back(bestEnd);
		}
	}
#else
	for (int i = 0; i < N; i++) {
		ll bestEnd = A[i] * T + B[i];
		for (int j = 0; j < 2 * N; j++) {
			if (B[i] >= B[j]) {
				bestEnd = max(bestEnd, A[j] * T + B[j]);
			}
		}
		cans.push_back(bestEnd);
	}
#endif

	sort(goals.begin(), goals.end());
	sort(cans.begin(), cans.end());
	for (int i = 0; i < N; i++) {
		if (cans[i] >= goals[i]) {
			// it's good
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < 2 * N; i++) {
		cin >> A[i] >> B[i];
	}

	for (int i = 0; i < 2 * N; i++) {
		startPts.emplace_back(pair<ll, ll>(B[i], -A[i]), i);
	}
	sort(startPts.begin(), startPts.end());

	ll mi = -1;
	ll ma = ll(1.1e9);
	if (!isGood(ma)) {
		cout << -1 << '\n';
		exit(0);
	}

	while (ma - mi > 1 ){
		ll md = (mi + ma) / 2;
		if (isGood(md)) {
			ma = md;
		} else {
			mi = md;
		}
	}

	ll T = ma;

	vector<ll> dleft;
	vector<ll> dright;
	for (int i = 0; i < 2 * N; i++) {
		dleft.emplace_back(B[i]);
		dright.emplace_back(A[i] * T + B[i]);
		//cerr << i << ' ' << dleft.back() << ' ' << dright.back() << '\n';
	}
	sort(dleft.begin(), dleft.end());
	dleft.resize(unique(dleft.begin(), dleft.end()) - dleft.begin());
	sort(dright.begin(), dright.end());
	dright.resize(unique(dright.begin(), dright.end()) - dright.begin());

	int source = 2 * N;
	int sink = 2 * N + 1;
	int leftOff = 2 + 2 * N;
	int rightOff = leftOff + int(dleft.size());

	MCMF_SSPA<> mf(2 + 2 * N + int(dleft.size()) + int(dright.size()));
	auto addEdge = [&] (int a, int b, int c, int d) {
		mf.addEdge(a, b, c, d);
	};

	for (int i = 0; i < N; i++) {
		addEdge(source, i, 1, 0);
	}
	for (int j = N; j < 2 * N; j++) {
		addEdge(j, sink, 1, 0);
	}

	for (int i = 0; i < 2 * N; i++) {
		int leftInd = int(lower_bound(dleft.begin(), dleft.end(), B[i]) - dleft.begin());
		int rightInd = int(lower_bound(dright.begin(), dright.end(), A[i] * T + B[i]) - dright.begin());
		addEdge(leftOff + leftInd, rightOff + rightInd, N, 0);
		if (i < N) {
			addEdge(i, rightOff + rightInd, 1, 0);
		} else {
			addEdge(leftOff + leftInd, i, 1, 0);
		}
	}

	for (int i = 0; i < 2 * N; i++) {
		int leftInd = int(lower_bound(dleft.begin(), dleft.end(), B[i]) - dleft.begin());
		int rightInd = int(lower_bound(dright.begin(), dright.end(), A[i] * T + B[i]) - dright.begin());
		if (i < N) {
			addEdge(i, leftOff + leftInd, 1, 1);
		} else {
			addEdge(rightOff + rightInd, i, 1, 1);
		}
	}

	for (int i = 0; i+1 < int(dleft.size()); i++) {
		addEdge(leftOff + i+1, leftOff + i, N, 0);
	}
	for (int i = 0; i+1 < int(dright.size()); i++) {
		addEdge(rightOff + i+1, rightOff + i, N, 0);
	}

	ll E = mf.maxflow(source, sink).second;

	cout << T << ' ' << E << '\n';
	return 0;
}