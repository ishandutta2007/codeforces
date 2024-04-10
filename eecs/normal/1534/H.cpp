#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, lim, rt, tim, f[maxn], lb[maxn], rb[maxn], tid[maxn], sz[maxn];
vector<int> ans, G[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        cout << "! 1 1" << endl, exit(0);
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    auto calc = [&](int v, int fa = 0) {
        vector<int> V;
        for (int u : G[v]) if (u ^ fa) {
            V.push_back(f[u]);
        }
        sort(V.begin(), V.end(), greater<int>()), f[v] = 1;
        for (int i = 0; i < V.size(); i++) {
            f[v] = max(f[v], V[i] + i);
        }
    };
    function<void(int, int)> dfs1 = [&](int v, int fa) {
        tid[v] = ++tim, sz[v] = 1;
        vector<int> V;
        for (int u : G[v]) if (u ^ fa) {
            dfs1(u, v), V.push_back(f[u]);
            sz[v] += sz[u];
        }
        calc(v, fa);
    };
    function<void(int, int)> dfs2 = [&](int v, int fa) {
        vector<int> V;
        for (int u : G[v]) V.push_back(f[u]);
        sort(V.begin(), V.end(), greater<int>());
        int g = 0;
        for (int i = 1; i < V.size(); i++) {
            g = max(g, V[i] + i - 1);
        }
        lim = max(lim, g + V[0]);
        sort(G[v].begin(), G[v].end(), [&](int x, int y) { return f[x] > f[y]; });
        vector<int> pre(G[v].size()), suf(G[v].size());
        for (int i = 0; i < G[v].size(); i++) {
            pre[i] = max(i ? pre[i - 1] : 1, f[G[v][i]] + i);
        }
        for (int i = G[v].size() - 1; ~i; i--) {
            suf[i] = max(i < G[v].size() - 1 ? suf[i + 1] : 1, f[G[v][i]] + i - 1);
        }
        for (int i = 0; i < G[v].size(); i++) if (G[v][i] ^ fa) {
            int u = G[v][i], foo = f[v], bar = f[u];
            f[v] = max(i ? pre[i - 1] : 1, i < G[v].size() - 1 ? suf[i + 1] : 1);
            calc(u), dfs2(u, v);
            f[v] = foo, f[u] = bar;
        }
    };
    dfs1(1, 0), dfs2(1, 0);
    cout << lim << endl;
    function<pair<int, bool>(int, int)> dfs3 = [&](int v, int fa) {
        lb[v] = INT_MAX, rb[v] = INT_MIN;
        if (G[v].size() == (fa > 0)) {
            cout << "? " << v << endl;
            int x; cin >> x;
            lb[v] = rb[v] = tid[x];
            if (x == v) ans.push_back(v);
            return make_pair(x, x == v);
        }
        sort(G[v].begin(), G[v].end(), [&](int x, int y) { return f[x] > f[y]; });
        int cnt = v == rt ? 2 : 1, o = 0;
        bool flag = 0;
        for (int u : G[v]) if (u ^ fa) {
            auto p = dfs3(u, v);
            lb[v] = min(lb[v], lb[u]), rb[v] = max(rb[v], rb[u]);
            if (p.first) {
                if (!o) o = p.first;
                else if (o ^ p.first) o = -1;
            }
            if (p.second) {
                flag = 1;
                if (!--cnt) break;
            }
            if (lb[v] < tid[v] || rb[v] >= tid[v] + sz[v]) { flag = 0; break; }
        }
        if (o == v) ans.push_back(v), flag = 1;
        return make_pair(o, flag);
    };
    cin >> rt;
    dfs1(rt, tim = 0), dfs3(rt, 0);
    if (ans.size() == 1) ans.push_back(rt);
    cout << "! " << ans[0] << " " << ans[1] << endl;
    return 0;
}