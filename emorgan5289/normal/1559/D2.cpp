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
    int n, m1, m2; cin >> n >> m1 >> m2;
    dsu u1(n), u2(n);

    while (m1--) {
        int x, y; cin >> x >> y;
        u1.unite(x-1, y-1);
    }
    while (m2--) {
        int x, y; cin >> x >> y;
        u2.unite(x-1, y-1);
    }

    vector<array<int, 2>> ans;
    for (int i = 1; i < n; i++)
        if (!u1.query(0, i) && !u2.query(0, i)) {
            ans.pb({0, i});
            u1.unite(0, i), u2.unite(0, i);
        }

    map<int, int> l, r;
    for (int i = 1; i < n; i++) {
        if (!u1.query(0, i)) l[u1.rep(i)] = i;
        if (!u2.query(0, i)) r[u2.rep(i)] = i;
    }
    while (!l.empty() && !r.empty()) {
        ans.pb({l.begin()->second, r.begin()->second});
        l.erase(l.begin()), r.erase(r.begin());
    }

    cout << ans.size() << "\n";
    for (auto& [i, j] : ans)
        cout << i+1 << " " << j+1 << "\n";
}