#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) { cin >> a; a--; }
	vector<array<int, 2>> ans; ans.reserve(N+1);

	auto do_swap = [&](int x, int y) {
		ans.push_back({x, y});
		A[x] = ~A[x];
		A[y] = ~A[y];
		std::swap(A[x], A[y]);
	};

	vector<int> cycle_starts; cycle_starts.reserve(N);
	vector<bool> vis(N, false);
	for (int i = 0; i < N; i++) {
		if (A[i] == i) continue;
		if (vis[i]) continue;
		cycle_starts.push_back(i);
		for (int cur = i; !vis[cur]; cur = A[cur]) {
			vis[cur] = true;
		}
	}

	while (int(cycle_starts.size()) >= 2) {
		int X = cycle_starts.back(); cycle_starts.pop_back();
		int Y = cycle_starts.back(); cycle_starts.pop_back();
		do_swap(X, Y);
		while (~A[X] != Y) {
			do_swap(X, ~A[X]);
		}
		while (~A[Y] != X) {
			do_swap(Y, ~A[Y]);
		}
		do_swap(X, Y);
	}

	if (!cycle_starts.empty()) {
		int X = cycle_starts.back();
		if (A[A[X]] == X) {
			// we need a 3rd node
			int Y = 0;
			while (Y == X || Y == A[X]) Y++;
			do_swap(X, Y);
			while (~A[X] != Y) {
				do_swap(X, ~A[X]);
			}
			while (~A[Y] != X) {
				do_swap(Y, ~A[Y]);
			}
			do_swap(X, Y);
		} else {
			int Y = A[X];
			int Z = A[Y];
			do_swap(Y, Z);
			do_swap(X, Z);
			while (~A[Y] != Z) {
				do_swap(Y, ~A[Y]);
			}
			while (~A[Z] != Y) {
				do_swap(Z, ~A[Z]);
			}
			do_swap(Y, Z);
		}
	}

	for (int i = 0; i < N; i++) {
		assert(A[i] == i);
	}

	cout << ans.size() << '\n';
	for (auto [x, y] : ans) {
		cout << x+1 << ' ' << y+1 << '\n';
	}

	return 0;
}