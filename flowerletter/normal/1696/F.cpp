#include <bits/stdc++.h>
using namespace std;
constexpr int N = 105;
int T, n, vis[N][N], dis[N][N];
string a[N][N];
vector<pair<int, int>> trans[N][N];
vector<int> G[N];
int ok[N], use[N][N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T; T --) {
		cin >> n;
		for(int i = 1; i <= n; i ++) for(int j = i + 1; j <= n; j ++) {
			cin >> a[i][j];
			a[i][j] = "*" + a[i][j];
			trans[i][j].clear();
			use[i][j] = 0;
		}
		if(n == 2) {
			if(a[1][2] == "*00") {
				cout << "YES\n";
				cout << 1 << ' ' << 2 << '\n';
			}
			else {
				cout << "NO\n";
			}
			continue;
		}
		int answer = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1; j <= n; j ++) {
				for(int k = 1; k <= n; k ++) if(a[i][j][k] == '1') {
					if(i == k || j == k) answer = -1;
					trans[min(k, i)][max(k, i)].emplace_back(min(k, j), max(k, j));
					trans[min(k, j)][max(k, j)].emplace_back(min(k, i), max(k, i));
				}
			}
		}
		if(answer == -1) {
			cout << "NO\n";
			continue;
		}
		for(int i = 1; !answer && i <= n; i ++) {
			for(int j = i + 1; !answer && j <= n; j ++) if(!use[i][j]) {
				for(int i = 1; i <= n; i ++) {
					for(int j = 1; j <= n; j ++) vis[i][j] = 0;
				}
				queue<pair<int, int>> q;
				q.emplace(i, j);
				vis[i][j] = 1;
				vector<pair<int, int>> e;
				while(!q.empty()) {
					auto [u, v] = q.front(); q.pop();
					e.emplace_back(u, v);
					if(e.size() >= n) break;
					for(auto [x, y] : trans[u][v]) {
						if(!vis[x][y]) q.emplace(x, y), vis[x][y] = 1;
					}
				}
				if(e.size() == n - 1) {
					auto istree = [&] () {
						for(int i = 1; i <= n; i ++) G[i].clear(), ok[i] = 0;
						for(auto [u, v] : e) {
							G[u].emplace_back(v);
							G[v].emplace_back(u);
						}
						int cnt = 0;
						function<bool(int, int)> check = [&] (int u, int par) {
							if(ok[u]) return 0;
							ok[u] = 1;
							cnt ++;
							for(auto v : G[u]) if(v != par) {
								if(!check(v, u)) return 0;
							}
							return 1;
						};
						return check(1, -1) && cnt == n;
					};
					if(istree()) {
						for(auto [u, v] : e) use[u][v] = 1;
						for(int rt = 1; rt <= n; rt ++) {
							function<void(int, int)> dfs = [&] (int u, int par) {
								for(auto v : G[u]) if(v != par) {
									dis[rt][v] = dis[rt][u] + 1;
									dfs(v, u);
								}
							};
							dfs(rt, -1);
						}
						int flag = 1;
						for(int i = 1; flag && i <= n; i ++) {
							for(int j = i + 1; flag && j <= n; j ++) {
								for(int k = 1; flag && k <= n; k ++) {
									if((dis[i][k] == dis[j][k]) != a[i][j][k] - '0') {
										flag = 0;
									}
								}
							}
						}
						if(flag) {
							cout << "YES\n";
							for(auto [u, v] : e) cout << u << ' ' << v << '\n';
							answer = 1;
						}
					}

				}
			}
		}
		if(!answer) cout << "NO\n";
	}
	return 0;
}