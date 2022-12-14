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

void solve() {
    int n;
    cin >> n;
    vt<set<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int u = 1, p = 0;;) {
        if (adj[u].empty()) {
            cout << "! " << u << endl;
            exit(0);
        } else if (sz(adj[u]) == 1) {
            int v = *adj[u].begin();
            if (v == p) {
                cout << "? " << u << ' ' << p << endl;
                int r;
                cin >> r;
                if (~r) cout << "! " << r << endl;
                exit(0);
            } else {
                p = u;
                u = v;
            }
        }
        else {
            int v = *adj[u].begin(),
                w = *adj[u].rbegin();
            cout << "? " << v << ' ' << w << endl;
            int r;
            cin >> r;

            if (!~r) exit(0);
            else if (r != u) {
                adj[r].erase(u);
                p = u;
                u = r;
            } else {
                adj[u].erase(v);
                adj[u].erase(w);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}