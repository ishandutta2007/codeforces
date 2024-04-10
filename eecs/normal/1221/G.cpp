#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m, fa[40], col[40], adj[40], _adj[40], f[1 << 20];
bool vis[40];
vector<int> G[40];
vector<array<int, 2>> E;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d %d", &u, &v);
        if (--u > --v) swap(u, v);
        E.push_back({u, v});
    }
    auto solve1 = [&]() { // 0 or 2
        iota(fa, fa + n, 0);
        for (auto &e : E) {
            fa[find(e[0])] = find(e[1]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i == find(i)) cnt++;
        }
        return 1LL << cnt;
    };
    auto solve2 = [&]() { // 0 or 1
        int m = n / 2;
        for (auto &e : E) {
            if (e[1] < m) adj[e[0]] |= 1 << e[1];
            else if (e[0] >= m) adj[e[0]] |= 1 << (e[1] - m);
            else _adj[e[0]] |= 1 << (e[1] - m);
        }
        for (int S = 0; S < 1 << (n - m); S++) {
            bool flag = 1;
            for (int i = 0; i < n - m; i++) if (S >> i & 1) {
                if (S & adj[i + m]) flag = 0;
            }
            if (flag) f[S]++;
        }
        for (int i = 0; i < n - m; i++) {
            for (int S = 0; S < 1 << (n - m); S++) {
                if (S >> i & 1) f[S] += f[S ^ (1 << i)];
            }
        }
        ll ans = 0;
        for (int S = 0; S < 1 << m; S++) {
            bool flag = 1;
            int T = (1 << (n - m)) - 1;
            for (int i = 0; i < m; i++) if (S >> i & 1) {
                if (S & adj[i]) flag = 0;
                T &= ~_adj[i];
            }
            if (flag) ans += f[T];
        }
        return ans;
    };
    auto solve3 = [&]() { // 0
        memset(vis, 0, sizeof(vis));
        for (auto &e : E) {
            vis[e[0]] = vis[e[1]] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) cnt++;
        }
        return 1LL << cnt;
    };
    auto solve4 = [&]() { // 1
        for (auto &e : E) {
            G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
        }
        memset(vis, 0, sizeof(vis));
        bool flag = 1;
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for (int v : G[u]) {
                if (!vis[v]) col[v] = !col[u], dfs(v);
                if (col[u] == col[v]) flag = 0;
            }
        };
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        return !flag ? 0 : solve1();
    };
    ll ans = (1LL << n) - solve1() - 2 * solve2();
    ans += 2 * solve3() + solve4();
    if (!m) ans -= 1LL << n;
    printf("%lld\n", ans);
    return 0;
}