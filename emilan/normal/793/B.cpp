#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n + 2, vector<char>(m + 2, '*'));
    int sx, sy, tx, ty;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            cin >> a[x][y];
            if (a[x][y] == 'S') sx = x, sy = y;
            if (a[x][y] == 'T') tx = x, ty = y;
        }
    }

    vector dist(n + 2, vector(m + 2, array{3, 3, 3, 3}));
    deque<array<int, 3>> dq;
    for (int i = 0; i < 4; i++) {
        dist[sx][sy][i] = 0;
        dq.push_back({sx, sy, i});
    }
    while (!empty(dq)) {
        auto [x, y, i] = dq.front();
        dq.pop_front();

        int d = dist[x][y][i];
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (a[nx][ny] == '*') continue;

            if (j == i) {
                if (d < dist[nx][ny][j]) {
                    dist[nx][ny][j] = d;
                    dq.push_front({nx, ny, j});
                }
            } else if (d < 2) {
                if (d + 1 < dist[nx][ny][j]) {
                    dist[nx][ny][j] = d + 1;
                    dq.push_back({nx, ny, j});
                }
            }
        }
    }

    if (*min_element(ALL(dist[tx][ty])) == 3) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}