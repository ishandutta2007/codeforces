#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, q, dep[maxn], fa[maxn][20];
vector<int> G[maxn], H[maxn], cand[maxn][20];

vector<int> comb(vector<int> &V1, vector<int> &V2) {
    vector<int> V;
    int i = 0, j = 0;
    while (i < V1.size() && j < V2.size() && V.size() < 10) {
        if (V1[i] < V2[j]) V.push_back(V1[i++]);
        else V.push_back(V2[j++]);
    }
    while (i < V1.size() && V.size() < 10) V.push_back(V1[i++]);
    while (j < V2.size() && V.size() < 10) V.push_back(V2[j++]);
    return V;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1, c; i <= m; i++) {
        scanf("%d", &c), H[c].push_back(i);
    }
    function<void(int, int)> dfs = [&](int v, int f) {
        fa[v][0] = f, dep[v] = dep[f] + 1;
        cand[v][0] = H[v];
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
            cand[v][i] = comb(cand[v][i - 1], cand[fa[v][i - 1]][i - 1]);
        }
        for (int u : G[v]) if (u ^ f) dfs(u, v);
    };
    dfs(1, 0);
    while (q--) {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);
        if (dep[u] < dep[v]) swap(u, v);
        vector<int> ans;
        for (int i = 19; ~i; i--) if (dep[fa[u][i]] >= dep[v]) {
            ans = comb(ans, cand[u][i]), u = fa[u][i];
        }
        if (u ^ v) {
            for (int i = 19; ~i; i--) if (fa[u][i] ^ fa[v][i]) {
                ans = comb(ans, cand[u][i]);
                ans = comb(ans, cand[v][i]);
                u = fa[u][i], v = fa[v][i];
            }
            ans = comb(ans, H[u]), ans = comb(ans, H[v]), u = fa[u][0];
        }
        ans = comb(ans, H[u]);
        int a = min(k, (int)ans.size());
        printf("%d", a);
        for (int i = 0; i < a; i++) printf(" %d", ans[i]);
        putchar('\n');
    }
    return 0;
}