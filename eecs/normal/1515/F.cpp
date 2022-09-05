#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010;
int n, m, X, fa[maxn];
ll a[maxn];
vector<pair<int, int>> G[maxn];
priority_queue<pair<ll, int>> Q;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d %d", &n, &m, &X);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    if (accumulate(a + 1, a + n + 1, 0LL) < 1LL * (n - 1) * X) {
        puts("NO"), exit(0);
    }
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v, i), G[v].emplace_back(u, i);
    }
    puts("YES"), iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        Q.emplace(a[i], i);
    }
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();
        int v = p.second;
        if (v != find(v)) continue;
        while (!G[v].empty() && v == find(G[v].back().first)) G[v].pop_back();
        if (G[v].empty()) break;
        printf("%d\n", G[v].back().second);
        int u = find(G[v].back().first);
        fa[u] = v, Q.emplace(a[v] += a[u] - X, v);
        if (G[v].size() < G[u].size()) swap(G[u], G[v]);
        for (auto &p : G[u]) G[v].push_back(p);
    }
    return 0;
}