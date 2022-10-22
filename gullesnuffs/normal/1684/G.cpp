#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
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

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<int> large;
	vector<int> small;
	bool impossible = false;
	rep(i,0,n) {
		ll t;
		cin >> t;
		if (t*2 >= m) {
			impossible = true;
		}
		if (t*3 <= m) {
			small.push_back(t);
		} else {
			large.push_back(t);
		}
	}
	if (impossible) {
		cout << "-1" << endl;
		return;
	}
	vector<vector<int>> g;
	rep(i,0,sz(large)) {
		g.emplace_back();
		rep(j,0,sz(small)) {
			if (large[i]%small[j] == 0 && large[i]*2+small[j] <= m) {
				g[i].push_back(j);
			}
		}
	}
	vector<int> btoa(sz(small), -1);
	int matching = hopcroftKarp(g, btoa);
	if (matching < sz(large)) {
		cout << "-1" << endl;
		return;
	}
	vector<pair<int, int>> ans;
	rep(i,0,sz(small)) {
		int large_ind = btoa[i];
		if (large_ind == -1) {
			ans.emplace_back(2*small[i], 3*small[i]);
		} else {
			int l = large[large_ind];
			ans.emplace_back(small[i]+l, small[i]+2*l);
		}
	}
	cout << sz(ans) << endl;
	for (auto it : ans) {
		assert(it.first <= m);
		assert(it.second <= m);
		cout << it.second << " " << it.first << endl;
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	solve();
}