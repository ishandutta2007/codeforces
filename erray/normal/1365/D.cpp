#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<string> gr(n);
		for (int i = 0; i < n; ++i) cin >> gr[i];
		auto aor = [&](int x, int y) {
			return x < 0 || x == n || y == m || y < 0;
		};
		bool ans = 1;
		int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if(gr[i][j] == 'B') {
					for (int q = 0; q < 4; ++q) {
						int nx = i + mx[q], ny = j + my[q];
						if (aor(nx, ny)) continue;
						if (gr[nx][ny] == 'G') ans = 0;
						if(gr[nx][ny] == '.')gr[nx][ny] = '#';
					}
				}
			}
		}
		auto BFS = [&](int x, int y) {
			vector<vector<int>> vis(n, vector<int>(m));
			queue<pair<int, int>> Q;
			Q.emplace(x, y);
			while (!Q.empty()) {
				int cx = Q.front().first, cy = Q.front().second;
				Q.pop();
				if (vis[cx][cy] || gr[cx][cy] == '#') continue;
				vis[cx][cy] = 1;
				for (int q = 0; q < 4; ++q) {
					int nx = cx + mx[q], ny = cy + my[q];
					if (aor(nx, ny) || gr[nx][ny] == '#') continue;
					Q.emplace(nx, ny);
				}
			}
			return vis;
		};
		vector<vector<int>> r = BFS(n - 1, m - 1);
		for (int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(gr[i][j] == 'G') ans &= r[i][j]; 		
		cout << (ans ? "Yes" : "No") << '\n';
	}
}