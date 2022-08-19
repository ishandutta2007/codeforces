#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) { cin >> a; a--; }
		std::vector<int> B(N);
		for (auto& a : B) { cin >> a; a--; }

		std::vector<int> freq(N);
		for (auto a : A) freq[a]++;

		int root = int(std::max_element(freq.begin(), freq.end()) - freq.begin());
		std::vector<int> inDeg(N);
		std::vector<std::vector<int>> outEdges(N);
		for (int i = 0; i < N; i++) {
			if (A[i] == root || B[i] == root) continue;
			outEdges[A[i]].push_back(B[i]);
			inDeg[B[i]]++;
		}
		std::vector<int> q; q.reserve(N);
		for (int i = 0; i < N; i++) {
			if (inDeg[i] == 0) {
				q.push_back(i);
			}
		}
		for (int z = 0; z < int(q.size()); z++) {
			int cur = q[z];
			for (int nxt : outEdges[cur]) {
				if ((--inDeg[nxt]) == 0) {
					q.push_back(nxt);
				}
			}
		}
		cout << (int(q.size()) == N ? "AC" : "WA") << '\n';
	}

	return 0;
}