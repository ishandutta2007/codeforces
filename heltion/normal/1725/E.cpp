#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
struct P{
    int p, a, d;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int test_time = 0;
    int n, m = 200000;
    cin >> n;
    if (test_time) n = 200000;
    vector<int> a(n + 1);
    vector<vector<int>> ar(m + 1), ap(m + 1);
    vector<int> cp(m + 1);
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i];
        if (test_time) a[i] = 30030;
        ar[a[i]].push_back(i);
    }
    for (int i = 2; i <= m; i += 1)
        if (not cp[i]) {
            for (int j = i; j <= m; j += i) {
                cp[j] = 1;
                for (int k : ar[j]) ap[i].push_back(k);
            }
        }
    vector<vector<int>> G(n + 1);
    for (int i = 1, u, v; i < n; i += 1) {
        cin >> u >> v;
        if (test_time) {
            v = i + 1;
            u = rand() % i + 1;
        }
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> dfn(n + 1), size(n + 1), dep(n + 1);
    vector p(n + 1, vector<int>(18));
    int dft = 0;
    function<void(int)> DFS = [&](int u) {
        dfn[u] = dft += 1;
        size[u] = 1;
        for (int i = 1; i < 18; i += 1)
            p[u][i] = p[p[u][i - 1]][i - 1];
        for (int v : G[u]) if (v != p[u][0]) {
            p[v][0] = u;
            dep[v] = dep[u] + 1;
            DFS(v);
            size[u] += size[v];
        }
    };
    DFS(1);
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 0; i < 18; i += 1)
            if ((dep[u] - dep[v]) & (1 << i))
                u = p[u][i];
        for (int i = 17; i >= 0; i -= 1)
            if (p[u][i] != p[v][i]) {
                u = p[u][i];
                v = p[v][i];
            }
        if (u == v) return u;
        return p[u][0];
    };
    auto ff = [&](vector<int> v) {
        ranges::sort(v, [&](int x, int y){
            return dfn[x] < dfn[y];
        });
        vector<int> w = v;
        for (int i = 1; i < v.size(); i += 1)
            w.push_back(lca(v[i - 1], v[i]));
        ranges::sort(w, [&](int x, int y){
            return dfn[x] < dfn[y];
        });
        w.erase(unique(w.begin(), w.end()), w.end());
        map<int, int> mp;
        for (int i = 0; i < w.size(); i += 1)
            mp[w[i]] = i;
        vector<P> f(w.size());
        for (int i = 0; i < w.size(); i += 1) {
            mp[w[i]] = i;
            f[i] = {-1, a[w[i]]};
        }
        vector<int> st = {w[0]};
        for (int i = 1; i < w.size(); i += 1) {
            while (dfn[w[i]] >= dfn[st.back()] + size[st.back()]) st.pop_back();
            int x = st.back();
            f[i].p = mp[x];
            f[i].d = dep[w[i]] - dep[x];
            st.push_back(w[i]);
        }
        return f;
    };
    auto get = [&](vector<P> f) {
        int n = f.size();
        vector<vector<int>> G(n);
        vector<LL> cdown(n), sdown(n), cup(n), sup(n);
        for (int i = 1; i < n; i += 1)
            G[f[i].p].push_back(i);
        for (int i = n - 1; i >= 0; i -= 1) {
            cup[i] += f[i].a;
            if (f[i].p >= 0) {
                cup[f[i].p] += cup[i];
                sup[f[i].p] += sup[i] + cup[i] * f[i].d;
            }
        }
        for (int i = 0; i < n; i += 1) {
            LL cc = cdown[i] + f[i].a, ss = sdown[i];
            for (int j : G[i]) {
                cc += cup[j];
                ss += sup[j] + cup[j] * f[j].d;
            }
            for (int j : G[i]) {
                cdown[j] = cc - cup[j];
                sdown[j] = ss - sup[j] - cup[j] * f[j].d + cdown[j] * f[j].d;
            }
        }
        LL ans = 0;
        for (int i = 0; i < n; i += 1) {
            vector<pair<LL, LL>> x;
            x.emplace_back(cdown[i], sdown[i]);
            for (int j : G[i]) x.emplace_back(cup[j], sup[j] + cup[j] * f[j].d);
            vector<LL> dpf(4), dpg(4);
            dpf[0] = 1;
            for (auto [ci, xi] : x) {
                xi %= mod;
                for (int i = 3; i; i -= 1) {
                    dpf[i] = (dpf[i] + ci * dpf[i - 1]) % mod;
                    dpg[i] = (dpg[i] + ci * dpg[i - 1] + xi * dpf[i - 1]) % mod;
                }
            }
            ans = (ans + dpg[3]) % mod;
            if (f[i].a) ans = (ans + dpg[2]) % mod;
            //for (auto [x, y] : x) cout << x << "-" << y << " "; cout << "\n";
            //for (auto x : dpf) cout << x << " "; cout << "\n";
            //for (auto x : dpg) cout << x << " "; cout << "\n";
        }
        return ans;
    };
    LL ans = 0;
    for (int i = 1; i <= n; i += 1)
        if (ap[i].size()) {
            auto f = ff(ap[i]);
            for (auto& [x, y, z] : f) y = y % i == 0;
            //for (auto [x, y, z] : f) cout << "(" << x << "," << y << "," << z << ")"; cout << "\n";
            ans += get(f);
        }
    cout << ans % mod;
}