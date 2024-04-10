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
	vector<uint32_t> A(N); for (auto& a : A) cin >> a;
	sort(A.begin(), A.end());
	int ans = std::y_combinator([&](auto self, int k, int l, int r) -> int {
		assert(l <= r);
		if (r - l <= 2) return 0;
		assert(k >= 0);
		int m = l;
		while (m < r && !(A[m] & (1u << k))) m++;
		if (m == l || m == r) {
			return self(k-1, l, r);
		}
		assert(l < m && m < r);
		return min((m-l-1) + self(k-1, m, r), self(k-1, l, m) + (r-m-1));
	})(30, 0, N);
	cout << ans << '\n';

	return 0;
}