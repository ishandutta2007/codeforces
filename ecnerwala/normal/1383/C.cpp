#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; string A, B; cin >> N >> A >> B;
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
			par[a] += par[b];
			par[b] = a;
			return true;
		};

		vector<int32_t> adj(20);
		int res = 0;
		for (int i = 0; i < N; i++) {
			res += merge(A[i] - 'a', B[i] - 'a');
			adj[A[i]-'a'] |= 1 << (B[i] - 'a');
		}

		int best_dag = 0;
		vector<bool> is_good(1<<20);
		is_good[0] = true;
		for (int m = 0; m < (1<<20); m++) {
			if (!is_good[m]) continue;
			best_dag = max(best_dag, __builtin_popcount(m));
			for (int i = 0; i < 20; i++) {
				if (m & (1 << i)) continue;
				if (adj[i] & m) continue;
				is_good[m | (1 << i)] = true;
			}
		}

		res += 20 - best_dag;

		cout << res << '\n';
	}

	return 0;
}