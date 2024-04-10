#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) cin >> a;

	const int V = int(2.5e6) + 10;
	vector<int> seen_1(V, -1);
	pair<int, int> good_pair(-1, -1);
	vector<pair<int, int>> seen_2(2*V, std::pair<int, int>{-1, -1});
	for (int i = 0; i < N; i++) {
		if (seen_1[A[i]] != -1) {
			if (good_pair.first != -1) {
				cout << "YES" << '\n';
				cout << good_pair.first+1 << ' ' << i+1 << ' ' << good_pair.second+1 << ' ' << seen_1[A[i]]+1 << '\n';
				exit(0);
			}
			good_pair = {i, seen_1[A[i]]};
			seen_1[A[i]] = -1;
		}
		for (int j = 0; j < i; j++) {
			int s = A[i]+A[j];
			if (seen_2[s].first == -1) {
				seen_2[s] = {j, i};
			} else {
				auto [x, y] = seen_2[s];
				if (x == i || x == j || y == i || y == j) {
					// keep going
				} else {
					cout << "YES" << '\n';
					cout << x+1 << ' ' << y+1 << ' ' << i+1 << ' ' << j+1 << '\n';
					exit(0);
				}
			}
		}
	}
	cout << "NO" << '\n';

	return 0;
}