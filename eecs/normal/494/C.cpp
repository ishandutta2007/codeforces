#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, double> T;
const int maxn = 100010, maxq = 5010, V = 5000;
int n, q, a[maxn], sz[maxq], range[maxn];
T p[maxq];
double ans, f[maxq][maxq << 1], g[maxq << 1], h[maxq << 1];
vector<int> G[maxq];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int mx = *max_element(a + 1, a + n + 1);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %lf", &get<0>(p[i]), &get<1>(p[i]), &get<2>(p[i]));
    }
    p[++q] = make_tuple(1, n, 0);
    sort(p + 1, p + q + 1, [&](T x, T y) {
        return get<1>(x) - get<0>(x) > get<1>(y) - get<0>(y);
    });
    for (int i = 2; i <= q; i++) {
        for (int j = i - 1; j; j--) {
            if (get<0>(p[j]) <= get<0>(p[i]) && get<1>(p[j]) >= get<1>(p[i])) {
                G[j].push_back(i); break;
            }
        }
    }
    function<void(int)> dfs = [&](int v) {
        if (G[v].empty()) {
            range[v] = max(-q, *max_element(a + get<0>(p[v]), a + get<1>(p[v]) + 1) - mx);
            f[v][range[v] + V] = 1 - get<2>(p[v]);
            f[v][range[v] + V + 1] = get<2>(p[v]), sz[v] = 1; return;
        }
        for (int u : G[v]) dfs(u);
        sz[v] = 1, range[v] = -q;
        memset(h, 0, sizeof(h)), h[V - q] = 1;
        for (int u : G[v]) {
            memset(g, 0, sizeof(g));
            for (int i = range[v] + V; i <= range[v] + sz[v] + V; i++) {
                for (int j = range[u] + V; j <= range[u] + sz[u] + V; j++) {
                    g[max(i, j)] += h[i] * f[u][j];
                }
            }
            swap(g, h), sz[v] += sz[u];
            range[v] = max(range[v], range[u]);
        }
        int o = range[v];
        range[v] = max(-q, *max_element(a + get<0>(p[v]), a + get<1>(p[v]) + 1) - mx);
        memset(g, 0, sizeof(g));
        for (int i = o + V; i <= o + sz[v] + V; i++) {
            g[max(i, range[v] + V)] += h[i];
        }
        swap(g, h);
        for (int t : {0, 1}) {
            for (int i = range[v] + V; i <= range[v] + sz[v] + V; i++) {
                f[v][i + t] += h[i] * (t ? get<2>(p[v]) : 1 - get<2>(p[v]));
            }
        }
    };
    dfs(1);
    for (int i = 0; i <= q; i++) {
        ans += (mx + i) * f[1][V + i];
    }
    printf("%.9f\n", ans);
    return 0;
}