#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 250010;
int n, K, fa[maxn], mark[maxn], low[maxn], ew[maxn];
ll f[maxn], g[maxn], sum[maxn];
vector<pair<int, int>> G[maxn], H[maxn];
vector<ll> ans, pre[maxn];
unordered_map<int, int> mp[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0, u, v, w; i < n - 1; i++) {
        scanf("%d %d %d", &u, &v, &w), u--, v--;
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    function<void(int)> init = [&](int v) {
        for (auto e : G[v]) if (e.first ^ fa[v]) {
            fa[e.first] = v, ew[e.first] = e.second, init(e.first);
            sum[v] += e.second;
        }
    };
    init(0);
    vector<int> id;
    for (int i = 0; i < n; i++) {
        id.push_back(i);
        sort(G[i].begin(), G[i].end(), [&](pair<int, int> p1, pair<int, int> p2) { return p1.second > p2.second; });
        for (int j = 0; j < G[i].size(); j++) {
            pre[i].push_back((pre[i].empty() ? 0 : pre[i].back()) - G[i][j].second);
            mp[i][G[i][j].first] = j;
        }
    }
    sort(id.begin(), id.end(), [&](int x, int y) { return G[x].size() > G[y].size(); });
    memset(mark, -1, sizeof(mark));
    function<void(int)> dfs = [&](int v) {
        f[v] = ew[v] + sum[v], g[v] = sum[v];
        vector<ll> V;
        vector<int> pos;
        if (v) pos.push_back(mp[v][fa[v]]);
        for (auto e : H[v]) {
            dfs(e.first);
            f[v] += f[e.first] - e.second, g[v] += f[e.first] - e.second;
            V.push_back(min(0LL, g[e.first] - f[e.first]));
            pos.push_back(mp[v][e.first]);
        }
        sort(V.begin(), V.end());
        sort(pos.begin(), pos.end());
        for (int i = 0, j = 0, k = 0; k < K; ) {
            int cur = lower_bound(pos.begin(), pos.end(), j) - pos.begin();
            while (j < G[v].size() && cur < pos.size() && pos[cur] == j) cur++, j++;
            if (i == V.size() && j == G[v].size()) break;
            if (i < V.size() && (j == G[v].size() || V[i] < -G[v][j].second)) {
                f[v] += V[i], i++, k++;
            } else {
                int lim = min(cur == pos.size() ? (int)G[v].size() - 1 : (pos[cur] - 1), j + K - 1 - k);
                int l = j, r = lim, foo = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (i == V.size() || -G[v][mid].second <= V[i]) l = (foo = mid) + 1;
                    else r = mid - 1;
                }
                assert(~foo);
                f[v] += pre[v][foo];
                if (j) f[v] -= pre[v][j - 1];
                k += foo - j + 1, j = foo + 1;
            }
        }
        for (int i = 0, j = 0, k = 0; k < K - 1; ) {
            int cur = lower_bound(pos.begin(), pos.end(), j) - pos.begin();
            while (j < G[v].size() && cur < pos.size() && pos[cur] == j) cur++, j++;
            if (i == V.size() && j == G[v].size()) break;
            if (i < V.size() && (j == G[v].size() || V[i] < -G[v][j].second)) {
                g[v] += V[i], i++, k++;
            } else {
                int lim = min(cur == pos.size() ? (int)G[v].size() - 1 : (pos[cur] - 1), j + K - 2 - k);
                int l = j, r = lim, foo = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (i == V.size() || -G[v][mid].second <= V[i]) l = (foo = mid) + 1;
                    else r = mid - 1;
                }
                assert(~foo);
                g[v] += pre[v][foo];
                if (j) g[v] -= pre[v][j - 1];
                k += foo - j + 1, j = foo + 1;
            }
        }
    };
    auto solve = [&](int p) {
        for (int i = 0; i < p; i++) {
            mark[id[i]] = i, low[id[i]] = 1, H[id[i]].clear();
        }
        for (int i = 0; i < p; i++) if (id[i] && ~mark[fa[id[i]]]) {
            low[id[i]] = 0, H[fa[id[i]]].emplace_back(id[i], ew[id[i]]);
        }
        ll ans = 0;
        for (int i = 0; i < p; i++) {
            if (low[id[i]]) dfs(id[i]), ans += min(f[id[i]], g[id[i]]);
        }
        for (int i = 0; i < p; i++) {
            mark[id[i]] = -1;
        }
        return ans;
    };
    for (int k = n - 1, p = 0; ~k; k--) {
        for (; p < id.size() && G[id[p]].size() > k; p++);
        if (!p) { ans.push_back(0); continue; }
        K = k, ans.push_back(solve(p));
    }
    reverse(ans.begin(), ans.end());
    for (ll x : ans) printf("%lld ", x);
    return 0;
}