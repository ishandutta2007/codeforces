#include <bits/stdc++.h>

int minv(int a, int m) {
	if (m == 1) return 0;
	if (a == 1) return 1;
	return int(m - int64_t(minv(m % a, a)) * m / a);
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; int64_t K; cin >> N >> M >> K;
	vector<int> A(N); for (auto& a : A) cin >> a;
	vector<int> B(M); for (auto& b : B) cin >> b;

	const int V = 2 * max(N, M) + 2;
	vector<array<int, 2>> loc(V+1, array<int, 2>{-1, -1});
	for (int i = 0; i < N; i++) {
		loc[A[i]][0] = i;
	}
	for (int j = 0; j < M; j++) {
		loc[B[j]][1] = j;
	}
	vector<int64_t> overlaps; overlaps.reserve(min(N, M));

	int G = std::gcd(N, M);
	N /= G, M /= G;
	int64_t P = int64_t(N) * int64_t(M) * int64_t(G);
	int64_t inv_N = minv(N, M);
	for (auto [x, y] : loc) {
		if (x == -1 || y == -1) continue;
		if (x % G != y % G) continue;
		int g = x % G;
		x /= G, y /= G;
		y -= x;
		y %= M;
		if (y < 0) y += M;
		int64_t v = (x + (y * inv_N) % M * N);
		v *= G;
		v += g;
		overlaps.push_back(v);
	}

	// number that are bad in the first T days
	auto num_bad = [&](int64_t T) -> int64_t {
		int64_t ans = T;
		ans -= int(overlaps.size()) * (T / P);
		T %= P;
		for (int64_t v : overlaps) ans -= v < T;
		return ans;
	};

	int64_t mi = 0;
	int64_t ma = 2e18;
	while (ma - mi > 1) {
		int64_t md = mi + (ma - mi) / 2;
		if (num_bad(md) >= K) ma = md;
		else mi = md;
	}
	cout << ma << '\n';

	return 0;
}