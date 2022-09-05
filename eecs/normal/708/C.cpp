#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, mx[maxn], sec[maxn], fa[maxn], sz[maxn];
vector<int> G[maxn];
multiset<int> S;
bool ans[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs1 = [&](int v) {
        sz[v] = 1;
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dfs1(u), sz[v] += sz[u];
            if (mx[u] > mx[v]) sec[v] = max(mx[v], sec[u]), mx[v] = mx[u];
            else sec[v] = max(sec[v], mx[u]);
            if (sz[u] * 2 > n) continue;
            if (sz[u] > mx[v]) sec[v] = mx[v], mx[v] = sz[u];
            else sec[v] = max(sec[v], sz[u]);
        }
    };
    function<void(int)> dfs2 = [&](int v) {
        int max_sz = 0;
        for (int u : G[v]) if (u ^ fa[v]) {
            max_sz = max(max_sz, sz[u]);
        }
        if (max(max_sz, n - sz[v]) * 2 <= n) {
            ans[v] = 1;
        } else if (max_sz * 2 > n) {
            for (int u : G[v]) if (u ^ fa[v] && sz[u] * 2 > n) {
                if ((sz[u] - mx[u]) * 2 <= n) ans[v] = 1;
            }
        } else if ((n - sz[v]) * 2 > n) {
            if ((n - sz[v] - *S.rbegin()) * 2 <= n) ans[v] = 1;
        }
        vector<int> suf(G[v].size() + 1, 0);
        for (int i = G[v].size() - 1; ~i; i--) {
            suf[i] = suf[i + 1];
            if (G[v][i] != fa[v]) {
                suf[i] = max(suf[i], mx[G[v][i]]);
                if (sz[G[v][i]] * 2 <= n) suf[i] = max(suf[i], sz[G[v][i]]);
            }
        }
        for (int i = 0, j = 0; i < G[v].size(); i++) if (G[v][i] ^ fa[v]) {
            int u = G[v][i];
            int t = max(j, suf[i + 1]);
            if (n - sz[v] <= n / 2) t = max(t, n - sz[v]);
            S.insert(t), dfs2(u), S.erase(S.find(t));
            j = max(j, mx[u]);
            if (sz[u] * 2 <= n) j = max(j, sz[u]);
        }
    };
    dfs1(1), dfs2(1);
    for (int i = 1; i <= n; i++) {
        putchar(ans[i] ? '1' : '0'), putchar(' ');
    }
    return 0;
}