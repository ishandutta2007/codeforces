#include <bits/stdc++.h>

std::pair<std::vector<int>, std::vector<std::pair<int, int>>> solve(std::string S, int K) {
	using namespace std;
	int N = int(S.size());
	vector<int> V; V.reserve(N+1);
	V.push_back(0);
	for (char c : S) {
		if (c == '0') V.back()++;
		else if (c == '1') V.push_back(0);
		else assert(false);
	}
	vector<pair<int, int>> ops; ops.reserve(2*N);

	if (int(V.size()) > N) return {V, ops};
	if (K == 0) return {V, ops};

	auto do_op = [&](int x, int y, int nx, int ny) {
		assert(K >= 1);

		assert(x != -1 || y != -1);
		if (x == -1) {
			x = y - K;
		} else if (y == -1) {
			y = x + K;
		}
		assert(y - x == K);
		assert(0 <= x && x < y && y < N);

		int oldsum = V[x] + V[y];
		assert(oldsum >= 0);
		assert(nx != -1 || ny != -1);
		if (nx == -1) {
			nx = oldsum - ny;
		} else if (ny == -1) {
			ny = oldsum - nx;
		}
		assert(nx + ny == oldsum);
		assert(nx >= 0 && ny >= 0);
		int ax, bx, ay, by;
		if (nx >= V[x]) {
			ax = V[x];
			bx = 0;
			ay = nx - V[x];
			by = ny;
		} else {
			assert(ny >= V[y]);
			ax = nx;
			bx = ny - V[y];
			ay = 0;
			by = V[y];
		}
		assert(ax >= 0 && bx >= 0 && ay >= 0 && by >= 0);
		assert(ax + bx == V[x]);
		assert(ay + by == V[y]);
		assert(ax + ay == nx);
		assert(bx + by == ny);

		int L = std::accumulate(V.begin(), V.begin() + x, x) + ax;
		int R = std::accumulate(V.begin(), V.begin() + y, y) + ay;
		ops.push_back({L, R});

		std::reverse(V.begin() + x + 1, V.begin() + y);
		V[x] = nx;
		V[y] = ny;
	};

	if (K+1 > int(V.size())) return {V, ops};
	if (K + 1 == int(V.size())) {
		do_op(0, int(V.size())-1, -1, 0);
		pair<vector<int>, vector<pair<int, int>>> resp1(V, ops);
		do_op(0, int(V.size())-1, -1, 0);
		pair<vector<int>, vector<pair<int, int>>> resp2(V, ops);
		return min(resp1, resp2);
	}

	for (int i = int(V.size())-1; i > K; i--) {
		do_op(-1, i, -1, 0);
	}
	if (K % 2 == 0) {
		for (int z = 1; int(ops.size()) < 2*N; z ^= 1) {
			if (z) {
				do_op(z, -1, 0, -1);
			} else {
				do_op(z, -1, -1, 0);
			}
		}
	} else {
		for (int z = 1; int(ops.size()) < 2*N; z ^= 1) {
			do_op(z, -1, -1, 0);
		}
	}

	return {V, ops};
}


int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		string A; cin >> A;
		assert(int(A.size()) == N);
		string B; cin >> B;
		assert(int(B.size()) == N);
		auto [va, opa] = solve(A, K);
		auto [vb, opb] = solve(B, K);
		if (va != vb) {
			cout << -1 << '\n';
		} else {
			cout << opa.size() + opb.size() << '\n';
			for (auto [x, y] : opa) cout << x+1 << ' ' << y << '\n';
			reverse(opb.begin(), opb.end());
			for (auto [x, y] : opb) cout << x+1 << ' ' << y << '\n';
		}
	}

	return 0;
}