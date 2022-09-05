#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, fa[maxn], mark[maxn];
long long d[maxn];
vector<pair<int, int>> G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    function<void(int)> dfs = [&](int v) {
        for (auto e : G[v]) if (e.first ^ fa[v]) {
            d[e.first] = d[v] + e.second;
            fa[e.first] = v, dfs(e.first);
        }
    };
    dfs(1);
    vector<int> V;
    for (int i = n; i; i = fa[i]) {
        mark[i] = 1, V.push_back(i);
    }
    bool flag = 0;
    for (int i = 1; i <= n; i++) if (mark[i]) {
        int sz = 0;
        function<void(int, int)> dfs = [&](int v, int fa) {
            sz++;
            for (auto e : G[v]) {
                if (e.first ^ fa && !mark[e.first]) dfs(e.first, v);
            }
        };
        dfs(i, 0);
        if (sz > 2) flag = 1;
    }
    reverse(V.begin(), V.end());
    long long mx = 0, cur = -1e18;
    int lst = -1;
    for (int v : V) {
        if (~lst) {
            for (auto e : G[lst]) if (!mark[e.first]) {
                cur = max(cur, d[lst] + e.second);
            }
        }
        mx = max(mx, cur + d[n] - d[v]);
        if (~lst) cur = max(cur, d[lst]);
        for (auto e : G[v]) if (!mark[e.first]) {
            mx = max(mx, cur + d[n] - d[v] + e.second);
        }
        lst = v;
    }
    while (m--) {
        int x;
        scanf("%d", &x);
        if (flag) { printf("%lld\n", d[n]); continue; }
        printf("%lld\n", min(d[n], mx + x));
    }
    return 0;
}