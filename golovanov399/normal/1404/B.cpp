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
int d[N];

void dfs(int v, int p = -1) {
	for (int x : a[v]) {
		if (x != p) {
			d[x] = d[v] + 1;
			dfs(x, v);
		}
	}
}

void mark_dist(int v) {
	d[v] = 0;
	dfs(v);
}

void solve() {
	int n = nxt(), va = nxt() - 1, vb = nxt() - 1, da = nxt(), db = nxt();
	for (int i = 0; i < n; ++i) {
		a[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	mark_dist(va);
	if (d[vb] <= da || db <= 2 * da) {
		puts("Alice");
		return;
	}

	int e1 = max_element(d, d + n) - d;
	mark_dist(e1);
	int diam = *max_element(d, d + n);
	if (2 * da >= diam) {
		puts("Alice");
	} else {
		puts("Bob");
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}