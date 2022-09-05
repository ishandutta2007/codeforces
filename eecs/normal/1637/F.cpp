#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, h[maxn], d[maxn];
set<int> V, G[maxn], cand[maxn];
set<pair<int, int>> leaf;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]), V.insert(i);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        d[u]++, d[v]++;
        G[u].insert(v), G[v].insert(u);
    }
    auto ins = [&](int x) {
        if (d[x] == 1) leaf.emplace(h[x], x);
    };
    for (int i = 1; i <= n; i++) {
        ins(i);
    }
    function<ll()> solve = [&]() {
        if (V.size() == 2) return 2LL * max(h[*V.begin()], h[*V.rbegin()]);
        int u = leaf.begin()->second, v = *G[u].begin();
        leaf.erase(leaf.begin());
        G[u].erase(v), G[v].erase(u);
        d[u]--, d[v]--, V.erase(u);
        if (d[v] == 1) h[v] = max(h[v], h[u]);
        ins(v);
        if (d[v] == 1) return solve();
        return solve() + h[u];
    };
    printf("%lld\n", solve());
    return 0;
}