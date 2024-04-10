#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) { cin >> a; a--; }

		bool is_good = true;
		for (int i = 0; i < N; i++) if ((A[i] ^ i) & 1) is_good = false;
		if (!is_good) {
			cout << -1 << '\n';
			continue;
		} else {
			std::vector<int> ops; ops.reserve(5*N/2);

			auto find_val = [&](int v) -> int {
				return int(std::find(A.begin(), A.end(), v) - A.begin());
			};
			auto do_op = [&](int p) -> void {
				assert(p & 1);
				ops.push_back(p);
				std::reverse(A.begin(), A.begin() + p);
			};


			for (int L = N; L > 1; L -= 2) {
				int pN = find_val(L-1);
				do_op(pN+1);
				int pN1 = find_val(L-2);
				do_op(pN1);
				do_op(pN1+2);
				do_op(3);
				do_op(L);
			}
			for (int i = 0; i < N; i++) {
				assert(A[i] == i);
			}

			cout << ops.size() << '\n';
			for (int z = 0; z < int(ops.size()); z++) {
				cout << ops[z] << " \n"[z+1==int(ops.size())];
			}
		}
	}

	return 0;
}