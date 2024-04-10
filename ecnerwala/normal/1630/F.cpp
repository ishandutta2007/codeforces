#include <bits/stdc++.h>

namespace kactl {
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const int V = int(5e4) + 20;
	std::vector<vector<int>> factors(V+1);
	for (int i = 1; i <= V; i++) {
		for (int j = 2*i; j <= V; j += i) {
			factors[j].push_back(i);
		}
	}

	std::vector<int> idx(V+1, -1);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		for (int i = 0; i < N; i++) idx[A[i]] = i;

		std::vector<std::vector<int>> g(2*N);
		for (int i = 0; i < N; i++) {
			g[2*i].push_back(2*i+1);
			for (int v : factors[A[i]]) {
				int j = idx[v];
				if (j == -1) continue;
				assert(i != j);
				g[2*i].push_back(2*j);
				g[2*i+1].push_back(2*j+1);
				g[2*i].push_back(2*j+1);
			}
		}

		std::vector<int> btoa(2*N, -1);
		cout << N - (2*N - kactl::hopcroftKarp(g, btoa)) << '\n';

		for (int i = 0; i < N; i++) idx[A[i]] = -1;
	}

	return 0;
}