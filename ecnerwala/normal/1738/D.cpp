#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> B(N);
		for (auto& b : B) { cin >> b; b--; }

		for (int i = 0; i < N; i++) assert(B[i] != i);

		int K = 0;
		while (K < N && B[K] > K) K++;

		std::vector<std::vector<int>> inds(N+2);
		for (int i = 0; i < N; i++) {
			inds[B[i]+1].push_back(i);
		}

		std::vector<int> A; A.reserve(N+2);
		int st = 0;
		A.push_back(-1);
		A.push_back(N);

		while (int(A.size()) < N+2) {
			for (int z = st; z < int(A.size()); z++) {
				if (inds[A[z]+1].empty()) continue;
				std::swap(A[z], A.back());
				break;
			}
			st = int(A.size());
			A.insert(A.end(), inds[A.back()+1].begin(), inds[A.back()+1].end());
		}

		cout << K << '\n';
		for (int i = 0; i < N; i++) {
			cout << A[i+2]+1 << " \n"[i+1==N];
		}
	}

	return 0;
}