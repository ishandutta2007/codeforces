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

void solve() {
	int n = nxt();
	vector<vector<int>> ans(n, vector<int>(n, 0));
	vector<int> a(n);
	generate(all(a), nxt);
	for (int t = 1; t <= n; ++t) {
		for (int i = 0; i < (int)a.size(); ++i) {
			ans[t - 1 + i][i] = a[i];
		}
		a.erase(find(all(a), t));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}