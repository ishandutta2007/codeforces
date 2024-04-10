#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;

		auto ans = [&]() -> std::optional<std::vector<int>> {
			int tot = 0;
			for (auto a : A) tot ^= a;
			if (tot != 0) {
				return std::nullopt;
			}
			if (N & 1) {
				std::vector<int> resp; resp.reserve(N);
				for (int i = 0; i <= N-3; i += 2) {
					resp.push_back(i);
				}
				for (int i = N-5; i >= 0; i -= 2) {
					resp.push_back(i);
				}
				return resp;
			} else {
				int cur_tot = A[0];
				for (int md = 1; md < N; md += 2) {
					if (cur_tot == 0) {
						std::vector<int> resp; resp.reserve(N);
						for (int i = 0; i <= md-3; i += 2) {
							resp.push_back(i);
						}
						for (int i = md-5; i >= 0; i -= 2) {
							resp.push_back(i);
						}
						for (int i = md; i <= N-3; i += 2) {
							resp.push_back(i);
						}
						for (int i = N-5; i >= md; i -= 2) {
							resp.push_back(i);
						}
						return resp;
					}
					if (md + 2 < N) {
						cur_tot ^= A[md] ^ A[md+1];
					}
				}
				return std::nullopt;
			}
		}();

		if (ans) {
			cout << "YES" << '\n';
			cout << ans->size() << '\n';
			for (int z = 0; z < int(ans->size()); z++) {
				cout << (*ans)[z]+1 << " \n"[z+1==int(ans->size())];
			}
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}