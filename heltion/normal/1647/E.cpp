#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i += 1) cin >> p[i];
    int rm = n + 1 - set<int>(p.begin(), p.end()).size();
    for (int i = 1; i <= n; i += 1) cin >> a[i];
    int mx = ranges::max(a);
    assert((mx - n) % rm == 0);
    int t = (mx - n) / rm;
    vector nxt(n + 1, vector<int>(30));
    for (int i = 0; i < 30; i += 1)
        for (int j = 1; j <= n; j += 1)
            if (i == 0) nxt[j][i] = p[j];
            else nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
    vector<vector<int>> G(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i += 1) {
        c[i] = i;
        for (int j = 0; j < 30; j += 1)
            if ((t >> j) & 1)
                c[i] = nxt[c[i]][j];
        G[c[i]].push_back(i);
    }
    vector<int> mn(n + 1), b(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i += 1) s.insert(i);
    for (int i = 1; i <= n; i += 1) {
        if (G[i].size()) {
            b[G[i][0]] = a[i];
            s.erase(a[i]);
        }
    }
    for (int i = 1; i <= n; i += 1) {
        if (b[i] == 0) {
            b[i] = *s.lower_bound(a[c[i]]);
            s.erase(b[i]);
        }
        cout << b[i] << " ";
    }
    return 0;
}