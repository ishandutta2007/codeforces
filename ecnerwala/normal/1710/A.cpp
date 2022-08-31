#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		int K; cin >> K;
		std::vector<int> A(K); for (auto& a : A) cin >> a;
		bool good = false;
		for (int z = 0; z < 2; z++, std::swap(N, M)) {
			bool has_three = false;
			int64_t len = 0;
			for (auto a : A) {
				int cnt = a / N;
				if (cnt >= 2) len += cnt;
				if (cnt >= 3) has_three = true;
			}
			if (len >= M && ((M & 1) ? has_three : true)) {
				good = true;
			}
		}
		cout << (good ? "Yes" : "No") << '\n';
	}

	return 0;
}