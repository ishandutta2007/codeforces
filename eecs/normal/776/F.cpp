#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, rt, out[maxn], in[maxn], label[maxn], sz[maxn];
bool solved[maxn];
vector<vector<int>> V;
vector<pair<int, int>> E;
vector<int> id[maxn], _id[maxn], G[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        out[u]++, in[v]++;
    }
    vector<int> st = {1};
    for (int i = 1, tot = 1; i <= n; i++) {
        while (in[i]--) {
            id[st.back()].push_back(i), st.pop_back();
        }
        id[st.back()].push_back(i);
        while (out[i]--) {
            E.emplace_back(st.back(), ++tot);
            id[tot].push_back(i), st.push_back(tot);
        }
    }
    for (int i = 1; i <= m + 1; i++) {
        reverse(id[i].begin(), id[i].end());
    }
    copy(id + 1, id + m + 2, _id + 1);
    sort(id + 1, id + m + 2);
    for (auto &e : E) {
        int u = lower_bound(id + 1, id + m + 2, _id[e.first]) - id;
        int v = lower_bound(id + 1, id + m + 2, _id[e.second]) - id;
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int, int)> find_rt = [&](int v, int fa, int all) {
        sz[v] = 1;
        int mx = 0;
        for (int u : G[v]) if (u ^ fa && !solved[u]) {
            find_rt(u, v, all), sz[v] += sz[u];
            mx = max(mx, sz[u]);
        }
        if (max(mx, all - sz[v]) * 2 <= all) rt = v;
    };
    function<void(int, int)> divide = [&](int x, int dep) {
        label[x] = dep, solved[x] = 1;
        for (int v : G[x]) if (!solved[v]) {
            int all = 0;
            function<void(int, int)> dfs = [&](int v, int fa) {
                all++;
                for (int u : G[v]) if (u ^ fa && !solved[u]) dfs(u, v);
            };
            dfs(v, x), find_rt(v, x, all), divide(rt, dep + 1);
        }
    };
    find_rt(1, 0, m + 1), divide(rt, 1);
    for (int i = 1; i <= m + 1; i++) {
        printf("%d ", label[i]);
    }
    return 0;
}