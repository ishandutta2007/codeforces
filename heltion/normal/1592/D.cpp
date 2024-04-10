#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 1;
vector<int> G[maxn];
int done[maxn], par[maxn], sz[maxn], sum[maxn], n, m, k, rt;
int query(vector<int> v) {
    cout << "? " << v.size();
    for (int x : v) cout << " " << x;
    cout << endl;
    int res;
    cin >> res;
    return res;
}
bitset<maxn> dp, f[maxn];
void frt(int u) {
    vector<int> w;
    sz[u] = 1;
    for (int v : G[u]) if (v != par[u] and not done[v]) {
        par[v] = u;
        frt(v);
        sz[u] += sz[v];
        w.push_back(sz[v]);
    }
    w.push_back(k - sz[u]);
    dp.reset();
    dp.set(0);
    for (int x : w) dp = dp | dp << x;
    for (int i = k / 2; i < k; i += 1) if (dp.test(i)) {
        sum[u] = 2 * i - k + 1;
        break;
    }
    if (not rt or sum[u] < sum[rt]) rt = u;
}
void DC(int u) {
    if (k == 2)
        for (int v : G[u]) if (not done[v]) {
            cout << "! " << u << " " << v << "\n";
            return;
        }
    rt = 0;
    par[u] = 0;
    frt(u);
    vector<int> x;
    for (int v : G[rt]) if (not done[v]) {
        if (v == par[rt]) sz[v] = k - sz[rt];
        x.push_back(v);
    }
    vector<int> y(x.size());
    dp.reset();
    dp.set(0);
    for (int i = 0; i < (int)x.size(); i += 1) {
        auto& p = i ? f[i - 1] : dp;
        f[i] = p | p << sz[x[i]];
    }
    for (int i = (int)x.size() - 1, j = (sum[rt] + k - 1) / 2; i >= 0; i -= 1) {
        auto& p = i ? f[i - 1] : dp;
        if (j >= sz[x[i]] and p.test(j - sz[x[i]])) {
            j -= sz[x[i]];
            y[i] = 1;
        }
        else assert(p.test(j));
    }
    vector<int> queries;
    function<void(int, int)> dfs = [&](int u, int par) {
        queries.push_back(u);
        for (int v : G[u]) if (not done[v] and v != par) {
            dfs(v, u);
        }
    };
    queries.push_back(rt);
    for (int i = 0; i < (int)x.size(); i += 1) if (y[i]) dfs(x[i], rt);
    int r = query(queries);
    for (int i = 0; i < (int)x.size(); i += 1) if ((r == m) ^ y[i]) {
        done[x[i]] = 1;
        k -= sz[x[i]];
    }
    DC(rt);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1, u, v; i < n; i += 1) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> v;
    for (int i = 1; i <= n; i += 1) v.push_back(i);
    m = query(v);
    k = n;
    DC(1);
    return 0;
}