#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ar3 = array<array<array<bool, 101>, 101>, 101>;

struct Tree {
	vector<vector<int>> e;
	vector<bool> vfa;
	int n;
	void addedge(int u, int v) {
		e[u].emplace_back(v), vfa[v] = true;
		e[v].emplace_back(u);
	}
	Tree(int n, const ar3 &chk, int son) : e(n + 1), vfa(n + 1) {
		this->n = n;
		int root = 1;
		vfa[root] = true;
		addedge(root, son);
		for (int i = 1; i <= n; i++) {
			if (!vfa[i] && chk[root][son][i]) {
				addedge(root, i);
			}
		}
		for (auto u : e[root]) {
			build(u, root, chk);
		}
	}
	void build(int v, int fa, const ar3 &chk) {
		for (int i = 1; i <= n; i++) {
			if (!vfa[i] && chk[v][fa][i]) {
				addedge(v, i);
			}
		}
		for (auto u : e[v]) {
			if (u != fa) {
				build(u, v, chk);
			}
		}
	}
	vector<array<int, 101>> dis;
	void getdis(int v, int fa, array<int, 101> &d) {
		d[v] = (fa ? (d[fa] + 1) : 0);
		for (auto u : e[v]) {
			if (u != fa) {
				getdis(u, v, d);
			}
		}
	}
	bool test(int n, const ar3 &chk) {
		for (int i = 1; i <= n; i++) {
			if (!vfa[i]) {
				return false;
			}
		}
		dis.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			getdis(i, 0, dis[i]);
			for (int j = 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					if (chk[i][j][k] && dis[i][j] != dis[i][k]) {
						return false;
					}
					if (!chk[i][j][k] && dis[i][j] == dis[i][k]) {
						return false;
					}
				}
			}
		}
		return true;
	}
	void output(int v = 1, int fa = 0) {
		if (fa) {
			printf("%d %d\n", fa, v);
		}
		for (auto u : e[v]) {
			if (u != fa) {
				output(u, v);
			}
		}
	}
};

void solve() {
	int n;
	cin >> n;
	ar3 chk{};
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			string s;
			cin >> s;
			for (int k = 1; k <= n; k++) {
				if (s[k - 1] == '1') {
					chk[k][i][i + j] = true;
					chk[k][i + j][i] = true;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		Tree t(n, chk, i);
		if (t.test(n, chk)) {
			puts("Yes");
			t.output();
			return;
		}
	}
	puts("No");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}