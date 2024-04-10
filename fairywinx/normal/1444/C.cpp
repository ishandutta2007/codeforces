#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

struct dsu {
    vector<pair<int, int>> p;
    vector<int> sz;
    vector<pair<int, pair<int, int>>> stP;
    vector<pair<int, int>> stSz;
    dsu(int n) {
        p.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i)
            p[i].first = i;
    }

    int getCol(int v) {
        if (v == p[v].first)
            return p[v].second;
        return p[v].second ^ getCol(p[v].first);
    }

    int getPar(int v) {
        if (v == p[v].first)
            return v;
        return getPar(p[v].first);
    }

    bool merge(int a, int b) {
        int c1 = getCol(a), c2 = getCol(b);
        if (getPar(a) == getPar(b))
            return c1 == c2;

        a = getPar(a), b = getPar(b);
        if (sz[a] < sz[b]) {
            stP.emplace_back(a, p[a]);
            stSz.emplace_back(b, sz[b]);
            sz[b] += sz[a];
            p[a] = {b, c1 ^ c2 ^ 1};
        } else {
            stP.emplace_back(b, p[b]);
            stSz.emplace_back(a, sz[a]);
            sz[a] += sz[b];
            p[b] = {a, c2 ^ c1 ^ 1};
        }
        return false;
    }
};

long long mind(int n, int m, int k, vector<int> a, vector<pair<int, int>> edge) {
    vector<set<int>> who(k);
    map<pair<int, int>, vector<pair<int, int>>> e;
    dsu d(n);
    for (int i = 0; i < m; ++i) {
        auto [c, b] = edge[i];
        if (a[c] != a[b]) {
            who[a[c]].insert(a[b]);
            who[a[b]].insert(a[c]);
        }
        e[{a[c], a[b]}].emplace_back(c, b);
        if (a[c] != a[b]) {
            e[{a[b], a[c]}].emplace_back(c, b);
        }
    }

    long long ans = 0;
    int cntBad = 0;
    vector<int> good(k, 1);
    for (int i = 0; i < k; ++i) {
        for (auto j : e[{i, i}]) {
            if (d.merge(j.first, j.second)) {
                good[i] = 0;
                ++cntBad;
                break;
            }
        }
    }
    pair<int, int> sz = {d.stP.size(), d.stSz.size()};
    for (int i = 0; i < k; ++i) {
        if (!good[i]) {
            continue;
        }
        int cnt = 0;
        for (auto j : who[i]) {
            if (!good[j])
                continue;

            bool find = false;
            for (auto k : e[{i, j}]) {
                if (d.merge(k.first, k.second)) {
                    find = true;
                    break;
                }
            }
            if (find) {
                ++cnt;
            }
            while ((int) d.stP.size() != sz.first) {
                d.p[d.stP.back().first] = d.stP.back().second;
                d.stP.pop_back();
            }
            while ((int) d.stSz.size() != sz.second) {
                d.sz[d.stSz.back().first] = d.stSz.back().second;
                d.stSz.pop_back();
            }
        }
        ans += (k - 1 - cnt - cntBad);
    }
    return ans / 2;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // stress();

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<pair<int, int>> edge(m);
    for (auto &i : edge) {
        cin >> i.first >> i.second;
        --i.first, --i.second;
    }
    cout << mind(n, m, k, a, edge) << '\n';
}