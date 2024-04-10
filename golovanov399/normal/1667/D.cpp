#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 222'222;
vector<int> a[N];

bool can[N][3];
int cnt_sons[N][4];
vector<int> exact_sons[N][4];

bool f(int v, int ce, int co) {
	if (ce < 0 || co < 0) {
		return false;
	}
	return max(0, ce - cnt_sons[v][1]) + max(0, co - cnt_sons[v][2]) <= cnt_sons[v][3];
}

void dfs(int v, int p = -1) {
	fill(can[v], can[v] + 3, false);
	fill(cnt_sons[v], cnt_sons[v] + 4, 0);
	for (int i = 0; i < 4; ++i) {
		exact_sons[v][i].clear();
	}
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		int mask = 0;
		if (can[x][1]) {
			mask |= 1;
		}
		if (can[x][2]) {
			mask |= 2;
		}
		cnt_sons[v][mask] += 1;
		exact_sons[v][mask].push_back(x);
	}

	int cnt_odd = (a[v].size() + 1) / 2;
	int cnt_even = (a[v].size()) / 2;

	if (~p) {
		can[v][1] = f(v, cnt_even - 1, cnt_odd);
		can[v][2] = f(v, cnt_even, cnt_odd - 1);
	} else {
		can[v][0] = f(v, cnt_even, cnt_odd);
	}
}

vector<pair<int, int>> ans;
void propagate(int v, int p, int free_flip) {
	// cerr << v << " " << p << ": " << free_flip << "\n";
	int d = a[v].size();
	while (d) {
		if (free_flip == (1 << (d % 2))) {
			// cerr << "yay free flip " << d << "\n";
			ans.push_back({v, p});
			free_flip = 0;
		} else {
			int idx = 1 << (d % 2);
			if (exact_sons[v][idx].empty()) {
				idx = 3;
			}
			assert(!exact_sons[v][idx].empty());
			int x = exact_sons[v][idx].back();
			exact_sons[v][idx].pop_back();
			propagate(x, v, 1 << (d % 2));
		}
		--d;
	}
}

void solve() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		a[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0);
	if (!can[0][0]) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	ans.clear();
	propagate(0, -1, 0);
	for (auto [u, v] : ans) {
		cout << u + 1 << " " << v + 1 << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}