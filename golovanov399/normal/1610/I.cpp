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

struct Edge {
	int to;
	int w;
};

const int N = 333'333;
vector<int> ed[N];

bool is_base[N];
int par[N];
int pid[N];

int score;
vector<Edge> a[N];

void mark_tree(int v, int p) {
	par[v] = p;
	for (int i = 0; i < (int)ed[v].size(); ++i) {
		if (ed[v][i] == p) {
			ed[v].erase(ed[v].begin() + i);
			--i;
			continue;
		}
		mark_tree(ed[v][i], v);
	}
}

int calc_score(int v) {
	int x = 0;
	for (auto& e : a[v]) {
		x ^= (e.w = calc_score(e.to) + 1);
	}
	return x;
}

void solve() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	mark_tree(0, -1);
	for (int i = 0; i < n; ++i) {
		for (int x : ed[i]) {
			a[i].push_back({x, 0});
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			pid[a[i][j].to] = j;
		}
	}
	is_base[0] = 1;
	score = calc_score(0);
	string ans(1, (char)('1' + !score));
	// for (int i = 0; i < n; ++i) {
	// 	for (auto e : a[i]) {
	// 		cerr << i + 1 << " -> " << e.to + 1 << ": " << e.w << "\n";
	// 	}
	// }
	for (int i = 1; i < n; ++i) {
		if (is_base[i]) {
			ans += (char)('1' + !score);
			continue;
		}

		int v = i;
		int last = -1;
		while (!is_base[v]) {
			for (auto& e : a[v]) {
				if (e.to == last) {
					score ^= 1;
				} else {
					score ^= e.w;
				}
			}
			is_base[v] = true;
			last = v;
			v = par[v];
		}
		score ^= a[v][pid[last]].w ^ 1;

		ans += (char)('1' + !score);
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}