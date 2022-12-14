#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> p;

    DSU(int n) : p(n, -1) {}

    bool same(int u, int v) { return root(u) == root(v); }
    int root(int u) { return p[u] < 0 ? u : p[u] = root(p[u]); }

    bool combine(int u, int v) {
        if ((u = root(u)) == (v = root(v))) return false;
        if (p[u] > p[v]) swap(u, v);

        p[u] += p[v];
        p[v] = u;

        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    int cnt = 1;
    while (q--) {
        int u, v;
        cin >> u >> v;

        if (!dsu.combine(--u, --v)) cnt++;

        int ans = -1;
        vector<int> s(dsu.p);
        sort(s.begin(), s.end());
        for (int i = 0; i < cnt; i++) if (s[i] < 0) {
            ans -= s[i];
        }
        cout << ans << "\n";
    }
}