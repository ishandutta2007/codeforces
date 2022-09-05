#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, K, ans[maxn], x[maxn], fa[maxn], tid[maxn], sz[maxn], id[maxn], dep[maxn];
vector<tuple<int, int, int>> E, cand;
vector<int> G[maxn];
set<pair<int, int>> S;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &x[i]), id[x[i]] = i;
    }
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        E.emplace_back(w, u, v);
    }
    sort(E.begin(), E.end());
    iota(fa + 1, fa + n + 1, 1);
    for (auto e : E) if (find(get<1>(e)) ^ find(get<2>(e))) {
        cand.push_back(e);
        fa[find(get<1>(e))] = find(get<2>(e));
        G[get<1>(e)].push_back(get<2>(e));
        G[get<2>(e)].push_back(get<1>(e));
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        static int tim = 0;
        sz[v] = 1, tid[v] = ++tim;
        dep[v] = dep[fa] + 1;
        if (id[v]) S.emplace(tid[v], v);
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v), sz[v] += sz[u];
        }
    };
    dfs(1, 0);
    reverse(cand.begin(), cand.end());
    auto find = [&](int l, int r) {
        auto it = S.lower_bound({l, 0});
        if (it == S.end() || it->first > r) return -1;
        return it->second;
    };
    for (auto e : cand) {
        int u = get<1>(e), v = get<2>(e), w = get<0>(e);
        if (dep[u] > dep[v]) swap(u, v);
        if ((~find(1, tid[v] - 1) || ~find(tid[v] + sz[v], n)) && ~find(tid[v], tid[v] + sz[v] - 1)) {
            fill(ans + 1, ans + K + 1, w); break;
        }
    }
    for (int i = 1; i <= K; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}