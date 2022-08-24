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
int cnt[N];
long long reserved[N];
int low[N], high[N];

const int inf = 2e9;

void dfs(int v) {
	cnt[v] = 0;
	reserved[v] = 0;
	for (int x : a[v]) {
		dfs(x);
		cnt[v] += cnt[x];
		reserved[v] += reserved[x];
	}
	if (reserved[v] < low[v]) {
		cnt[v] += 1;
		reserved[v] = high[v];
	} else if (reserved[v] > high[v]) {
		reserved[v] = high[v];
	}
}

void solve() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		a[i] = {};
	}
	for (int i = 1; i < n; ++i) {
		int v = nxt() - 1;
		a[v].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		low[i] = nxt();
		high[i] = nxt();
	}
	dfs(0);
	// for (int i = 0; i < n; ++i) {
	// 	cerr << cnt[i] << " " << reserved[i] << "\n";
	// }
	cout << cnt[0] << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}