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
	int n = nxt(), k = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < n * k; ++i) {
		a[nxt() - 1].push_back(i);
	}
	for (int first = 0; first < n; first += k - 1) {
		int last = min(n, first + k - 1);
		vector<pair<int, int>> ans(last - first);
		vector<int> remv(last - first);
		iota(all(remv), first);
		set<int> rem(all(remv));
		for (int i = 0; i < last - first; ++i) {
			int opt = *rem.begin();
			for (int x : rem) {
				if (a[x][i + 1] < a[opt][i + 1]) {
					opt = x;
				}
			}
			ans[opt - first] = {a[opt][i], a[opt][i + 1]};
			rem.erase(opt);
		}
		for (const auto& [l, r] : ans) {
			cout << l + 1 << " " << r + 1 << "\n";
		}
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}