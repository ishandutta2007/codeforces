#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010, P = 998244353;
int n1, n2, m, q, ans, pw = 1, tot, d[maxn], fa[maxn], bel[maxn], s[maxn][2];

int find(int x) {
    if (x == fa[x]) return x;
    int y = find(fa[x]);
    d[x] ^= d[fa[x]];
    return fa[x] = y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n1 >> n2 >> m;
    iota(fa, fa + maxn, 0);
    auto unite = [&](int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return;
        if (d[u] == d[v]) {
            ans = (1LL * ans + s[x][0] - s[x][1] + P) % P;
            swap(s[x][0], s[x][1]), d[x] = 1;
        }
        fa[x] = y, (s[y][0] += s[x][0]) %= P, (s[y][1] += s[x][1]) %= P;
    };
    auto add_edge = [&](int u, int v) {
        m++, (pw *= 2) %= P, s[++tot][0] = pw;
        if (!bel[u] && !bel[v]) bel[u] = bel[v] = tot;
        else if (!bel[u]) unite(tot, bel[v]), bel[u] = tot, bel[v] = 0;
        else if (!bel[v]) unite(tot, bel[u]), bel[v] = tot, bel[u] = 0;
        else unite(tot, bel[u]), unite(tot, bel[v]), bel[u] = bel[v] = 0;
    };
    int o = m;
    m = 0;
    while (o--) {
        int u, v;
        cin >> u >> v, add_edge(u, v + n1);
    }
    cin >> q;
    while (q--) {
        int op, u, v;
        cin >> op;
        if (op == 1) {
            cin >> u >> v, add_edge(u, v + n1);
            cout << ans << endl;
        } else {
            vector<int> V;
            for (int i = 1; i <= m; i++) {
                if (find(i), d[i]) V.push_back(i);
            }
            cout << V.size();
            for (int x : V) cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}