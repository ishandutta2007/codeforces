#include <bits/stdc++.h>

using namespace std;

const pair<int, int> d[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    bool ok = false;
    vector<vector<bool>> vis(n, vector<bool>(m));

    function<void(int, int, int, int)> dfs =
            [&](int x, int y, int px, int py) -> void {
        vis[x][y] = true;

        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (unsigned(nx) >= n || unsigned(ny) >= m) continue;
            if (nx == px && ny == py) continue;
            if (a[nx][ny] != a[x][y]) continue;
            if (vis[nx][ny]) {
                ok = true;
                continue;
            }

            dfs(nx, ny, x, y);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (!vis[i][j]) {
            dfs(i, j, i, j);
        }
    }

    if (ok) cout << "Yes";
    else cout << "No";
}