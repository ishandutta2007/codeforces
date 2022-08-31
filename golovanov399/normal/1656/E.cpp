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

const int N = 111'111;
vector<int> a[N];
int h[N];

void dfs(int v, int p = -1) {
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		h[x] = -h[v];
		dfs(x, v);
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
	h[0] = 1;
	dfs(0);
	for (int i = 0; i < n; ++i) {
		cout << (int)a[i].size() * h[i] << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}