#include <bits/stdc++.h>
#define FOR(i, n, m) for (long long i = (n); i < (long long)(m); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr ld eps = 1e-6;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    REP(i, v.size()) {
        if (i) os << " ";
        os << v[i];
    }
    return os;
}

struct union_find {
    union_find(int n) : par_(n, -1) {}
    void init(int n) { par_.assign(n, -1); }
    int root(int x) { return par_[x] < 0 ? x : par_[x] = root(par_[x]); }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par_[x] < par_[y]) {
            par_[x] += par_[y];
            par_[y] = x;
        } else {
            par_[y] += par_[x];
            par_[x] = y;
        }
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par_[root(x)]; }
    vector<int> par_;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<bool> good(n, false);
    REP(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].pb({v - 1, w});
        g[v - 1].pb({u - 1, w});
        if (w % 2 == 0) {
            good[u - 1] = good[v - 1] = true;
        }
    }

    int q;
    cin >> q;
    vector<pair<int, int>> query(q);
    REP(i, q) {
        cin >> query[i].first >> query[i].second;
        query[i].first--;
        query[i].second--;
    }

    vector<int> ans(q, 2);

    REP(bit, 30) {
        union_find uf(n + 1);
        REP(i, n) REP(j, g[i].size()) {
            if (g[i][j].second & (1 << bit)) uf.unite(i, g[i][j].first);
        }

        REP(i, q) {
            if (uf.same(query[i].first, query[i].second))
                ans[i] = min(ans[i], 0);
        }

        REP(i, n) if (good[i] && bit != 0) uf.unite(i, n);

        REP(i, q) {
            if (uf.same(query[i].first, n)) ans[i] = min(ans[i], 1);
        }
    }

    REP(i, q) cout << ans[i] << endl;
    return 0;
}