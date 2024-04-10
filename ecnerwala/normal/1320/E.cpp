#include<bits/stdc++.h>
using namespace std;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> depth(N);

	vector<int> st(N);
	vector<int> en(N);
	vector<pair<int, int>> inOrder; inOrder.reserve(2*N-1);

	std::y_combinator([&] (auto self, int cur, int prv) -> void {
		depth[cur] = (prv == -1 ? 0 : depth[prv]) + 1;
		st[cur] = int(inOrder.size());
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			inOrder.emplace_back(depth[cur], cur);
			self(nxt, cur);
		}
		en[cur] = int(inOrder.size());
		inOrder.emplace_back(depth[cur], cur);
	})(0, -1);

	assert(int(inOrder.size()) == 2 * N - 1);

	const int S = 1 << 19;
	vector<pair<int, int>> seg(2*S);
	for (int i = 0; i < int(inOrder.size()); i++) {
		seg[S+i] = inOrder[i];
	}
	for (int i = S-1; i; i--) seg[i] = min(seg[2*i+0], seg[2*i+1]);


	int Q; cin >> Q;
	while (Q--) {
		//cerr << "starting query" << '\n';

		int K, M; cin >> K >> M;
		vector<pair<int, int>> viruses(K);
		for (auto& it : viruses) { cin >> it.first >> it.second; it.first--; }
		vector<int> queries(M);
		for (auto& it : queries) { cin >> it; it--; }

		vector<int> allCities; allCities.reserve((K+M)*2);
		for (auto it : viruses) allCities.push_back(st[it.first]);
		for (auto it : queries) allCities.push_back(st[it]);
		sort(allCities.begin(), allCities.end());
		allCities.resize(unique(allCities.begin(), allCities.end()) - allCities.begin());

		//cerr << "Grabbed all cities" << '\n';

		for (int i = int(allCities.size())-1; i > 0; i--) {
			int r = allCities[i];
			int l = allCities[i-1];

			assert(l < r);

			pair<int, int> lowest = inOrder[l];
			for (int a = S+l, b = S+r+1; a < b; a /= 2, b /= 2) {
				if (a & 1) lowest = min(lowest, seg[a++]);
				if (b & 1) lowest = min(lowest, seg[--b]);
			}

			int lca = st[lowest.second];
			if (lca == l || lca == r) {
				// don't need to do anything
			} else {
				allCities.push_back(lca);
			}
		}

		//cerr << "Grabbed really all cities" << '\n';

		sort(allCities.begin(), allCities.end());
		allCities.resize(unique(allCities.begin(), allCities.end()) - allCities.begin());
		//for (auto& it : allCities) { cerr << inOrder[it].second << ' '; } cerr << '\n';

		int C = int(allCities.size());
		vector<vector<pair<int, int>>> curAdj(C);

		{
			auto compressId = [&allCities, &st](int v) -> int {
				auto it = lower_bound(allCities.begin(), allCities.end(), st[v]);
				assert(it != allCities.end() && *it == st[v]);
				return int(it - allCities.begin());
			};
			for (auto& it : viruses) { it.first = compressId(it.first); }
			for (auto& it : queries) { it = compressId(it); }
		}

		stack<pair<int, pair<int, int>>> stk;
		for (int i = 0; i < C; i++) {
			int curSt = allCities[i];
			int curNode = inOrder[curSt].second;
			int curEn = en[curNode];
			int curDepth = depth[curNode];

			if (i) {
				assert(!stk.empty());
				while (stk.top().second.first < curSt) {
					stk.pop();
					assert(!stk.empty());
				}
				int p = stk.top().first;
				int d = curDepth - stk.top().second.second;
				curAdj[i].emplace_back(p, d);
				curAdj[p].emplace_back(i, d);
			} else {
				assert(stk.empty());
			}

			stk.push({i, {curEn, curDepth}});
		}

		using distVal = pair<pair<int, int>, pair<int, int>>;
		vector<distVal> dist(C, {{N+10, -1}, {0, 1}});
		priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
		for (int i = 0; i < int(viruses.size()); i++) {
			int loc = viruses[i].first;
			int s = viruses[i].second;
			dist[loc] = {{0, i}, {0, s}};
			pq.emplace(dist[loc].first, loc);
		}

		while (!pq.empty()) {
			auto pqD = pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			assert(pqD >= dist[cur].first);
			if (pqD != dist[cur].first) continue;

			for (auto e : curAdj[cur]) {
				int nxt = e.first;
				distVal nd = dist[cur];
				nd.second.first += e.second;
				int whole = (nd.second.first + nd.second.second - 1) / nd.second.second;
				nd.first.first += whole;
				nd.second.first -= nd.second.second * whole;

				if (nd < dist[nxt]) {
					dist[nxt] = nd;
					pq.emplace(dist[nxt].first, nxt);
				}
			}
		}

		for (int i = 0; i < int(queries.size()); i++) {
			cout << dist[queries[i]].first.second+1 << " \n"[i+1 == int(queries.size())];
		}
	}

	return 0;
}