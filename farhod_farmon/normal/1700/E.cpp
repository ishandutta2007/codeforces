#include "bits/stdc++.h"

using namespace std;

const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);

    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<bool>> used(n, vector<bool> (m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    function<bool(int, int)> ok = [&](int i, int j) -> bool {
        if (a[i][j] == 1) {
            return true;
        }
        for (int h = 0; h < 4; h++) {
            const int ni = i + dx[h];
            const int nj = j + dy[h];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                continue;
            } else if (a[ni][nj] < a[i][j]) {
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ok(i, j)) {
                continue;
            }
            for (int h = 0; h < 4; h++) {
                const int ni = i + dx[h];
                const int nj = j + dy[h];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                    continue;
                } else {
                    used[ni][nj] = true;
                }
            }
            used[i][j] = true;
        }
    }
    vector<pair<int, int>> can;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j]) {
                can.push_back({i, j});
            }
        }
    }
    if (can.size() > 12) {
        cout << 2 << "\n";
        return 0;
    } else if (can.empty()) {
        cout << 0 << "\n";
        return 0;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (const auto p : can) {
                if (p == make_pair(i, j)) {
                    continue;
                } else if (used[i][j] && p < make_pair(i, j)) {
                    continue;
                }
                swap(a[i][j], a[p.first][p.second]);
                bool good = ok(i, j);
                for (const auto g : can) {
                    if (!ok(g.first, g.second)) {
                        good = false;
                        break;
                    }
                }
                for (int h = 0; h < 4; h++) {
                    const int ni = i + dx[h];
                    const int nj = j + dy[h];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m || used[ni][nj]) {
                        continue;
                    } else if (!ok(ni, nj)){
                        good = false;
                        break;
                    }
                }
                for (int h = 0; h < 4; h++) {
                    const int ni = p.first + dx[h];
                    const int nj = p.second + dy[h];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m || used[ni][nj]) {
                        continue;
                    } else if (!ok(ni, nj)){
                        good = false;
                        break;
                    }
                }
                if (good) {
                    res += 1;
                }
                swap(a[i][j], a[p.first][p.second]);
            }
        }
    }
    if (res) {
        cout << 1 << " " << res << "\n";
    } else {
        cout << 2 << "\n";
    }
}