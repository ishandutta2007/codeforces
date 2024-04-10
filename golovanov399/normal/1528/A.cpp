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
int l[N], r[N];

long long dp[N][2];

void dfs(int v, int p) {
	dp[v][0] = dp[v][1] = 0;
	for (int x : a[v]) {
		if (x != p) {
			dfs(x, v);
			dp[v][0] += max(abs(l[v] - l[x]) + dp[x][0], abs(l[v] - r[x]) + dp[x][1]);
			dp[v][1] += max(abs(r[v] - l[x]) + dp[x][0], abs(r[v] - r[x]) + dp[x][1]);
		}
	}
}

void solve() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		l[i] = nxt();
		r[i] = nxt();
	}
	for (int i = 0; i < n; ++i) {
		a[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0, 0);
	cout << max(dp[0][0], dp[0][1]) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}