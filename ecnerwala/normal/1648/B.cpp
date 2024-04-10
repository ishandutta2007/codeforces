#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, C; cin >> N >> C;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		std::sort(A.begin(), A.end());
		A.resize(std::unique(A.begin(), A.end()) - A.begin());
		N = int(A.size());

		std::vector<int> cnt(C+1);
		for (auto a : A) cnt[a]++;
		for (int c = 1; c <= C; c++) cnt[c] += cnt[c-1];

		std::vector<int> num_cover(C+2);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (int64_t(A[i]) * int64_t(A[j]) > C) break;
				num_cover[A[i] * A[j]]++;
				num_cover[std::min(C+1, A[i] * (A[j] + 1))]--;
			}
		}
		for (int c = 1; c <= C+1; c++) num_cover[c] += num_cover[c-1];
		bool is_good = true;
		for (int i = 0; i < N; i++) {
			if (num_cover[A[i]] < i+1) {
				is_good = false;
				break;
			}
		}
		cout << (is_good ? "Yes" : "No") << '\n';
	}

	return 0;
}