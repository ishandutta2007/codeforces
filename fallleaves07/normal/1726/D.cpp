#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int getfa(int v) {
        return (fa[v] == v) ? v : (fa[v] = getfa(fa[v]));
    }
    bool merge(int u, int v) {
        u = getfa(u), v = getfa(v);
        if (u == v) {
            return false;
        }
        fa[u] = v;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    struct Edges {
        int u, v, id;
    };
    vector<Edges> edges(m), e1, e2;
    e1.reserve(n - 1), e2.reserve(m - n + 2);
    int idc = 0;
    for (auto &[u, v, id] : edges) {
        cin >> u >> v;
        id = idc++;
    }
    DSU dsu(n);
    for (auto [u, v, id] : edges) {
        if (dsu.merge(u, v)) {
            e1.push_back({u, v, id});
        } else {
            e2.push_back({u, v, id});
        }
    }
    auto check = [&]() {
        if (e2.empty()) {
            return true;
        }
        map<int, int> cnt;
        for (auto [u, v, id] : e2) {
            ++cnt[u], ++cnt[v];
        }
        for (auto [u, c] : cnt) {
            if (c % 2) {
                return true;
            }
        }
        return false;
    };
    if (!check()) {
        e1.emplace_back(e2.back());
        e2.pop_back();
        swap(e1.front(), e1.back());
        edges.swap(e1);
        e1.clear();
        DSU dsu2(n);
        for (auto [u, v, id] : edges) {
            if (dsu2.merge(u, v)) {
                e1.push_back({u, v, id});
            } else {
                e2.push_back({u, v, id});
            }
        }
    }
    assert(check());
    vector<bool> ans(m);
    for (auto [u, v, id] : e1) {
        ans[id] = true;
    }
    for (auto b : ans) {
        putchar(b ? '0' : '1');
    }
    puts("");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}