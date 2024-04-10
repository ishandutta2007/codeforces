#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		std::vector<int> B(N);
		for (auto& b : B) cin >> b;

		std::vector<std::array<int, 2>> segs(M);
		for (auto& [x, y] : segs) {
			cin >> x >> y; x--;
		}

		std::vector<std::vector<std::array<int, 2>>> endpts(N+1);
		for (int e = 0; e < M; e++) {
			for (int z = 0; z < 2; z++) {
				endpts[segs[e][z]].push_back({e, z});
			}
		}

		std::set<int> bads;
		std::vector<int> good_q; good_q.reserve(N+1);
		{
			int64_t v = 0;
			for (int i = 0; i <= N; i++) {
				if (i) {
					v += A[i-1];
					v -= B[i-1];
				}
				if (v) {
					bads.insert(i);
				} else {
					good_q.push_back(i);
				}
			}
		}

		for (int iter = 0; iter < int(good_q.size()); iter++) {
			int cur = good_q[iter];
			for (auto [e, z] : endpts[cur]) {
				segs[e][z] = ~segs[e][z];
				if (segs[e][!z] < 0) {
					// both sides are good
					int l = ~segs[e][0], r = ~segs[e][1];
					auto it = bads.lower_bound(l);
					while (it != bads.end() && *it <= r) {
						good_q.push_back(*it);
						it = bads.erase(it);
					}
				}
			}
		}
		cout << (bads.empty() ? "YES" : "NO") << '\n';
	}

	return 0;
}