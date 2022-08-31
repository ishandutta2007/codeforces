#include <bits/stdc++.h>

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
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<std::vector<std::pair<int, int>>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v, c; cin >> u >> v >> c; u--, v--;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}

	int K; cin >> K;
	std::vector<int> zones(N);
	{
		string s; cin >> s;
		for (int i = 0; i < N; i++) zones[i] = s[i] - 'A';
	}

	std::vector<int64_t> pass(K);
	for (auto& v : pass) cin >> v;
	std::vector<int64_t> fine(K);
	for (auto& v : fine) cin >> v;

	int T; cin >> T;

	std::vector<int64_t> depth(N);
	depth[0] = 0;

	std::vector<int> par(N);
	par[0] = 0;

	std::vector<std::array<std::pair<int, int>, 52>> mods(N);
	std::vector<int> mods_len(N);
	mods_len[0] = 0;
	auto do_insert = [&](int idx, std::pair<int, int> val) {
		int i = mods_len[idx]++;
		while (i > 0 && val < mods[idx][i-1]) {
			mods[idx][i] = mods[idx][i-1];
			i--;
		}
		mods[idx][i] = val;
	};

	std::vector<std::array<int64_t, 26>> base_cnt(N);
	base_cnt[0].fill(0);

	std::vector<int64_t> mods_msk(N);

	std::y_combinator([&](auto self, int cur, int prv) -> void {
		{
			std::pair<int, int> nmod(int(depth[cur] % T), -K-1);
			int idx = int(std::lower_bound(mods[cur].begin(), mods[cur].begin() + mods_len[cur], nmod) - mods[cur].begin());
			mods_msk[cur] = (int64_t(1) << idx);
		}
		for (auto [nxt, l] : adj[cur]) {
			if (nxt == prv) continue;
			depth[nxt] = depth[cur] + l;
			assert(zones[nxt] >= zones[cur]);
			if (cur == 0 || zones[nxt] == zones[cur]) {
				par[nxt] = par[cur];
				mods_len[nxt] = mods_len[cur];
				mods[nxt] = mods[cur];
				base_cnt[nxt] = base_cnt[cur];
			} else {
				par[nxt] = cur;

				// add depth[cur] % T
				mods_len[nxt] = mods_len[cur];
				mods[nxt] = mods[cur];
				do_insert(nxt, {int(depth[par[cur]] % T), ~zones[cur]});
				do_insert(nxt, {int(depth[cur] % T), zones[cur]});

				base_cnt[nxt] = base_cnt[cur];
				base_cnt[nxt][zones[cur]] += depth[cur] / T + 1;
				base_cnt[nxt][zones[cur]] -= depth[par[cur]] / T + 1;
			}
			self(nxt, cur);

			if (zones[nxt] == zones[cur]) {
				mods_msk[cur] |= mods_msk[nxt];
			}
		}
	})(0, -1);

	int Q; cin >> Q;

	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			char zone; int v; cin >> zone >> v;
			pass[zone-'A'] = v;
		} else if (op == 2) {
			char zone; int v; cin >> zone >> v;
			fine[zone-'A'] = v;
		} else if (op == 3) {
			int v; cin >> v; v--;
			auto cnt = base_cnt[v];
			int64_t cur_cost = 0;
			for (int k = 0; k < K; k++) {
				cur_cost += cnt[k] <= pass[k] / fine[k] ? cnt[k] * fine[k] : pass[k];
			}
			/*
			cerr << "query " << v << ' ' << mods_msk[v] << '\n';
			for (int i = 0; i < K; i++) { cerr << base_cnt[v][i] << ' '; } cerr << '\n';
			for (int i = 0; i < mods_len[v]; i++) {
				cerr << ' ' << mods[v][i].first << ' ' << mods[v][i].second << '\n';
			}
			*/
			int64_t ans = 1e18;
			for (int i = 0; i <= mods_len[v]; i++) {
				if (i) {
					auto [_, y] = mods[v][i-1];
					int k = (y < 0) ? ~y : y;
					cur_cost -= cnt[k] <= pass[k] / fine[k] ? cnt[k] * fine[k] : pass[k];
					if (y < 0) {
						cnt[k]++;
					} else {
						cnt[k]--;
					}
					assert(cnt[k] >= 0);
					cur_cost += cnt[k] <= pass[k] / fine[k] ? cnt[k] * fine[k] : pass[k];
				}
				if ((mods_msk[v] >> i) & 1) {
					ans = min(ans, cur_cost);
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}