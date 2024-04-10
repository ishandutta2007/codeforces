#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 111111;
vector<int> a[N];
int par[N], lvl[N];

void dfs(int v, int p = -1) {
	par[v] = p;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		lvl[x] = lvl[v] + 1;
		dfs(x, v);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	dfs(0);
	int v = max_element(lvl, lvl + n) - lvl;
	lvl[v] = 0;
	dfs(v);
	v = max_element(lvl, lvl + n) - lvl;
	if (lvl[v] != 2 * k) {
		cout << "No\n";
		return 0;
	}
	for (int i = 0; i < k; ++i) {
		v = par[v];
	}
	lvl[v] = 0;
	dfs(v);

	for (int i = 0; i < n; ++i) {
		if ((int)a[i].size() == 1) {
			if (lvl[i] != k) {
				cout << "No\n";
				return 0;
			}
		} else {
			int deg = a[i].size();
			if (i != v) {
				--deg;
			}
			if (deg < 3) {
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";

	return 0;
}