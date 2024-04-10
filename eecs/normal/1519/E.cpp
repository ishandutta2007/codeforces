#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, tot, fa[maxn], par[maxn], dep[maxn];
bool vis[maxn];
vector<pair<int, int>> ans, G[maxn], V;
map<pair<long long, long long>, int> mp;
vector<int> id[maxn];

int main() {
    scanf("%d", &n);
    auto get = [&](long long a, long long b, long long c, long long d) {
        a *= d, b *= c;
        long long g = __gcd(a, b);
        a /= g, b /= g;
        if (!mp.count({a, b})) mp[{a, b}] = ++tot;
        return mp[{a, b}];
    };
    for (int i = 1; i <= n; i++) {
        long long a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        int u = get(a + b, b, c, d), v = get(a, b, c + d, d);
        G[u].emplace_back(v, i), G[v].emplace_back(u, i);
    }
    function<void(int)> dfs1 = [&](int v) {
        vis[v] = 1;
        for (auto e : G[v]) if (e.second ^ fa[v]) {
            if (!vis[e.first]) {
                par[e.first] = v, dep[e.first] = dep[v] + 1;
                fa[e.first] = e.second, dfs1(e.first);
            } else if (dep[v] > dep[e.first]) {
                V.push_back(e);
            }
        }
    };
    function<void(int)> dfs2 = [&](int v) {
        for (auto e : G[v]) if (e.second == fa[e.first]) {
            dfs2(e.first);
        }
        if (fa[v]) {
            if (id[v].size() & 1) id[v].push_back(fa[v]);
            else id[par[v]].push_back(fa[v]);
        }
    };
    for (int i = 1; i <= tot; i++) if (!vis[i]) {
        V.clear(), dfs1(i);
        for (auto e : V) id[e.first].push_back(e.second);
        dfs2(i);
    }
    for (int i = 1; i <= tot; i++) {
        for (int j = 0; j + 1 < id[i].size(); j += 2) {
            ans.emplace_back(id[i][j], id[i][j + 1]);
        }
    }
    printf("%d\n", ans.size());
    for (auto p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}