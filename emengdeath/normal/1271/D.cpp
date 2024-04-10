#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e4 + 10;
int a[N], b[N], c[N], w[N], to[N];
int f[5011][N];
vector<int>g[5011];
int n, m, k;
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        to[i]= i;
    }
    while(m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        to[y] = max(to[y], x);
    }
    for (int i = 1; i < n; i ++) {
        if (k < a[i]) {
            printf("-1\n");
            return 0;
        }
        k += b[i];
        w[i] = k - a[i + 1];
    }
    if (k < a[n]) {
        printf("-1\n");
        return 0;
    }
    w[n] = k + b[n];
    w[n + 1] = N - 1;
    for (int i = n - 1; i >= 1;i --)
        w[i] = min(w[i], w[i  + 1]);
    for (int i = 1;i  <= n; i ++) {
        g[to[i]].push_back(i);
    }
    for (int i = n; i >= 1; i --) {
        sort(g[i].begin(), g[i].end(), [](int x, int y) {
            return c[x] > c[y];
        });
        int all = 0, cnt = 0;
        for (int j = 0; j <= w[i + 1] ; j ++)
            f[i][min(j, w[i])] = max(f[i + 1][j], f[i][min(j, w[i])]);
        for (auto u:g[i]) {
            all += c[u];
            ++cnt;
            for (int j = 0; j <= w[i + 1]; j++) {
                int x = min(w[i], j);
                if (x < cnt) continue;
                f[i][x - cnt] = max(f[i][x - cnt], f[i + 1][j] + all);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w[1] ; i++)
        ans = max(ans, f[1][i]);
    printf("%d\n", ans);
    return 0;
}