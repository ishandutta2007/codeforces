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

std::vector<std::array<int, 2>> solve(int N) {
	std::vector<std::array<int, 2>> ops;
	ops.reserve(20 * N);

	std::map<int, int> cnt;
	std::y_combinator([&](auto self, int hi, int mult) -> void {
		while (!(hi & (hi-1))) {
			if (hi == 0) return;
			cnt[mult*hi]++;
			hi--;
		}
		assert(hi >= 3);
		int next_pow_2 = 1 << (32 - __builtin_clz(hi));
		cnt[mult * (next_pow_2 >> 1)]++;
		cnt[mult * next_pow_2] += hi - (next_pow_2 >> 1);
		for (int i = (next_pow_2 >> 1) + 1; i <= hi; i++) {
			ops.push_back({mult * (next_pow_2 - i), mult * i});
		}
		self(hi - (next_pow_2 >> 1), mult * 2);
		self(next_pow_2 - hi - 1, mult);
	})(N, 1);

	while (cnt.size() > 1) {
		auto it = cnt.begin();
		int v = it->first;
		int c = it->second;
		cnt.erase(it);
		assert(c > 0);
		if (c == 1) {
			assert(cnt.begin()->first == v * 2);
			ops.push_back({v, 2*v});
			ops.push_back({v, 3*v});
			cnt[4*v]++;
		} else {
			cnt[2*v] += c;
			for (; c != 0 && c != 3; c -= 2) {
				ops.push_back({v, v});
				ops.push_back({0, 2*v});
			}
			if (c == 3) {
				ops.push_back({v, v});
				ops.push_back({0, v});
				ops.push_back({v, v});
				ops.push_back({0, 2*v});
			}
		}
	}

	assert(int(ops.size()) <= 20 * N);
	return ops;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	/*
	for (int N = 3; N <= 100; N++) {
		solve(N);
	}
	for (int N = int(5e4) - 100; N <= int(5e4); N++) {
		solve(N);
	}
	*/

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		if (N == 2) {
			cout << -1 << '\n';
		} else {
			auto ans = solve(N);
			cout << ans.size() << '\n';
			for (auto a : ans) {
				cout << a[0] << ' ' << a[1] << '\n';
			}
		}
	}

	return 0;
}