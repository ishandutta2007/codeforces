#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 222222;
vector<int> a[N];

int sz[N];
int par[N];

void dfsSize(int v, int p = -1) {
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfsSize(x, v);
		sz[v] += sz[x];
	}
	par[v] = p;
	++sz[v];
}

vector<int> ans;

void dfs(int v) {
	for (int x : a[v]) {
		if (x == par[v]) {
			continue;
		}
		if (sz[x] % 2 == 0) {
			dfs(x);
		}
	}
	ans.push_back(v);
	for (int x : a[v]) {
		if (x == par[v]) {
			continue;
		}
		if (sz[x] % 2) {
			dfs(x);
		}
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		int u = nxt() - 1, v = i;
		if (u == -1) {
			continue;
		}
		a[u].push_back(v);
		a[v].push_back(u);
	}

	if (n % 2 == 0) {
		cout << "NO\n";
		return 0;
	}

	dfsSize(0);
	dfs(0);
	printf("YES\n");
	for (int x : ans) {
		printf("%d\n", x + 1);
	}
	// printf("\n");

	return 0;
}