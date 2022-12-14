#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const ll mod = 1e9 + 7;
const int inf = 1 << 30;

struct DSU {
    vt<int> p;
    DSU(int n) : p(n + 1, -1) {}
    int root(int u) { return p[u] < 0 ? u : p[u] = root(p[u]); }
    bool unite(int u, int v) {
        if ((u = root(u)) == (v = root(v))) return false;
        if (p[u] > p[v]) swap(u, v);

        p[u] += p[v];
        p[v] = u;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(m);
    vt<int> ans;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        if (k == 1) {
            int u;
            cin >> u;

            if (dsu.unite(0, u)) {
                ans.push_back(i);
            }
        } else {
            int u, v;
            cin >> u >> v;

            if (dsu.unite(u, v)) {
                ans.push_back(i);
            }
        }
    }

    ll t = 1;
    for (int i = 0; i < sz(ans); i++) t = t * 2 % mod;
    cout << t << ' ' << sz(ans) << '\n';
    sort(all(ans));
    for (int i : ans) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}