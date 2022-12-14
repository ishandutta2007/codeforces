#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

enum Color {
    kUnvis,
    kBad,
    kGood,
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector grid(n + 2, vector<char>(m + 2, '#'));
    REP1(i, n) REP1(j, m) cin >> grid[i][j];

    vector color(n + 2, vector(m + 2, array<int, 4>()));
    auto dfs = [&](auto &self, int x, int y, int d) -> void {
        if (grid[x][y] == 'L') {
            color[x][y][d] = kGood;
            return;
        }

        color[x][y][d] = kBad;

        bool ok = true;
        int ways = 0;
        auto nxt = {tuple
            {x, y - 1, 0},
            {x, y + 1, 1},
            {x - 1, y, 2},
            {x + 1, y, 3},
        };
        for (auto [nx, ny, nd] : nxt) {
            if ((nd ^ 1) != d && grid[nx][ny] != '#') {
                ways++;
                if (color[nx][ny][nd] == kUnvis) self(self, nx, ny, nd);
                if (color[nx][ny][nd] == kBad) ok = false;
            }
        }
        if (ok && ways > 0) {
            color[x][y][d] = kGood;
            grid[x][y] = '+';
        }
    };
    REP1(i, n) REP1(j, m) REP(d, 4) {
        if (grid[i][j] != '#' && color[i][j][d] == kUnvis) {
            dfs(dfs, i, j, d);
        }
    }

    REP1(i, n) {
        REP1(j, m) cout << grid[i][j];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}