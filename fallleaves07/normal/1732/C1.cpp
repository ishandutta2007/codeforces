#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	vector<array<int, 30>> sum(n + 1), lst(n + 1), nxt(n + 2);
	lst[0].fill(0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		lst[i] = lst[i - 1], sum[i] = sum[i - 1];
		for (int j = 0; j < 30; j++) {
			if ((a[i] >> j) & 1) {
				sum[i][j]++, lst[i][j] = i;
			}
		}
	}
	nxt[n + 1].fill(n + 1);
	for (int i = n; i >= 1; i--) {
		nxt[i] = nxt[i + 1];
		for (int j = 0; j < 30; j++) {
			if ((a[i] >> j) & 1) {
				nxt[i][j] = i;
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		multiset<int> lbound;
		map<int, vector<int>> op;
		int tot = 0;
		for (int j = 0; j < 30; j++) {
			int s = sum[r][j] - sum[l - 1][j];
			if (s < 2) {
				continue;
			}
			++tot;
			if (s % 2 == 0) {
				op[lst[r][j]].emplace_back(nxt[l][j]);
			} else {
				int x = nxt[l][j], y = nxt[x + 1][j], w = lst[r][j], z = lst[w - 1][j];
				op[z].emplace_back(x);
				op[w].emplace_back(-x);
				op[w].emplace_back(y);
			}
		}
		int ansl = l, ansr = l;
		if (tot > 0) {
			ansr = r;
			for (auto [nowr, vec] : op) {
				for (auto d : vec) {
					if (d < 0) {
						lbound.erase(lbound.find(-d));
					} else {
						lbound.insert(d);
					}
				}
				if ((int)lbound.size() == tot) {
					int nowl = *lbound.begin();
					if (nowr - nowl < ansr - ansl) {
						ansl = nowl, ansr = nowr;
					}
				}
			}
		}
		printf("%d %d\n", ansl, ansr);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}