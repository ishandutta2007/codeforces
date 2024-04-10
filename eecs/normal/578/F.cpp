#include <bits/stdc++.h>
using namespace std;

const int maxn = 410, maxV = maxn * maxn;
int n, m, P, ans, a[maxn][maxn], e[maxn][maxn], fa[maxV], mp[maxV];
char s[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int id(int x, int y) { return (x - 1) * m + y; }
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) puts("0"), exit(0);
    fa[u] = v;
}

int main() {
    scanf("%d %d %d", &n, &m, &P);
    n++, m++;
    iota(fa + 1, fa + n * m + 1, 1);
    for (int i = 1; i < n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j < m; j++) {
            if (s[j] == '/') unite(id(i, j + 1), id(i + 1, j));
            if (s[j] == '\\') unite(id(i, j), id(i + 1, j + 1));
            if (s[j] == '*') e[i][j] = 1;
        }
    }
    auto add_edge = [&](int u, int v) {
        ++a[u][u] %= P, ++a[v][v] %= P;
        (a[u][v] += P - 1) %= P, (a[v][u] += P - 1) %= P;
    };
    auto solve = [&](int parity) {
        memset(a, 0, sizeof(a));
        memset(mp, 0, sizeof(mp));
        int V = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int k = id(i, j);
                if (k == find(k) && (i + j) % 2 == parity) mp[k] = ++V;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) if (e[i][j]) {
                add_edge(mp[find(id(i, j + 1))], mp[find(id(i + 1, j))]);
                add_edge(mp[find(id(i, j))], mp[find(id(i + 1, j + 1))]);
            }
        }
        int p = 1;
        for (int i = 1; i < V; i++) {
            for (int j = i + 1; j < V; j++) if (a[j][i]) {
                swap(a[i], a[j]), p = P - p; break;
            }
            p = 1LL * p * a[i][i] % P;
            int inv = qp(a[i][i], P - 2);
            for (int j = i + 1; j < V; j++) if (a[j][i]) {
                int t = P - 1LL * a[j][i] * inv % P;
                for (int k = i; k < V; k++) {
                    a[j][k] = (a[j][k] + 1LL * t * a[i][k]) % P;
                }
            }
        }
        (ans += p) %= P;
    };
    solve(0), solve(1);
    printf("%d\n", ans);
    return 0;
}