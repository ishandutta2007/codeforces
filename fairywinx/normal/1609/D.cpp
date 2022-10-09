#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

struct dsu {
    vector<int> p, sz;
    dsu(int n) {
        p.resize(n);
        iota(all(p), 0);
        sz.resize(n, 1);
    }
    int get(int a) {
        if (a == p[a])
            return a;
        return p[a] = get(p[a]);
    }
    void merge(int a, int b) {
        a = get(a), b = get(b);
        if (a != b) {
            sz[a] += sz[b];
            p[b] = a;
        }
    }
};

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a;
    dsu d(n);
    for (int k = 1; k <= q; ++k) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        d.merge(b, c);
        vector<int> s;
        int S = 0;
        for (int i = 0; i < n; ++i) {
            if (d.get(i) == i) {
                s.emplace_back(d.sz[i]);
                S += d.sz[i];
            }
        }
        sort(rall(s));
        int dop = min((int) s.size() - 1, k - (S - (int) s.size()));
        int ans = 0;
        for (int j = 0; j <= dop; ++j)
            ans += s[j];
        cout << ans - 1 << '\n';
    }
}