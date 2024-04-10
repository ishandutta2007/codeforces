#include<bits/stdc++.h>

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

using i64 = int64_t;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N, M; cin >> N >> M;

	vector<vector<pair<int, i64>>> ch(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; i64 d; cin >> u >> v >> d; u--, v--;
		ch[u].emplace_back(v, d);
		ch[v].emplace_back(u, d);
	}

	vector<pair<int, i64>> trains(M);
	for (auto& it : trains) {
		cin >> it.first >> it.second; it.first--;
	}

	vector<int> par(N, -1);
	vector<i64> depth(N, 0);
	vector<int> init_state(N);
	{
		vector<int> q; q.reserve(N);
		par[0] = -1;
		depth[0] = 0;
		q.push_back(0);
		for (int z = 0; z < int(q.size()); z++) {
			int cur = q[z];
			if (par[cur] != -1) {
				auto it = ch[cur].begin();
				while (it->first != par[cur]) ++it;
				ch[cur].erase(it);
			}
			init_state[cur] = ch[cur].empty() ? -1 : ch[cur].back().first;
			for (auto [nxt, d] : ch[cur]) {
				par[nxt] = cur;
				depth[nxt] = depth[cur] + d;
				q.push_back(nxt);
			}
		}
	}

	vector<pair<i64, i64>> swap_times;
	vector<set<i64>> locs(N);

	vector<vector<i64>> loc_trains(N);
	for (auto [s, t] : trains) {
		loc_trains[s].push_back(t);
	}

	std::y_combinator([&](auto self, int cur) -> void {
		for (auto [nxt, d] : ch[cur]) {
			self(nxt);
			if (nxt == init_state[cur]) {
				locs[nxt].insert(-depth[cur]);
			}
			if (locs[nxt].size() > locs[cur].size()) {
				locs[cur].swap(locs[nxt]);
			}
		}

		int small_sz = 0;
		for (auto [nxt, d] : ch[cur]) {
			small_sz += int(locs[nxt].size());
		}
		vector<pair<i64, int>> smalls; smalls.reserve(small_sz);
		for (auto [nxt, d] : ch[cur]) {
			for (i64 t : locs[nxt]) {
				smalls.emplace_back(t, nxt);
			}
		}
		assert(int(smalls.size()) == small_sz);
		sort(smalls.begin(), smalls.end());

		for (int z = 0; z < small_sz; z++) {
			auto [t, nxt] = smalls[z];
			auto nit = locs[cur].lower_bound(t);
			if (z+1 < small_sz && (nit == locs[cur].end() || smalls[z+1].first <= *nit)) {
				if (smalls[z+1].second != nxt) {
					swap_times.emplace_back(t + depth[cur], smalls[z+1].first + depth[cur]);
				}
			} else if (nit != locs[cur].end()) {
				swap_times.emplace_back(t + depth[cur], *nit + depth[cur]);
			}
			auto pit = nit;
			if (pit != locs[cur].begin()) {
				--pit;
				if (z == 0 || smalls[z-1].first <= *pit) {
					swap_times.emplace_back(*pit + depth[cur], t + depth[cur]);
				}
			}
		}

		for (auto [t, nxt] : smalls) {
			locs[cur].insert(t);
		}
		locs[cur].insert(loc_trains[cur].begin(), loc_trains[cur].end());
		locs[cur].erase(-depth[cur]);
	})(0);

	sort(swap_times.begin(), swap_times.end());
	//for (auto it : swap_times) { cerr << it.first << ' ' << it.second << '\n'; }

	i64 death_time = [&]() -> i64 {
		i64 cur_t = 0;
		priority_queue<i64, vector<i64>, greater<i64>> pq;
		for (auto it : swap_times) {
			assert(cur_t <= it.first);
			while (!pq.empty() && cur_t < it.first) {
				cur_t++;
				if (pq.top() < cur_t) {
					return pq.top();
				}
				pq.pop();
			}
			assert(cur_t <= it.first);
			cur_t = it.first;
			pq.push(it.second);
		}
		while (!pq.empty()) {
			cur_t++;
			if (pq.top() < cur_t) {
				return pq.top();
			}
			pq.pop();
		}
		return -1;
	}();

	int num_swaps = 0;
	for (auto it : swap_times) {
		num_swaps += (death_time == -1 || it.second < death_time);
	}
	cout << death_time << ' ' << num_swaps << '\n';

	return 0;
}