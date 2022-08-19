#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int L, R; cin >> L >> R;
	int N = 23;
	vector<std::tuple<int, int, int>> edges;

	// link some subset to 22 with some weights
	if (L == 1) {
		edges.push_back({0, 22, 1});
		L++;
	}

	for (int j = 1; j <= 20; j++) {
		for (int i = 0; i < j; i++) {
			edges.push_back({i, j, 1 << (j-1)});
		}
		if ((R-L+1) >= (1 << (j-1))) {
			edges.push_back({j, 22, L - (1 << (j-1))});
			L += (1 << (j-1));
		}
	}
	// R - L 
	if (R >= L) {
		for (int j = 20; j >= 1; j--) {
			if (R - L + 1 >= (1 << (j-1))) {
				edges.push_back({j, 21, L - 1 - (1 << (j-1))});
				L += (1 << (j-1));
			}
		}
		if (R >= L) {
			edges.push_back({0, 21, L-1});
		}
		edges.push_back({21, 22, 1});
	}

	cout << "YES" << '\n';
	cout << N << ' ' << edges.size() << '\n';
	for (auto [u, v, w] : edges) {
		cout << u+1 << ' ' << v+1 << ' ' << w << '\n';
	}

	return 0;
}