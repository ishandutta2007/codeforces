#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		std::vector<int> cnt(N+2);
		for (auto a : A) cnt[a]++;
		int mex = N+2;
		for (int i = 0; i < int(cnt.size()); i++) {
			if (!cnt[i]) {
				mex = i;
				break;
			}
		}

		std::vector<int> B; B.reserve(N);

		std::vector<int> cur_cnt(N+2);
		for (int st = 0; st < N; ) {
			int cur_mex = mex;
			B.push_back(cur_mex);
			int cur_has = 0;
			do {
				assert(A[st] != cur_mex);

				cnt[A[st]]--;
				if (cnt[A[st]] == 0) mex = std::min(mex, A[st]);

				if (A[st] < cur_mex && !cur_cnt[A[st]]) {
					cur_cnt[A[st]] = true;
					cur_has++;
				}
				st++;
			} while (cur_has < cur_mex);
			std::fill(cur_cnt.begin(), cur_cnt.begin() + cur_mex, 0);
		}
		cout << B.size() << '\n';
		for (int i = 0; i < int(B.size()); i++) {
			cout << B[i] << " \n"[i+1==int(B.size())];
		}
	}

	return 0;
}