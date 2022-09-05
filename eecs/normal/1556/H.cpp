#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int n, K, lim[maxn], d[maxn], fa[maxn];
int ans, cur, u[maxn], v[maxn], w[maxn][maxn];
mt19937 rnd(time(0));

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &lim[i]);
    }
    double st = clock();
    fill(lim + K + 1, lim + n + 1, n - 1);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            scanf("%d", &w[i][j]), w[j][i] = w[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        u[i] = i, v[i] = n;
        d[i]++, d[n]++, cur += w[i][n];
    }
    ans = cur;
    while ((clock() - st) / CLOCKS_PER_SEC < 1) {
        int id = rnd() % (n - 1) + 1;
        iota(fa + 1, fa + n + 1, 1);
        for (int i = 1; i < n; i++) if (i ^ id) {
            fa[find(u[i])] = find(v[i]);
        }
        d[u[id]]--, d[v[id]]--;
        int x, y;
        do {
            x = rnd() % n + 1, y = rnd() % n + 1;
        } while (find(x) == find(y) || d[x] == lim[x] || d[y] == lim[y]);
        int _cur = cur - w[u[id]][v[id]] + w[x][y];
        if (_cur < cur || !(rnd() % 1000)) {
            d[u[id] = x]++, d[v[id] = y]++;
            cur = _cur, ans = min(ans, _cur);
        } else {
            d[u[id]]++, d[v[id]]++;
        }
    }
    printf("%d\n", ans);
    return 0;
}