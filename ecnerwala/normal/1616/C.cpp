#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			std::map<std::pair<int, int>, int> cnd;
			for (int j = 0; j < N; j++) {
				if (j == i) continue;
				int a = A[j] - A[i];
				int b = j - i;
				if (b < 0) a = -a, b = -b;
				int g = std::gcd(std::abs(a), b);
				a /= g, b /= g;
				ans = std::max(ans, ++cnd[{a, b}]);
			}
		}
		cout << N-1-ans << '\n';
	}

	return 0;
}