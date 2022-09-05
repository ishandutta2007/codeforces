#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, maxq = 2000010;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int n, m, q, a[310][310], ans[maxq];
vector<array<int, 3>> inv[maxq];

struct DSU {
    int fa[maxn];
    void init() { iota(fa + 1, fa + n * m + 1, 1); }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x ^ y) return fa[x] = y, 1;
        return 0;
    }
} T;

int id(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    int cur = 0;
    ans[0] = n * m - 1;
    for (int i = 1, x, y, c; i <= q; i++) {
        scanf("%d %d %d", &x, &y, &c);
        if (c > cur) cur = c, T.init();
        if (a[x][y] ^ c) inv[a[x][y]].push_back({i, x, y}), a[x][y] = c;
        for (int k = 0; k < 4; k++) {
            int p = x + dx[k], q = y + dy[k];
            if (!p || p > n || !q || q > m) continue;
            if (a[p][q] == c && T.unite(id(x, y), id(p, q))) ans[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            inv[a[i][j]].push_back({-1, i, j});
        }
    }
    for (int i = 0; i <= cur; i++) {
        T.init(), reverse(inv[i].begin(), inv[i].end());
        for (auto &p : inv[i]) {
            for (int k = 0; k < 4; k++) {
                int x = p[1] + dx[k], y = p[2] + dy[k];
                if (!x || x > n || !y || y > m) continue;
                if (a[x][y] == i && T.unite(id(p[1], p[2]), id(x, y))) ans[p[0]]--;
            }
            a[p[1]][p[2]] = i;
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", n * m - (ans[i] += ans[i - 1]));
    }
    return 0;
}