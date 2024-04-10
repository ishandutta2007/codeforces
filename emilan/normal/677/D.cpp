#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

bool sort_snd(const pii &x, const pii &y) {
    return x.second < y.second;
}

void solve() {
    int n, m, k_max;
    cin >> n >> m >> k_max;
    vector a(n, vector<int>(m));
    for (auto &v : a) {
        for (auto &x : v) cin >> x;
    }

    vector<vector<pii>> pos(k_max + 1);
    pos[0] = {{0, 0}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pos[ a[i][j] ].emplace_back(i, j);
        }
    }

    vector dist(n, vector<int>(m, INT_MAX));
    for (int k = 0; k < k_max; k++) {
        vector<int> idxes(n);
        vector<vector<int>> rows_nxt(n);
        for (auto [i, j] : pos[k + 1]) {
            rows_nxt[i].push_back(j);
        }

        sort(ALL(pos[k]), sort_snd);

        for (auto [i, j] : pos[k]) {
            int d = k > 0 ? dist[i][j] : 0;
            if (d == INT_MAX) continue;

            for (int ni = 0; ni < n; ni++) {
                while (idxes[ni] < SZ(rows_nxt[ni])
                        && j > rows_nxt[ni][ idxes[ni] ]) {
                    idxes[ni]++;
                }

                if (idxes[ni] > 0) {
                    int nj = rows_nxt[ni][idxes[ni] - 1];
                    dist[ni][nj] = min(
                        dist[ni][nj],
                        d + abs(ni - i) + abs(nj - j)
                    );
                }
                if (idxes[ni] < SZ(rows_nxt[ni])) {
                    int nj = rows_nxt[ni][ idxes[ni] ];
                    dist[ni][nj] = min(
                        dist[ni][nj],
                        d + abs(ni - i) + abs(nj - j)
                    );
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (a[i][j] == k_max) {
            cout << dist[i][j] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}