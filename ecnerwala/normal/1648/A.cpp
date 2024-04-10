#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	const int V = int(1e5) + 10;
	std::vector<std::vector<int>> vals(2*V);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int c; cin >> c;
			vals[2*c+0].push_back(i);
			vals[2*c+1].push_back(j);
		}
	}

	int64_t ans = 0;
	for (auto& v : vals) {
		std::sort(v.begin(), v.end());
		for (int i = 0; i < int(v.size()); i++) {
			ans += v[i] * int64_t(2 * i - int(v.size()) + 1);
		}
	}
	cout << ans << '\n';

	return 0;
}