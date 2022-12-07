#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int x = 1; x <= 2; x++) {
		vector f(n + 1, vector(n + 1, 0));
		queue<pair<int, int>> que;
		vector step(n + 1, vector(n + 1, 0));
		for (int i = x; i <= n; i += 2) {
			if (a[i] == -1 || a[i] == 1) {
				f[i][i] = 1, que.emplace(i, i), step[i][i] = 1;
			}
		}
		while (!que.empty()) {
			auto [l, r] = que.front();
			que.pop();
			if (l > r) {
				continue;
			}
			if (step[l][r] == n) {
				ans = (ans + f[l][r]) % M;
				continue;
			}
			int nl, nr;
			if (l % 2 == x % 2) {
				nl = (l == 1) ? 2 : max(1, l - 2);
			} else {
				nl = l + 2;
			}
			if (r % 2 == x % 2) {
				nr = (r == n) ? (n - 1) : min(n, r + 2);
			} else {
				nr = r - 2;
			}
			auto upd = [&](int x, int y, int d) {
				if (!step[x][y]) {
					step[x][y] = d;
					que.emplace(x, y);
				}
			};
			if (step[l][r] == n - 1) {
				upd(nl, nr, n);
				if (a[nl] == n || a[nl] == -1) {
					f[nl][nr] = (f[nl][nr] + f[l][r]) % M;
				}
			} else {
				int d = step[l][r] + 1;
				upd(nl, r, d);
				if (a[nl] == d || a[nl] == -1) {
					f[nl][r] = (f[nl][r] + f[l][r]) % M;
				}
				upd(l, nr, d);
				if (a[nr] == d || a[nr] == -1) {
					f[l][nr] = (f[l][nr] + f[l][r]) % M;
				}
			}
		}
	}
	printf("%d\n", (ans % M + M) % M);
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