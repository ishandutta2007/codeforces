#include <bits/stdc++.h>
using namespace std;

int m, n, a[35], d[65];
bool f[65][2081], g[65][2081], vis[65];
char ans[65][65];
pair<int, int> pre[35][65][2081];

int main() {
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + m + 1), f[0][0] = 1;
    for (int i = 1; i <= m; i++, swap(f, g)) {
        memset(g, 0, sizeof(g));
        for (int j = 1; j < 65; j++) {
            for (int k = 0; j + k < 65; k++) {
                int nk = j + k;
                for (int l = max(0, nk * (nk - 1) / 2 - j * a[i]); l + j * a[i] < 2081; l++) if (f[k][l]) {
                    int nl = l + j * a[i];
                    if (!g[nk][nl]) g[nk][nl] = 1, pre[i][nk][nl] = make_pair(i, j);
                }
            }
        }
    }
    function<void(int, int, int)> print = [&](int x, int k, int id) {
        if (!x) return;
        auto p = pre[id][x][k];
        print(x - p.second, k - a[p.first] * p.second, id - 1);
        while (p.second--) d[++n] = a[p.first];
    };
    for (int i = 1; i < 65; i++) if (f[i][i * (i - 1) / 2]) {
        print(i, i * (i - 1) / 2, m); break;
    }
    if (!n) puts("=("), exit(0);
    printf("%d\n", n);
    for (int $ = 1; $ <= n; $++) {
        vector<int> id;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) id.push_back(i);
        }
        sort(id.begin(), id.end(), [&](int x, int y) { return d[x] > d[y]; });
        int i = id[0], t = n - $ - d[i];
        ans[i][i] = '0', vis[i] = 1;
        for (int j : id) if (i ^ j) {
            if (t) {
                ans[j][i] = '1', ans[i][j] = '0';
                t--, d[j]--;
            } else {
                ans[j][i] = '0', ans[i][j] = '1';
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) putchar(ans[i][j]);
        putchar('\n');
    }
    return 0;
}