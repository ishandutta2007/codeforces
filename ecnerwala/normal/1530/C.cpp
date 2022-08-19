#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A; A.reserve(N+1); A.resize(N); for (auto& a : A) cin >> a;
		vector<int> B; B.reserve(N+1); B.resize(N); for (auto& b : B) cin >> b;
		sort(A.begin(), A.end(), std::greater());
		A.push_back(0);
		for (int i = 0, v = 0; i <= N; i++) {
			std::swap(A[i], v);
			v += A[i];
		}
		sort(B.begin(), B.end(), std::greater());
		B.push_back(0);
		for (int i = 0, v = 0; i <= N; i++) {
			std::swap(B[i], v);
			v += B[i];
		}
		for (int k = N; true; k++) {
			int cnt = k - (k / 4);
			int64_t va = (k-N) * 100 + A[max(0, cnt - (k-N))];
			int64_t vb = B[min(cnt, N)];
			if (va >= vb) {
				cout << k - N << '\n';
				break;
			}
		}
	}

	return 0;
}