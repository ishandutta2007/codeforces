#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int ans = n;
    vector<set<int>> s(n + 1);
    auto add = [&](int u, int v) {
        if (not s[u].empty() and *s[u].rbegin() > u) ans += 1;
        if (not s[v].empty() and *s[v].rbegin() > v) ans += 1;
        s[u].insert(v);
        s[v].insert(u);
        if (not s[u].empty() and *s[u].rbegin() > u) ans -= 1;
        if (not s[v].empty() and *s[v].rbegin() > v) ans -= 1;
    };
    auto rem = [&](int u, int v) {
        if (not s[u].empty() and *s[u].rbegin() > u) ans += 1;
        if (not s[v].empty() and *s[v].rbegin() > v) ans += 1;
        s[u].erase(v);
        s[v].erase(u);
        if (not s[u].empty() and *s[u].rbegin() > u) ans -= 1;
        if (not s[v].empty() and *s[v].rbegin() > v) ans -= 1;
    };
    for (int i = 0; i < m; i += 1) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    int q;
    for (cin >> q; q; q -= 1) {
        int t;
        cin >> t;
        if (t <= 2) {
            int u, v;
            cin >> u >> v;
            if (t == 1) add(u, v);
            else rem(u, v);
        }
        else cout << ans << "\n";
    }
    return 0;
}