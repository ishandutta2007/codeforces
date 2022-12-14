#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

struct Dsu {
    vector<int> p;
    vector<int> kaboom;

    Dsu(int n) : p(n, -1), kaboom(n) {}

    int root(int u) { return p[u] < 0 ? u : p[u] = root(p[u]); }

    void combine(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        if (p[u] > p[v]) swap(u, v);
        kaboom[u] = min(kaboom[u], kaboom[v]);
        p[u] += p[v];
        p[v] = u;
    }
};

int solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> mines(n);
    map<int, vector<int>> row, col;
    REP(i, n) {
        auto &[x, y, t] = mines[i];
        cin >> x >> y >> t;
        row[x].push_back(i);
        col[y].push_back(i);
    }

    Dsu dsu(n);
    REP(i, n) dsu.kaboom[i] = mines[i][2];
    for (auto [_, v] : row) {
        sort(ALL(v), [&](int i, int j) { return mines[i][1] < mines[j][1];} );
        REP(p, SZ(v) - 1) {
            auto [x0, y0, t0] = mines[v[p]];
            auto [x1, y1, t1] = mines[v[p + 1]];
            if (y1 - y0 <= k) dsu.combine(v[p], v[p + 1]);
        }
    }
    for (auto [_, v] : col) {
        sort(ALL(v), [&](int i, int j) { return mines[i][0] < mines[j][0];} );
        REP(p, SZ(v) - 1) {
            auto [x0, y0, t0] = mines[v[p]];
            auto [x1, y1, t1] = mines[v[p + 1]];
            if (x1 - x0 <= k) dsu.combine(v[p], v[p + 1]);
        }
    }

    vector<int> kaboom;
    for (int u = 0; u < n; u++) if (dsu.p[u] < 0) {
        kaboom.push_back(dsu.kaboom[u]);
    }
    sort(ALL(kaboom));

    int m = SZ(kaboom);
    for (int t = 0; t < m - 1; t++) {
        if (kaboom[m - t - 2] <= t) return t;
    }
    return m - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}