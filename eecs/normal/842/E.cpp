#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, d, fa[maxn][20], dep[maxn];
vector<int> V1 = {1}, V2;

int main() {
    scanf("%d", &n);
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; ~i; i--) {
            if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        }
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    };
    auto dist = [&](int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    };
    for (int i = 2; i <= n + 1; i++) {
        scanf("%d", &fa[i][0]);
        dep[i] = dep[fa[i][0]] + 1;
        for (int j = 1; j < 20; j++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
        int d1 = V1.empty() ? 0 : dist(i, V1[0]), d2 = V2.empty() ? 0 : dist(i, V2[0]);
        if (max(d1, d2) == d) {
            (d1 == d ? V2 : V1).push_back(i);
        } else if (max(d1, d2) > d) {
            d++;
            if (d1 >= d2) {
                for (int x : V2) if (dist(x, i) == d) V1.push_back(x);
                V2 = {i};
            } else {
                for (int x : V1) if (dist(x, i) == d) V2.push_back(x);
                V1 = {i};
            }
        }
        printf("%d\n", V1.size() + V2.size());
    }
    return 0;
}