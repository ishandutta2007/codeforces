#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) { cin >> a; a--; }

		vector<bool> used(N);
		vector<int> B(N, -1);
		int K = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] == i) continue;
			if (used[A[i]]) continue;
			used[A[i]] = true;
			B[i] = A[i];
			K++;
		}

		vector<int> L; L.reserve(N-K);
		vector<int> R; R.reserve(N-K);
		for (int i = 0; i < N; i++) {
			if (B[i] == -1 && !used[i]) {
				L.push_back(i);
				R.push_back(i);
			}
		}
		for (int i = 0; i < N; i++) {
			if (B[i] == -1 && used[i]) {
				L.push_back(i);
			}
		}
		for (int i = 0; i < N; i++) {
			if (B[i] != -1 && !used[i]) {
				R.push_back(i);
			}
		}
		assert(int(L.size()) == N-K);
		assert(int(R.size()) == N-K);
		for (int i = 0; i < N-K; i++) {
			B[L[i]] = R[i+1==N-K ? 0 : i+1];
		}
		if (N-K == 1 && L[0] == R[0]) {
			int v = L[0];
			assert(B[v] == v);
			int u = 0;
			while (u == v || (used[A[v]] && B[u] != A[v])) u++;
			if (B[u] == A[v]) {
			} else {
				K--;
			}
			std::swap(B[u], B[v]);
		}

		cout << K << '\n';
		for (int i = 0; i < N; i++) {
			cout << B[i]+1 << " \n"[i+1==N];
		}
	}

	return 0;
}