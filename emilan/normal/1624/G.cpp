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
    int comp;

    Dsu(int n) : p(n, -1), comp(n) {}

    int root(int u) { return p[u] < 0 ? u : p[u] = root(p[u]); }

    void combine(int u, int v) {
        int x = root(u);
        int y = root(v);
        if (x == y) return;
        if (p[x] > p[y]) swap(x, y);

        p[x] += p[y];
        p[y] = x;
        comp--;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (auto &[u, v, w] : edges) {
        cin >> u >> v >> w;
        u--, v--;
    }

    auto f = [&](int msk) {
        Dsu dsu(n);
        for (auto [u, v, w] : edges) {
            if ((w & ~msk) == 0) dsu.combine(u, v);
        }
        return dsu.comp == 1;
    };

    int msk = 0;
    for (int k = 29; k >= 0; k--) {
        if (!f(msk | ((1 << k) - 1))) msk |= 1 << k;
    }
    cout << msk << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}