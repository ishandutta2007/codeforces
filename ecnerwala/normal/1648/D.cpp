#include <bits/stdc++.h>

template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

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

	int N, Q; cin >> N >> Q;

	std::vector<int64_t> top(N);
	for (auto& v : top) cin >> v;
	std::vector<int64_t> mid(N);
	for (auto& v : mid) cin >> v;
	std::vector<int64_t> bot(N);
	for (auto& v : bot) cin >> v;

	int64_t v_base = std::accumulate(mid.begin(), mid.end(), top[0] + bot[N-1]);
	std::vector<int64_t> v_top(N);
	for (int i = 1; i < N; i++) {
		v_top[i] = v_top[i-1] + top[i] - mid[i-1];
	}
	std::vector<int64_t> v_bot(N);
	for (int i = N-2; i >= 0; i--) {
		v_bot[i] = v_bot[i+1] + bot[i] - mid[i+1];
	}

	const int64_t INF = 1e18;

	std::vector<std::pair<std::array<int, 2>, int64_t>> all_offers(Q);
	for (auto& q : all_offers) {
		int l, r; cin >> l >> r >> q.second;
		l--, r--;
		q.first = {std::max(0, 2*l-1), std::min(2*N-1, 2*r+2)};
		q.second *= -1;
	}

	std::vector<int64_t> dp(2*N, -INF);
	for (int i = 0; i < N; i++) dp[2*i+0] = v_top[i];

	std::y_combinator([&](auto self, int lo, int hi, std::vector<std::pair<std::array<int, 2>, int64_t>> offers) -> void {
		assert(lo < hi);
		for (auto [x, v] : offers) {
			auto [l, r] = x;
			assert(l < hi && lo < r);
		}
		if (hi - lo == 1) {
			for (auto [x, v] : offers) {
				auto [l, r] = x;
				assert(l <= lo && hi <= r);
				setmax(dp[hi], dp[lo] + v);
			}
			return;
		} else {
			int md = lo + (hi - lo) / 2;

			{
				int64_t best_all = -INF;
				std::vector<std::pair<std::array<int, 2>, int64_t>> l_offers;
				l_offers.reserve(offers.size());
				for (auto [x, v] : offers) {
					auto [l, r] = x;
					if (l <= lo && r >= md) {
						setmax(best_all, v);
					} else if (l < md) {
						l_offers.emplace_back(x, v);
					}
				}
				l_offers.push_back({{lo, md}, best_all});
				self(lo, md, std::move(l_offers));
			}

			std::vector<int64_t> suff_max(md - lo + 1);
			for (int i = lo; i <= md; i++) {
				suff_max[i - lo] = dp[i];
			}
			for (int i = int(suff_max.size()) - 1; i > 0; i--) setmax(suff_max[i-1], suff_max[i]);
			std::vector<int64_t> to_add(hi - md + 1, -INF);

			for (auto [x, v] : offers) {
				auto [l, r] = x;
				l = std::max(l, lo);
				r = std::min(r, hi);
				if (l <= md && md <= r) {
					setmax(to_add[r - md], suff_max[l - lo] + v);
				}
			}
			for (int i = int(to_add.size()) - 1; i > 0; i--) setmax(to_add[i-1], to_add[i]);
			for (int i = md; i <= hi; i++) {
				setmax(dp[i], to_add[i - md]);
			}

			{
				int64_t best_all = -INF;
				std::vector<std::pair<std::array<int, 2>, int64_t>> r_offers;
				r_offers.reserve(offers.size());
				for (auto [x, v] : offers) {
					auto [l, r] = x;
					if (l <= md && hi <= r) {
						setmax(best_all, v);
					} else if (md < r) {
						r_offers.emplace_back(x, v);
					}
				}
				r_offers.push_back({{md, hi}, best_all});
				self(md, hi, std::move(r_offers));
			}
		}
	})(0, 2*N-1, std::move(all_offers));

	int64_t ans = -INF;
	for (int i = 0; i < N; i++) {
		ans = std::max(ans, dp[2*i+1] + v_bot[i]);
	}

	ans += v_base;
	cout << ans << '\n';

	return 0;
}