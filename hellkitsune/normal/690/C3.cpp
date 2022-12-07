#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair

int n;
int par[20][200005];
int h[200005];

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) if (h[u] - (1 << i) >= h[v]) {
        u = par[i][u];
    }
    for (int i = 19; i >= 0; --i) if (par[i][u] != -1 && par[i][u] != par[i][v]) {
        u = par[i][u];
        v = par[i][v];
    }
    return par[0][u];
}

int dist(int u, int v) {
    int lc = lca(u, v);
    return h[u] + h[v] - 2 * h[lc];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    par[0][0] = -1;
    int v1 = 0, v2 = 0;
    int diam = 0;
    h[0] = 0;
    for (int i = 1; i < n; ++i) {
        scanf("%d", par[0] + i), --par[0][i];
        for (int j = 0; j < 19; ++j) if (par[j][i] == -1) {
            break;
        } else {
            par[j + 1][i] = par[j][par[j][i]];
        }
        h[i] = h[par[0][i]] + 1;
        if (dist(v1, i) > diam) {
            v2 = i;
            ++diam;
        } else if (dist(v2, i) > diam) {
            v1 = i;
            ++diam;
        }
        printf("%d ", diam);
    }
    printf("\n");
    return 0;
}