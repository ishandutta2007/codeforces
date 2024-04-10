#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, K; cin >> N >> K; K--;

	auto query = [&](int i, int j) -> std::pair<int, int> {
		cout << "and" << ' ' << i+1 << ' ' << j+1 << '\n' << flush;
		int lo; cin >> lo;
		cout << "or" << ' ' << i+1 << ' ' << j+1 << '\n' << flush;
		int hi; cin >> hi;
		return {lo, hi};
	};

	assert(N >= 3);
	std::vector<int> A(N);
	auto q01 = query(0, 1);
	auto q20 = query(0, 2);
	auto q12 = query(1, 2);

	A[0] = (q01.second & q20.second) & (~q12.second | q01.first | q20.first);
	A[1] = (q12.second & q01.second) & (~q20.second | q12.first | q01.first);
	A[2] = (q20.second & q12.second) & (~q01.second | q20.first | q12.first);
	for (int i = 3; i < N; i++) {
		auto v = query(0, i);
		A[i] = A[0] ^ v.first ^ v.second;
	}
	std::nth_element(A.begin(), A.begin()+K, A.end());
	std::cout << "finish " << A[K] << '\n' << flush;

	return 0;
}