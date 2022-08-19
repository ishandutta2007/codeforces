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
} // namespace kactl

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; int64_t MX; cin >> N >> MX;

	std::vector<int64_t> smalls; smalls.reserve(N);
	std::vector<int64_t> bigs; bigs.reserve(N);
	for (int i = 0; i < N; i++) {
		int64_t a; cin >> a;
		if (3 * a <= MX) smalls.push_back(a);
		else bigs.push_back(a);
	}

	std::vector<std::vector<int>> adj(bigs.size());
	for (int i = 0; i < int(bigs.size()); i++) {
		for (int j = 0; j < int(smalls.size()); j++) {
			if (bigs[i] % smalls[j] == 0 && 2 * bigs[i] + smalls[j] <= MX) {
				adj[i].push_back(j);
			}
		}
	}

	std::vector<int> btoa(smalls.size(), -1);
	int res = kactl::hopcroftKarp(adj, btoa);
	if (res != int(bigs.size())) {
		cout << -1 << '\n';
	} else {
		cout << int(smalls.size()) << '\n';
		for (int i = 0; i < int(smalls.size()); i++) {
			if (btoa[i] == -1) {
				cout << smalls[i] * 2 << ' ' << smalls[i] * 3 << '\n';
			} else {
				int j = btoa[i];
				cout << smalls[i] + bigs[j] << ' ' << smalls[i] + 2 * bigs[j] << '\n';
			}
		}
	}

	return 0;
}