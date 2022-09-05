#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, s, d, bel[maxn], a[maxn], ans[maxn];
int L[maxn], R[maxn], pre[maxn], nxt[maxn];
pair<int, int> mn[maxn];
vector<pair<int, int>> G[maxn];

int find(int x) {
    return x == bel[x] ? x : bel[x] = find(bel[x]);
}

void chk(pair<int, int> &a, pair<int, int> b) {
    if (a > b) a = b;
}

int main() {
    scanf("%d %d %d %d", &n, &q, &s, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    iota(bel + 1, bel + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        L[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
        R[i] = lower_bound(a + 1, a + n + 1, a[i] + d) - a;
    }
    for (int C = n; C > 1; ) {
        memset(mn, 0x3f, sizeof(mn));
        for (int i = 1; i <= n; i++) {
            if (i > 1 && find(i) == find(i - 1)) pre[i] = pre[i - 1];
            else pre[i] = i - 1;
        }
        for (int i = n; i; i--) {
            if (i < n && find(i) == find(i + 1)) nxt[i] = nxt[i + 1];
            else nxt[i] = i + 1;
        }
        for (int i = 1; i <= n; i++) {
            int o = find(i);
            for (int j : {L[i] - 1, L[i], R[i] - 1, R[i]}) if (j && j <= n) {
                if (o ^ find(j)) chk(mn[o], {abs(d - abs(a[i] - a[j])), j});
                if (pre[j] && o ^ find(pre[j])) chk(mn[o], {abs(d - abs(a[i] - a[pre[j]])), pre[j]});
                if (nxt[j] <= n && o ^ find(nxt[j])) chk(mn[o], {abs(d - abs(a[i] - a[nxt[j]])), nxt[j]});
            }
        }
        auto unite = [&](int x, int y, int v) {
            x = find(x), y = find(y);
            if (x == y) return;
            C--, bel[x] = y;
            G[x].emplace_back(y, v), G[y].emplace_back(x, v);
        };
        for (int i = 1; i <= n; i++) {
            if (mn[i].first < 1e9) unite(i, mn[i].second, mn[i].first);
        }
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        for (auto e : G[v]) if (e.first ^ fa) {
            ans[e.first] = max(ans[v], e.second), dfs(e.first, v);
        }
    };
    dfs(s, 0);
    while (q--) {
        int i, k;
        scanf("%d %d", &i, &k);
        puts(ans[i] <= k ? "Yes" : "No");
    }
    return 0;
}