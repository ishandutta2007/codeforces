#include <bits/stdc++.h>
using namespace std;

int T, n, m, fa[10010];
char s[110][110];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    fa[find(x)] = find(y);
}

int id(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
        }
        iota(fa + 1, fa + n * m + 1, 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) if (s[i][j] == '1') {
                if (i < n && s[i + 1][j] == '1') unite(id(i, j), id(i + 1, j));
                if (j < m && s[i][j + 1] == '1') unite(id(i, j), id(i, j + 1));
            }
        }
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) if (s[i][j] == '1' && id(i, j) == find(id(i, j))) {
                int lx = INT_MAX, rx = 0, ly = INT_MAX, ry = 0, cnt = 0;
                for (int x = 1; x <= n; x++) for (int y = 1; y <= m; y++) {
                    if (find(id(x, y)) == id(i, j)) {
                        lx = min(lx, x), rx = max(rx, x);
                        ly = min(ly, y), ry = max(ry, y), cnt++;
                    }
                }
                flag &= cnt == (rx - lx + 1) * (ry - ly + 1);
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}