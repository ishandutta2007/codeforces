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

const int N = 2222;
vector<int> a[N];
int val[N];
int sz[N];
int c[N];

void panic() {
	cout << "NO\n";
	exit(0);
}

void incGe(int v, int x) {
	if (val[v] >= x) {
		++val[v];
	}
	for (int u : a[v]) {
		incGe(u, x);
	}
}

void dfs(int v, int off) {
	int old_off = off;
	for (int x : a[v]) {
		dfs(x, off);
		sz[v] += sz[x];
		off += sz[x];
	}
	if (sz[v] < c[v]) {
		panic();
	}
	incGe(v, old_off + c[v]);
	val[v] = old_off + c[v];
	++sz[v];
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	int root = -1;
	for (int i = 0; i < n; ++i) {
		int p = nxt() - 1;
		if (p == -1) {
			root = i;
		} else {
			a[p].push_back(i);
		}
		c[i] = nxt();
	}
	dfs(root, 1);
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << val[i] << " ";
	}
	cout << "\n";

	return 0;
}