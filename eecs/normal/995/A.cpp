#include <bits/stdc++.h>
using namespace std;

int n, K, a[4][50];
vector<tuple<int, int, int>> ans;

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    }
    if (K == 2 * n) {
        for (int i = 0; i < n; i++) {
            if (a[0][i] == a[1][i]) {
                ans.emplace_back(a[0][i], 0, i), a[0][i] = a[1][i] = 0; goto nxt;
            } else if (a[2][i] == a[3][i]) {
                ans.emplace_back(a[2][i], 3, i), a[2][i] = a[3][i] = 0; goto nxt;
            }
        }
        puts("-1"), exit(0);
        nxt:; K--;
    }
    while (K--) {
        int sx = -1, sy;
        for (int i = 0; i < n; i++) {
            if (a[1][i] && !a[2][i]) { sx = 1, sy = i; break; }
            if (a[2][i] && !a[1][i]) { sx = 2, sy = i; break; }
        }
        if (!~sx) {
            for (int i = 0; i < n; i++) {
                if (i < n - 1 && a[1][i] && !a[1][i + 1]) {
                    ans.emplace_back(a[1][i], 1, i + 1), swap(a[1][i], a[1][i + 1]);
                    sx = 1, sy = i + 1; break;
                }
                if (i && a[1][i] && !a[1][i - 1]) {
                    ans.emplace_back(a[1][i], 1, i - 1), swap(a[1][i], a[1][i - 1]);
                    sx = 1, sy = i - 1; break;
                }
            }
        }
        int tx, ty;
        for (int i = 0; i < n; i++) {
            if (a[0][i] == a[sx][sy]) { tx = 1, ty = i; break; }
            if (a[3][i] == a[sx][sy]) { tx = 2, ty = i; break; }
        }
        while (sy ^ ty) {
            int y = sy < ty ? sy + 1 : (sy - 1);
            if (a[3 - sx][y]) ans.emplace_back(a[3 - sx][y], 3 - sx, sy);
            swap(a[3 - sx][sy], a[3 - sx][y]);
            if (a[sx][y]) ans.emplace_back(a[sx][y], 3 - sx, y);
            swap(a[sx][y], a[3 - sx][y]);
            ans.emplace_back(a[sx][sy], sx, y);
            swap(a[sx][sy], a[sx][y]);
            if (a[3 - sx][sy]) ans.emplace_back(a[3 - sx][sy], sx, sy);
            swap(a[3 - sx][sy], a[sx][sy]);
            if (a[3 - sx][y]) ans.emplace_back(a[3 - sx][y], 3 - sx, sy);
            swap(a[3 - sx][y], a[3 - sx][sy]);
            sy = y;
        }
        if (sx ^ tx) {
            ans.emplace_back(a[sx][sy], tx, ty), swap(a[sx][sy], a[tx][ty]);
        }
        if (tx == 1) {
            ans.emplace_back(a[tx][ty], 0, ty), a[tx][ty] = a[0][ty] = 0;
        } else {
            ans.emplace_back(a[tx][ty], 3, ty), a[tx][ty] = a[3][ty] = 0;
        }
    }
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d %d %d\n", get<0>(p), get<1>(p) + 1, get<2>(p) + 1);
    }
    return 0;
}