#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL lnf = 1e18;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, m;
	cin >> n >> m;
	vector w(n + 1, vector(n + 1, lnf));
	vector s(n + 1, vector(n + 1, inf));
	for (int i = 1; i <= m; i++) {
		LL u, v, x;
		cin >> u >> v >> x;
		w[u][v] = min(w[u][v], x);
		w[v][u] = min(w[v][u], x);
	}
	auto bfs = [&](int s, vector<int> &step) {
		step[s] = 0;
		queue<int> que;
		que.push(s);
		while (!que.empty()) {
			int v = que.front();
			que.pop();
			for (int j = 1; j <= n; j++) {
				if (w[v][j] < lnf && step[j] > step[v] + 1) {
					step[j] = step[v] + 1;
					que.push(j);
				}
			}
		}
	};
	for (int i = 1; i <= n; i++) {
		bfs(i, s[i]);
	}
	LL ans = lnf;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (w[i][j] < lnf) {
				if (s[1][i] < inf && s[j][n] < inf) {
					ans = min(ans, w[i][j] * (s[1][i] + s[j][n] + 1ll));
				}
				for (int k = 1; k <= n; k++) {
					if (s[1][k] < inf && s[k][n] < inf) {
						if (s[k][i] < inf) {
							ans = min(ans, w[i][j] * (s[1][k] + s[k][n] + s[k][i] + 2ll));
						}
						if (s[k][j] < inf) {
							ans = min(ans, w[i][j] * (s[1][k] + s[k][n] + s[k][j] + 2ll));
						}
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
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