#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int nxt() {
	int x;
	cin >> x;
	return x;
}

constexpr int mod = 998'244'353;

const int N = 333'333;
vector<int> a[N];
int sz[N];
int cnt[N];

void dfs(int v, int p) {
	int res = 0;
	sz[v] = 1;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		sz[v] += sz[x];
	}
}

int ans[N];

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
	fill(ans + 1, ans + n + 1, 0);
	dfs(0, 0);
	ans[1] = 1;
	for (int i = 1; i < n; ++i) {
		ans[1] *= 2;
		if (ans[1] >= mod) {
			ans[1] -= mod;
		}
	}
	fill(cnt, cnt + n + 1, 0);
	for (int i = 0; i < n; ++i) {
		cnt[sz[i]] += 1;
	}
	for (int d = 2; d < n; ++d) {
		if (n % d != 1) {
			continue;
		}
		int need = n;
		for (int i = 0; i <= n; i += d) {
			need -= cnt[i] + cnt[i + 1];
		}
		ans[d] = !need;
	}
	
	for (int i = n; i > 0; --i) {
		for (int j = i + i; j <= n; j += i) {
			ans[i] -= ans[j];
			if (ans[i] < 0) {
				ans[i] += mod;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}