#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) { cin >> a; a--; }
		std::vector<std::vector<int>> idx(N);
		for (int i = 0; i < N; i++) {
			idx[A[i]].push_back(i);
		}
		std::vector<int> B(N);
		std::vector<int> cyc; cyc.reserve(N);
		std::vector<std::vector<int>> nidx; nidx.reserve(N);
		while (!idx.empty()) {
			for (auto& v : idx) {
				if (v.empty()) continue;
				cyc.push_back(v.back());
				v.pop_back();
				if (v.empty()) continue;
				nidx.emplace_back(std::move(v));
			}
			for (int i = 0; i < int(cyc.size()); i++) {
				B[cyc[i]] = A[cyc[(i+1)%int(cyc.size())]];
			}
			cyc.clear();
			std::swap(idx, nidx);
			nidx.clear();
		}
		for (int i = 0; i < N; i++) {
			cout << B[i]+1 << " \n"[i+1==N];
		}
	}

	return 0;
}