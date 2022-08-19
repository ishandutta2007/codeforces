#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<int> X(M);
		vector<int> Y(M);
		vector<int> par(N, -1);
		auto get_par = [&](int a) {
			while (par[a] >= 0) {
				if (par[par[a]] >= 0) par[a] = par[par[a]];
				a = par[a];
			}
			return a;
		};
		auto merge = [&](int a, int b) -> bool {
			a = get_par(a), b = get_par(b);
			if (a == b) return false;
			if (par[a] > par[b]) swap(a, b);
			par[a] += par[b];
			par[b] = a;
			return true;
		};

		int ans = M;
		for (int i = 0; i < M; i++) {
			cin >> X[i] >> Y[i];
			X[i]--, Y[i]--;
			if (X[i] == Y[i]) {
				// we're already done
				ans--;
			} else {
				if (!merge(X[i], Y[i])) ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}