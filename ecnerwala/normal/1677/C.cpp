#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		std::vector<int> B(N);
		for (auto& a : A) { cin >> a; a--; }
		for (auto& a : B) { cin >> a; a--; }
		std::vector<int> par(N, -1);
		auto get_par = [&](int a) {
			while (par[a] >= 0) {
				if (par[par[a]] >= 0) par[a] = par[par[a]];
				a = par[a];
			}
			return a;
		};
		auto merge = [&](int a, int b) {
			a = get_par(a), b = get_par(b);
			if (a == b) return false;
			if (par[a] > par[b]) std::swap(a, b);
			par[a] += par[b];
			par[b] = a;
			return true;
		};
		for (int i = 0; i < N; i++) {
			merge(A[i], B[i]);
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (par[i] < 0) {
				cnt += (-par[i]) / 2;
			}
		}
		int64_t ans = 0;
		for (int i = 0; i < cnt; i++) {
			ans += 2 * (N - 1 - i - i);
		}
		cout << ans << '\n';
	}

	return 0;
}