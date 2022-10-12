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

/*
    given an edge list of the form {{w, x, y}, ...}
    where {w, x, y} means an edge from x to y with weight w,
    return a new edge list on the same vertices, such that:
    a) every vertex has degree <= 2 (i.e. the tree is a line)
    b) the maximum edge weight along the path from x to y in the
       new graph is the same as in the old graph, for any x and y.
*/
vector<array<int, 3>> make_linear(vector<array<int, 3>> e) {
    int n = e.size()+1;

    // u.rep(i) -> representative of set containing i
    // u.unite(x, y) -> unite sets containing x and y
    dsu u(n);

    // left and right endpoints of the line of vertices
    // corresponding to the set with representative i
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        l[i] = r[i] = i;

    vector<array<int, 3>> line_e;

    sort(e.begin(), e.end());
    for (auto& [w, x, y] : e) {
        x = u.rep(x), y = u.rep(y);
        u.unite(x, y);
        int z = u.rep(x);
        line_e.push_back({w, r[x], l[y]});
        l[z] = l[x], r[z] = r[y];
    }

    return line_e;
}

template<typename it, typename bin_op>
struct sparse_table {

    using T = typename iterator_traits<it>::value_type;
    vector<vector<T>> t; bin_op f;

    void assign(it first, it last) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = f(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }

    sparse_table(bin_op op) : f(op) {}
    sparse_table(it first, it last, bin_op op) : f(op) {
        assign(first, last);
    }

    // returns f(a[l..r]) in O(1) time
    T operator()(int l, int r) {
        int h = floor(log2(r-l+1));
        return f(t[h][l], t[h][r-(1<<h)+1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<array<int, 3>> e(m), new_e;
        for (int i = 0; i < m; i++) {
            cin >> e[i][1] >> e[i][2] >> e[i][0];
            e[i][1]--, e[i][2]--;
        }

        set<array<int, 2>> e_s;
        for (auto& [w, x, y] : e) {
            e_s.insert({x, y});
            e_s.insert({y, x});
        }

        vector<int> p(n), q(n), qq(n);
        vector<vector<int>> grp_old(n);
        vector<vector<int>> grp_sub(n);
        vector<set<int>> grp_new(n);

        debug();
        debug();
        debug();
        debug();

        for (int i = 0; i < n; i++) {
            p[i] = q[i] = qq[i] = i;
            grp_old[i].pb(i);
            grp_sub[i].pb(i);
            grp_new[i].insert(i);
        }

        auto merge_sub = [&](int ii, int jj) {
            ii = q[ii], jj = q[jj];
            debug(grp_new, q);
            debug(ii, jj);
            if (grp_sub[ii].size() < grp_sub[jj].size())
                swap(ii, jj);
            for (int z : grp_sub[jj])
                grp_sub[ii].pb(z), q[z] = ii;
            grp_new[qq[jj]].erase(grp_new[qq[jj]].find(jj));
        };


        auto e_copy = e;
        sort(all(e_copy));

        for (auto [w, x, y] : e_copy) {
            x = p[x], y = p[y];
            if (x == y) continue;
            if (grp_old[x].size() < grp_old[y].size())
                swap(x, y);

            debug(x, y, grp_old[x], grp_old[y]);
            debug(grp_new[x], grp_new[y]);

            vector<array<int, 2>> cross_edges;

            for (int i : grp_new[y]) {
                vector<int> roots(all(grp_new[x])), edges;
                for (int j : roots) {
                    for (int ii : grp_sub[i])
                        for (int jj : grp_sub[j])
                            if (!e_s.count({ii, jj})) {
                                edges.pb(j);
                                goto done;
                            }
                    done:;
                }

                // merge sub-groups
                for (int k : edges)
                    new_e.pb({w, i, k});
                if (!edges.empty())
                    cross_edges.pb({i, edges[0]});
                for (int k = 1; k < edges.size(); k++)
                    merge_sub(edges[0], edges[k]);
            }

            debug(cross_edges);
            for (auto& [xx, yy] : cross_edges)
                merge_sub(xx, yy);

            // merge top-level groups
            for (int z : grp_old[y])
                p[z] = x, grp_old[x].pb(z);
            for (int z : grp_new[y])
                qq[z] = x, grp_new[x].insert(z);
            grp_old[y].clear();
            grp_new[y].clear();
        }

        debug(new_e);

        new_e = make_linear(new_e);
        debug(new_e);

        vector<vector<array<int, 2>>> line_adj(n);
        vector<int> line_w(n-1), line_pos(n);

        for (auto& [w, x, y] : new_e) {
            line_adj[x].pb({w, y});
            line_adj[y].pb({w, x});
        }
        int r = 0, pr = -1;
        for (int i = 0; i < n; i++)
            if (line_adj[i].size() == 1)
                r = i;
        line_pos[r] = 0;
        for (int i = 1; i < n; i++) {
            for (auto& [w, j] : line_adj[r]) {
                if (j != pr) {
                    debug(pr, r, j, w);
                    pr = r, r = j;
                    line_w[i-1] = w;
                    line_pos[r] = i;
                    break;
                }
            }
        }

        debug(line_w);
        debug(line_pos);

        sparse_table rmq(all(line_w), [](int x, int y) { return max(x, y); });

        for (auto& [w, x, y] : e) {
            debug(x, y);
            int i = line_pos[x], j = line_pos[y];
            if (i > j) swap(i, j);
            cout << rmq(i, j-1) << "\n";
        }
    }
}