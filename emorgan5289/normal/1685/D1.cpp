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
        int n; cin >> n;
        vector<int> p(n), e(n, -1);
        for (int i = 0; i < n; i++)
            cin >> p[i], p[i]--;

        // dsu u(n);
        // for (int i = 0; i < n; i++)
        //     u.unite(i, p[i]);
        // int s = -2;
        // for (int i = 0; i < n; i++)
        //     if (i == u.rep(i)) s += 2;

        auto has_solution = [&]() {

            vector<int> tmp_e(e);

            // add missing edges

            // for (int i = 0; i < n; i++) {
            //     if (e[i] != -1 && i+1 < e[i])
            //         for (int j = e[i]; j > i; j--) {
            //             if (tmp_e[j] != -1 && tmp_e[j] != j-1)
            //                 return 0;
            //             tmp_e[j] = j-1;
            //         }
            //     if (e[i] != -1 && i-1 > e[i])
            //         for (int j = e[i]; j < i; j++) {
            //             if (tmp_e[j] != -1 && tmp_e[j] != j+1)
            //                 return 0;
            //             tmp_e[j] = j+1;
            //         }
            // }

            // u = dsu(n);
            // for (int i = 0; i < n; i++) {
            //     u.unite(i, p[i]);
            //     u.unite(i, tmp_e[i]);
            // }

            // edges of same orientation do not overlap

            for (int i = 0; i < n; i++)
                if (e[i] != -1 && e[i] > i)
                    for (int j = i+1; j < e[i]; j++)
                        if (e[j] != -1 && e[j] > j)
                            return 0;
            for (int i = 0; i < n; i++)
                if (e[i] != -1 && e[i] < i)
                    for (int j = i-1; j > e[i]; j--)
                        if (e[j] != -1 && e[j] < j)
                            return 0;

            // edges of different orientation don't overlap too much

            vector<bool> vis(n);
            for (int i = 0; i < n; i++)
                if (e[i] != -1 && e[i] > i)
                    for (int j = i+1; j < e[i]; j++)
                        vis[j] = 1;
            for (int i = 0; i < n; i++)
                if (e[i] != -1 && e[i] < i)
                    for (int j = i-1; j > e[i]; j--)
                        if (vis[j]) return 0;

            // edges don't exceed minimum length

            dsu u(n), v(n);
            for (int i = 0; i < n; i++)
                u.unite(i, p[i]);
            for (int i = 0; i < n; i++)
                if (e[i] != -1 && e[i] > i)
                    for (int j = min(i, e[i]); j < max(i, e[i]); j++) {
                        v.unite(j, j+1);
                        if (u.unite(j, j+1))
                            return 0;
                    }
            for (int i = 0; i < n; i++)
                if (e[i] != -1 && e[i] < i)
                    for (int j = min(i, e[i]); j < max(i, e[i]); j++)
                        if (!v.unite(j, j+1) && u.unite(j, j+1))
                            return 0;

            // possible to add remaining edges so everything is connected

            vector<int> l(n), r(n);
            for (int i = 0; i < n; i++)
                if (e[i] != -1)
                    l[i] = 1, r[e[i]] = 1;
            for (int i = 0; i+1 < n; i++) {
                if (!u.query(i, i+1)) {
                    if (l[i] && r[i]) continue;
                    if (l[i+1] && r[i+1]) continue;
                    u.unite(i, i+1);
                }
            }
            if (u.size(0) != n)
                return 0;

            debug(p);
            debug(e);
            return 1;
        };

        vector<int> q(n, -1);
        q[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++)
                if (find(all(q), j) == q.end()) {
                    // q[i] = pi[e[q[i-1]]]
                    // p[q[i]] = e[q[i-1]]
                    q[i] = j;
                    e[q[i-1]] = p[q[i]];
                    if (has_solution()) break;
                }
            debug(q);
        }

        debug(e);

        assert(has_solution());

        for (int i = 0; i < n; i++)
            cout << q[i]+1 << " \n"[i == n-1];
    }
}