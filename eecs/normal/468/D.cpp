#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, rt, sz[maxn], bel[maxn], in[maxn], out[maxn];
vector<array<int, 2>> G[maxn];
set<int> S[maxn];
set<pair<int, int>> all, cand;

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({v, w}), G[v].push_back({u, w});
    }
    long long sum = 0;
    function<void(int, int)> init = [&](int u, int fa) {
        sz[u] = 1;
        int mx = 0;
        for (auto &e : G[u]) if (e[0] ^ fa) {
            init(e[0], u), sz[u] += sz[e[0]];
            sum += 2LL * e[1] * min(sz[e[0]], n - sz[e[0]]);
            mx = max(mx, sz[e[0]]);
        }
        if (max(mx, n - sz[u]) <= n / 2) rt = u;
    };
    init(1, 0), printf("%lld\n", sum);
    for (auto &e : G[rt]) {
        int x = e[0];
        function<void(int, int)> dfs = [&](int u, int fa) {
            S[bel[u] = x].insert(u);
            in[x]++, out[x]++;
            for (auto &e : G[u]) if (e[0] ^ fa) dfs(e[0], u);
        };
        S[x] = {INT_MAX}, dfs(x, rt);
        cand.emplace(in[x] + out[x], x);
        all.emplace(*S[x].begin(), x);
    }
    S[rt] = {rt, INT_MAX}, cand.emplace(0, rt);
    all.emplace(bel[rt] = rt, rt);
    auto del = [&](int x) {
        int y = bel[x];
        cand.erase({in[y] + out[y], y});
        all.erase({x, y}), S[y].erase(x);
        cand.emplace(in[y] + --out[y], y);
        all.emplace(*S[y].begin(), y);
    };
    for (int i = 1; i <= n; i++) {
        int x = bel[i];
        if (cand.rbegin()->first <= n - i || x == cand.rbegin()->second) {
            auto it = all.begin();
            if (x ^ rt && x == it->second) it++;
            printf("%d ", it->first), del(it->first);
        } else {
            int j = *S[cand.rbegin()->second].begin();
            printf("%d ", j), del(j);
        }
        cand.erase({in[x] + out[x], x});
        cand.emplace(--in[x] + out[x], x);
    }
    return 0;
}