#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;

		vector<vector<int>> F(M);
		for (auto& v : F) {
			int k; cin >> k;
			v.resize(k);
			for (auto& a : v) cin >> a;
		}

		vector<int> cnt(N+1);
		vector<int> C(M);
		for (int i = 0; i < M; i++) {
			C[i] = F[i][0];
			cnt[C[i]]++;
		}

		for (int v = 1; v <= N; v++) {
			if (cnt[v] > (M+1)/2) {
				for (int i = 0; cnt[v] > (M+1)/2 && i < M; i++) {
					if (C[i] == v && int(F[i].size()) > 1) {
						cnt[C[i]]--;
						C[i] = F[i][1];
						cnt[C[i]]++;
					}
				}
				if (cnt[v] > (M+1)/2) {
					cout << "NO" << '\n';
					goto finished;
				}
			}
		}

		cout << "YES" << '\n';
		for (int i = 0; i < M; i++) {
			cout << C[i] << " \n"[i+1==M];
		}

finished:;
	}

	return 0;
}