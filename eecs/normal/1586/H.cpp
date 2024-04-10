#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, rt, val[maxn], sz[maxn];
bool solved[maxn];
vector<array<int, 3>> G[maxn];
vector<array<int, 2>> Q[maxn];
pair<int, int> ans[maxn];
array<int, 3> fir[maxn], sec[maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }
    for (int i = 1, a, b, c, t; i < n; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &t);
        G[a].push_back({b, c, t}), G[b].push_back({a, c, t});
    }
    for (int i = 1, v, x; i <= q; i++) {
        scanf("%d %d", &v, &x);
        ans[i] = {val[x], 0}, Q[x].push_back({v, i});
    }
    function<void(int, int, int)> find_rt = [&](int v, int fa, int all) {
        sz[v] = 1;
        int mx = 0;
        for (auto &e : G[v]) if (e[0] ^ fa && !solved[e[0]]) {
            find_rt(e[0], v, all), sz[v] += sz[e[0]];
            mx = max(mx, sz[e[0]]);
        }
        if (max(mx, all - sz[v]) <= all / 2) rt = v;
    };
    function<void(int)> solve = [&](int x) {
        solved[x] = 1;
        vector<array<int, 4>> V;
        for (auto &y : G[x]) if (!solved[y[0]]) {
            function<void(int, int, int, int)> dfs = [&](int v, int fa, int mn, int mx) {
                sz[v] = 1, V.push_back({mn, val[v], mx, y[0]});
                for (auto &e : G[v]) if (e[0] ^ fa && !solved[e[0]]) {
                    dfs(e[0], v, min(mn, e[1]), max(mx, e[2])), sz[v] += sz[e[0]];
                }
            };
            dfs(y[0], x, y[1], y[2]);
        }
        sort(V.begin(), V.end());
        if (!V.empty()) fir[V.size() - 1] = {V.back()[1], V.back()[2], V.back()[3]}, sec[V.size() - 1] = {0, 0, 0};
        for (int i = (int)V.size() - 2; i >= 0; i--) {
            array<int, 3> p = {V[i][1], V[i][2], V[i][3]};
            fir[i] = max(fir[i + 1], p), sec[i] = {0, 0, 0};
            if (p[2] ^ fir[i][2]) sec[i] = max(sec[i], p);
            if (fir[i + 1][2] ^ fir[i][2]) sec[i] = max(sec[i], fir[i + 1]);
            if (sec[i + 1][2] ^ fir[i][2]) sec[i] = max(sec[i], sec[i + 1]);
        }
        for (auto &p : Q[x]) {
            int pos = lower_bound(V.begin(), V.end(), array<int, 4>{p[0], 0, 0, 0}) - V.begin();
            if (pos == V.size()) continue;
            ans[p[1]] = max(ans[p[1]], {fir[pos][0], fir[pos][1]});
        }
        for (auto &y : G[x]) if (!solved[y[0]]) {
            function<void(int, int, int, int)> dfs = [&](int v, int fa, int mn, int mx) {
                for (auto &p : Q[v]) if (mn >= p[0]) {
                    pair<int, int> q = {val[x], mx};
                    int pos = lower_bound(V.begin(), V.end(), array<int, 4>{p[0], 0, 0, 0}) - V.begin();
                    if (pos < V.size()) {
                        if (fir[pos][2] == y[0]) q = max(q, {sec[pos][0], sec[pos][1]});
                        else q = max(q, {fir[pos][0], fir[pos][1]});
                    }
                    q.second = max(q.second, mx), ans[p[1]] = max(ans[p[1]], q);
                }
                for (auto &e : G[v]) if (e[0] ^ fa && !solved[e[0]]) {
                    dfs(e[0], v, min(mn, e[1]), max(mx, e[2]));
                }
            };
            dfs(y[0], x, y[1], y[2]);
        }
        for (auto &y : G[x]) if (!solved[y[0]]) {
            find_rt(y[0], x, sz[y[0]]), solve(rt);
        }
    };
    find_rt(1, 0, n), solve(rt);
    for (int i = 1; i <= q; i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}