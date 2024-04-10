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

// note, the file lca_old.cpp allows lca queries in O(1) time instead of O(logn) time,
// but has a much higher constant factor and can cause MLE for around 5*10^5 vertices.

vector<vector<int>> make_cartesian_tree(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> adj(n);
    set<int> s = {-1, n};
    vector<int> o(n);
    for (int i = 0; i < n; i++)
        o[n-1-p[i]] = i;
    for (int i : o) {
        int l = *--s.lower_bound(i);
        int r = *s.lower_bound(i);
        debug(i, l, r);
        if (l != -1 && (r == n || p[l] < p[r]))
            adj[i].pb(l), adj[l].pb(i);
        if (r != n && (l == -1 || p[r] < p[l]))
            adj[i].pb(r), adj[r].pb(i);
        s.insert(i);
    }
    return adj;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, q; cin >> n >> q;
        vector<int> p(n), a(n);
        for (int i = 0; i < n; i++) 
            cin >> p[i], p[i]--;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        debug(n, q);
        debug(p);
        debug(a);

        auto adj = make_cartesian_tree(p);
        debug(adj);

        vector<int> o(n);
        for (int i = 0; i < n; i++)
            o[n-1-p[i]] = i;

        vector<int> min_p(n, inf), max_c(n, -inf);

        for (int i = 0; i < n; i++)
            if (a[i] != 0)
                min_p[i] = max_c[i] = a[i];

        for (int i : o)
            for (int j : adj[i])
                if (p[i] < p[j])
                    min_p[i] = min(min_p[i], min_p[j]);

        reverse(all(o));

        for (int i : o)
            for (int j : adj[i])
                if (p[i] < p[j])
                    max_c[j] = max(max_c[j], max_c[i]);

        reverse(all(o));

        debug(min_p);
        debug(max_c);

        int k = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == 0)
                k++;
        debug(k);

        vector<pair<int, bool>> d;
        map<int, int> pos;
        for (int i = 0; i < k-1; i++) {
            int x; cin >> x;
            d.pb({x, true});
        }
        for (int i = 0; i < q; i++) {
            int x; cin >> x;
            pos[x] = i;
            d.pb({x, false});
        }
        sort(all(d));
        debug(d);

        bool bad = false;
        bool very_bad = false;

        vector<array<int, 2>> v;
        for (int i = 0; i < n; i++)
            if (a[i] == 0) {
                v.pb({max_c[i], min_p[i]});
            } else {
                if (max_c[i] > min_p[i]) {
                    bad = true;
                    very_bad = true;
                }
            }
        sort(all(v));
        debug(v);

        multiset<int> s;
        map<int, vector<int>> e;
        int vi = 0;
        map<int, bool> e_bad;
        vector<int> maybe_not_bad;

        for (auto& [x, forced] : d) {
            while (vi < v.size() && v[vi][0] <= x)
                s.insert(v[vi][1]), vi++;

            debug(x, forced, s, e);

            if (forced) {
                if (s.empty()) {
                    bad = true;
                    break;
                }
                ll y = *s.begin();
                if (y < x) {
                    s.erase(s.begin());
                    bad = true;
                    if (!s.empty() && *s.begin() >= x) {
                        for (int i : e[y])
                            maybe_not_bad.pb(i);
                    } else {
                        break;
                    }
                }
                s.erase(s.begin());
                if (s.empty() || *s.begin() < x) {
                    for (int i : e[y])
                        e_bad[i] = true;
                    e[y].clear();
                } else {
                    ll z = *s.begin();
                    if (y != z) {
                        debug(y, z);
                        if (e[y].size() > e[z].size())
                            swap(e[y], e[z]);
                        auto& tmp = e[z];
                        for (int i : e[y])
                            tmp.pb(i);
                        e[y].clear();
                    }
                }
            } else {
                if (s.empty()) {
                    e_bad[x] = true;
                } else {
                    ll y = *s.begin();
                    if (y < x)
                        e_bad[x] = true;
                    else
                        e[y].pb(x);
                }
            }
        }

        debug(bad, e_bad, maybe_not_bad);
        vector<int> ans(q);

        if (!very_bad && bad && !maybe_not_bad.empty()) {
            vi = 0;
            bad = false;
            s.clear();
            for (auto& [x, forced] : d) {
                if (!forced && x != maybe_not_bad[0])
                    continue;
                while (vi < v.size() && v[vi][0] <= x)
                    s.insert(v[vi][1]), vi++;
                if (s.empty() || *s.begin() < x) {
                    bad = true;
                    break;
                } else {
                    s.erase(s.begin());
                }
            }
            if (!bad)
                for (int i : maybe_not_bad)
                    ans[pos[i]] = true;
        } else {
            for (auto& [x, forced] : d)
                if (!forced) {
                    ans[pos[x]] = !(bad || e_bad[x]);
                    debug(x, pos[x], ans[pos[x]]);
                }
        }

        for (int i = 0; i < q; i++)
            cout << (ans[i] ? "YES" : "NO") << "\n";
    }
}

/*

NO
NO
NO
YES
YES
NO

*/