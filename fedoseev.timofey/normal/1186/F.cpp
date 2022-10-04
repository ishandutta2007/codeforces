#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct edge {
    int u, v, id;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> d(n);
    vector <int> need(n);
    vector <int> cur(n);
    vector <int> ok(n);

    vector <set <int>> g(n);
    vector <edge> E;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++d[u];
        ++d[v];
        E.push_back({u, v, i});
        g[u].insert(i);
        g[v].insert(i);
    }
    auto get = [&] (int i, int u) {
        if (E[i].u == u) return E[i].v;
        return E[i].u;
    };
    auto add = [&] (int u) {
        ++cur[u];
        if (cur[u] >= need[u]) ok[u] = 1;
    };
    for (int i = 0; i < n; ++i) need[i] = (d[i] + 1) / 2;
    for (int i = 0; i < n; ++i) ok[i] = (need[i] == 0);
    set <int> ans;
    vector <int> p(n);
    iota(p.begin(), p.end(), 0);
    mt19937 rnd(123);
    shuffle(p.begin(), p.end(), rnd);
    for (int u : p) {
        vector <int> good, bad;
        for (int i : g[u]) {
            int v = get(i, u);
            if (ok[v]) bad.push_back(i);
            else good.push_back(i);
        }
        while (!ok[u]) {
            if (!good.empty()) {
                int i = good.back();
                good.pop_back();
                int v = get(i, u);
                add(u);
                add(v);
                g[v].erase(i);
                ans.insert(i);
            }
            else {
                int i = bad.back();
                bad.pop_back();
                int v = get(i, u);
                add(u);
                add(v);
                g[v].erase(i);
                ans.insert(i);
            }  
        }
    }
    assert(ans.size() <= (n + m + 1) / 2);
    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << E[i].u + 1 << ' ' << E[i].v + 1 << '\n';
    } 
}