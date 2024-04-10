#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M, K; cin >> N >> M >> K;
	string st; cin >> st;
	string en; cin >> en;

	vector<array<int, 20>> perm(N+1);
	iota(perm[0].begin(), perm[0].end(), 0);
	for (int i = 0; i < N; i++) {
		perm[i+1] = perm[i];
		int a, b; cin >> a >> b; a--, b--;
		swap(perm[i+1][a], perm[i+1][b]);
	}
	vector<uint32_t> st_pref(N+1);
	vector<uint32_t> en_pref(N+1);
	for (int i = 0; i <= N; i++) {
		for (int v = 0; v < K; v++) {
			en_pref[i] |= (en[v] - '0') << perm[i][v];
			st_pref[i] |= (st[v] - '0') << perm[i][v];
		}
	}

	vector<int> best_end((1 << K), -1);
	for (int i = 0; i <= N; i++) {
		best_end[en_pref[i]] = i;
	}
	vector<int> n_best_end((1 << K), -1);
	for (int s = 0; s <= K; s++) {
		for (int i = 0; i <= N; i++) {
			if (best_end[st_pref[i]] >= i + M) {
				cout << K - s << '\n';
				cout << i+1 << ' ' << best_end[st_pref[i]] << '\n';
				exit(0);
			}
		}
		fill(n_best_end.begin(), n_best_end.end(), -1);
		for (int z = 0; z < K; z++) {
			for (int m = 0; m < (1 << K); m++) {
				n_best_end[m] = max(n_best_end[m], best_end[m ^ (1 << z)]);
			}
		}
		swap(best_end, n_best_end);
	}
	assert(false);
	return 0;
}