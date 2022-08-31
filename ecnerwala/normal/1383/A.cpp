#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; string A, B; cin >> N >> A >> B;
		int ans = [&]() -> int {
			vector<int> par(20, -1);
			auto get_par = [&](int a) -> int {
				while (par[a] >= 0) a = par[a];
				return a;
			};
			auto merge = [&](int a, int b) -> bool {
				a = get_par(a);
				b = get_par(b);
				if (a == b) return false;
				if (par[a] > par[b]) swap(a, b);
				par[b] = a;
				return true;
			};

			int res = 0;
			for (int i = 0; i < N; i++) {
				if (A[i] > B[i]) return -1;
				res += merge(A[i] - 'a', B[i] - 'a');
			}
			return res;
		}();
		cout << ans << '\n';
	}

	return 0;
}