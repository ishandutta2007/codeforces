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

const int N = 622'222;
vector<int> g[N];
char used[N];

bool dfs(int v) {
	used[v] = 1;
	for (int x : g[v]) {
		if (used[x] == 2) {
			continue;
		}
		if (used[x] == 1) {
			return true;
		}
		if (dfs(x)) {
			return true;
		}
	}
	used[v] = 2;
	return false;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	vector<int> cnt(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
		cnt[a[i]] += 1;
	}
	int ban = max_element(all(cnt)) - cnt.begin();
	vector<int> b(n);
	for (int& x : b) {
		x = nxt() - 1;
	}
	for (int i = 0; i < 2 * n; ++i) {
		g[i].clear();
		used[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != ban) {
			g[i].push_back(n + a[i]);
		}
		if (b[i] != ban) {
			g[n + b[i]].push_back(i);
		}
	}
	for (int i = 0; i < 2 * n; ++i) {
		if (!used[i] && dfs(i)) {
			cout << "WA\n";
			return;
		}
	}
	cout << "AC\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}