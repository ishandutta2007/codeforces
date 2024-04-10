#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    // returns true if a and b are in the same set, and then unites them.
    bool unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m, k; cin >> n >> m >> k;
        vector<array<ll, 3>> e(m);
        for (int i = 0; i < m; i++)
            cin >> e[i][1] >> e[i][2] >> e[i][0];
        sort(all(e));
        debug(e);
        dsu u(n);
        ll max_e = -inf, sum_e = 0;
        for (auto& [s, x, y] : e) {
            if (u.size(0) == n && s > k) {
                if (s-k < k-max_e) {
                    cmax(max_e, s);
                    sum_e += max(0ll, s-k);
                }
                break;
            }
            if (s > k && u.query(x-1, y-1))
                continue;
            cmax(max_e, s);
            sum_e += max(0ll, s-k);
            u.unite(x-1, y-1);
        }
        if (max_e <= k) {
            cout << k-max_e << "\n";
        } else {
            cout << sum_e << "\n";
        }
    }
}