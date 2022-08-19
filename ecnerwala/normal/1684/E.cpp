#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;

		std::vector<int> cnt(N+1);
		std::map<int, int> big_cnt;
		for (auto a : A) {
			big_cnt[a]++;

			if (a <= N) cnt[a]++;
		}

		std::vector<int> gaps(N+1);
		for (int i = 0; i < N; i++) {
			gaps[i+1] = gaps[i] + (cnt[i] == 0);
		}
		int mex = N; while (gaps[mex] > K) mex--;
		std::priority_queue<int, std::vector<int>, std::greater<int>> groups;
		for (auto [k, v] : big_cnt) {
			if (k > mex) {
				groups.push(v);
			}
		}
		int ops = K;
		while (!groups.empty() && groups.top() <= ops) {
			ops -= groups.top();
			groups.pop();
		}
		cout << groups.size() << '\n';
	}

	return 0;
}