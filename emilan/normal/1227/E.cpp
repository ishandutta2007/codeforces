#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c == 'X';
        }
    }

    vector pre(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i + 1][j + 1] = a[i][j]
                + pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
        }
    }
    auto query = [&](int x1, int y1, int x2, int y2) {
        return pre[x2][y2] - pre[x2][y1] - pre[x1][y2] + pre[x1][y1];
    };

    auto oob = [&](int i, int j) {
        return !(0 <= i && i < n && 0 <= j && j < m);
    };

    auto f = [&](int t) -> vector<vector<bool>> {
        vector src(n, vector<bool>(m));
        for (int i = t; i < n - t; i++) {
            for (int j = t; j < m - t; j++) {
                if (int q = query(i - t, j - t, i + t + 1, j + t + 1);
                        q == (2 * t + 1) * (2 * t + 1)) {
                    src[i][j] = true;
                }
            }
        }

        vector dist(n, vector<int>(m, -1));
        queue<pii> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (src[i][j]) {
                dist[i][j] = 0;
                que.emplace(i, j);
            }
        }
        while (!empty(que)) {
            auto [x, y] = que.front();
            que.pop();
            if (dist[x][y] == t) break;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (!oob(nx, ny) && dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        que.emplace(nx, ny);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != (dist[i][j] != -1)) {
                    return {};
                }
            }
        }

        return src;
    };

    int l = 0, r = (min(n, m) - 1) / 2 + 1;
    while (l + 1 < r) {
        int mi = (l + r) / 2;
        if (!empty(f(mi))) l = mi;
        else r = mi;
    }

    cout << l << '\n';
    auto src = f(l);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ".X"[src[i][j]];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}