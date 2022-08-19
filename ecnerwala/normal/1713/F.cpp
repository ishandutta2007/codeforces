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
	std::vector<uint32_t> B(N);
	for (auto& b : B) cin >> b;

	int L = 0;
	while ((1 << L) < N) L++;

	B.resize(1 << L, 0);

	std::vector<uint32_t> A(1 << L, 0);

	// Compute A[st..st+len] given B[st..st+len], then zero-pad A and fix B[st..st+(1<<D)] (considering only bottom (1 << D) bits)
	std::y_combinator([&](auto self, int st, int len, int D) -> void {
		assert(0 < len && len <= (1 << D));
		if (D == 0) {
			A[st] = B[st];
			return;
		}
		if (len <= (1 << (D-1))) {
			self(st, len, D-1);
			for (int i = 0; i < (1 << (D-1)); i++) {
				B[st+(1<<(D-1))+i] = B[st+i];
			}
			return;
		}
		for (int i = 0; i < len - (1 << (D-1)); i++) {
			B[st+(1<<(D-1))+i] ^= B[st+i];
		}
		self(st + (1 << (D-1)), len - (1 << (D-1)), D-1);
		for (int i = 0; i < (1 << (D-1)); i++) {
			B[st+i] ^= B[st+(1<<(D-1))+i];
		}
		self(st, 1 << (D-1), D-1);
		for (int i = 0; i < (1 << (D-1)); i++) {
			B[st+i] ^= B[st+(1<<(D-1))+i];
			B[st+(1<<(D-1))+i] ^= B[st+i];
		}
	})(0, N, L);

	A.resize(N);
	std::reverse(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		cout << A[i] << " \n"[i+1==N];
	}

	return 0;
}