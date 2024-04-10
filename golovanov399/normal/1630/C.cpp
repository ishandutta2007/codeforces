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
	vector<int> first(n, -1), last(n, -1);
	for (int i = 0; i < n; ++i) {
		int x = nxt() - 1;
		if (first[x] == -1) {
			first[x] = i;
		}
		last[x] = i;
	}
	vector<pair<int, int>> segs;
	for (int i = 0; i < n; ++i) {
		if (first[i] != last[i]) {
			segs.push_back({first[i], last[i]});
		}
	}
	vector<int> to(n, -1);
	for (auto [l, r] : segs) {
		to[l] = r;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (to[i] == -1) {
			continue;
		}
		int j = to[i];
		int cur = i;
		while (true) {
			++cur;
			int nx = -1;
			while (cur < j) {
				nx = max(nx, to[cur]);
				++ans;
				++cur;
			}
			if (nx == -1) {
				break;
			}
			j = nx;
		}
		i = j;
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}