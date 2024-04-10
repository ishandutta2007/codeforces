#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		std::vector<int> A(M); for (auto& a : A) { cin >> a; a--; }
		std::sort(A.begin(), A.end());
		std::vector<int> gaps(M);
		for (int i = 0; i+1 < M; i++) {
			gaps[i] = A[i+1] - A[i] - 1;
		}
		gaps[M-1] = A[0] + N - A[M-1] - 1;
		std::sort(gaps.begin(), gaps.end(), std::greater<int>());
		int saved = 0;
		for (int i = 0; i < M; i++) {
			if (gaps[i] >= 4*i+1 + 2) {
				saved += gaps[i] - (4*i+1);
			} else if (gaps[i] >= 4 * i + 1) {
				saved ++;
			}
		}
		cout << N - saved << '\n';
	}

	return 0;
}