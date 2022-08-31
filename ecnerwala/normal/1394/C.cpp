#include<bits/stdc++.h>

template <typename T> inline void setmax(T& a, const T& b) { if (b > a) a = b; }
template <typename T> inline void setmin(T& a, const T& b) { if (b < a) a = b; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<array<int, 2>> A(N);
	for (auto& a : A) {
		string s; cin >> s;
		a[0] = a[1] = 0;
		for (char c : s) {
			a[c == 'N']++;
		}
	}

	const int INF = 1e9;
	auto can_make = [&](int d) -> std::optional<array<int, 2>> {
		for (int round = 0; round < 2; round++) {
			int min_coord[2] = {0,0};
			min_coord[round] = 1;
			int max_coord[2] = {INF, INF};
			int max_diag[2] = {INF, INF};
			for (const auto& a : A) {
				for (int z = 0; z < 2; z++) {
					setmax(min_coord[z], a[z] - d);
					setmin(max_coord[z], a[z] + d);
					setmin(max_diag[z], a[z] - a[!z] + d);
				}
			}
			if (min_coord[0] > max_coord[0]) continue;
			if (min_coord[1] > max_coord[1]) continue;

			setmin(max_diag[0], max_coord[0] - min_coord[1]);
			setmin(max_diag[1], max_coord[1] - min_coord[0]);
			if (max_diag[0] + max_diag[1] < 0) continue;

			// otherwise we have an answer
			if (min_coord[0] - min_coord[1] > max_diag[0]) {
				return {{min_coord[0], min_coord[0] - max_diag[0]}};
			} else {
				return {{max_diag[0] + min_coord[1], min_coord[1]}};
			}
		}
		return nullopt;
	};

	int mi = -1;
	int ma = INF;
	while (ma - mi > 1) {
		int md = mi + (ma - mi) / 2;
		if (can_make(md)) ma = md;
		else mi = md;
	}

	cout << ma << '\n';
	auto ans = *can_make(ma);
	cout << string(ans[0], 'B') << string(ans[1], 'N') << '\n';

	return 0;
}