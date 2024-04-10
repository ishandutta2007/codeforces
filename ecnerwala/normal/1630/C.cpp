#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int> A(N);
	for (auto& a : A) { cin >> a; a--; }

	std::vector<int> firstIdx(N, -1);
	std::vector<int> lastIdx(N, -1);
	for (int i = 0; i < N; i++) {
		if (firstIdx[A[i]] == -1) firstIdx[A[i]] = i;
		lastIdx[A[i]] = i;
	}

	std::vector<std::array<int, 2>> locs; locs.reserve(N);
	for (int i = 0; i < N; i++) {
		if (lastIdx[A[i]] != i) continue;
		int j = firstIdx[A[i]];
		assert(j != -1 && j <= i);
		if (j == i) continue;
		assert(j < i);
		while (!locs.empty() && locs.back()[0] >= j) {
			locs.pop_back();
		}
		locs.push_back({j, i});
	}

	int ans = 0;
	for (int i = 0, j = 0; i < int(locs.size()); i = j) {
		int last = i;
		int num = 1;
		j = i+1;
		while (j < int(locs.size()) && locs[j][0] < locs[j-1][1]) {
			if (locs[j][0] < locs[last][1]) {
				// do nothing
			} else {
				last = j-1;
				num++;
			}
			j++;
		}
		if (j - i > 1) num++;
		ans += locs[j-1][1] - locs[i][0] - 1;
		ans -= num - 1;
	}
	cout << ans << '\n';

	return 0;
}