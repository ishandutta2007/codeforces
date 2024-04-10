#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 510;
constexpr i64 inf = 1e18;
int n, m;
i64 G[N][N], H[N][N], F[N][N], A[N][N], mn[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		cin >> n >> m;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) H[i][j] = G[i][j] = F[i][j] = (i != j) * inf, A[i][j] = inf;
			mn[i] = inf;
		}
		for(int i = 1; i <= m; i ++) {
			i64 u, v, w;
			cin >> u >> v >> w;
			H[u][v] = H[v][u] = 1;
			G[u][v] = min(G[u][v], w);
			G[v][u] = min(G[v][u], w);
			mn[u] = min(mn[u], w);
			mn[v] = min(mn[v], w);
		}
		for(int k = 1; k <= n; k ++) {
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= n; j ++) H[i][j] = min(H[i][k] + H[k][j], H[i][j]);
			}
		}
		i64 ans = inf;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) if(G[i][j] != inf && i != j) {
				ans = min(ans, (1ll + H[1][i] + H[j][n]) * G[i][j]);
				for(int k = 1; k <= n; k ++) {
					ans = min(ans, (H[1][k] + H[k][n] + H[i][k] + 2ll) * G[i][j]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}