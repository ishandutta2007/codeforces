#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

vector<pii> g[200200];
vector<pii> conflict[200200];
char was[200200][2];
map<pii, int> ans;

void dfs(int v, int p) {
    if (was[v][p])
        return;
    was[v][p] = 1;
    for (auto [to, pp] : conflict[v])
        dfs(to, p ^ pp);
}

void add(int a, int b, int z) {
    if (a > b) swap(a, b);
    ans[{a, b}] = z;
}

void dfsRestore(int v, int p, int pred = -1) {
    for (auto& [to, pp] : g[v]) {
        if (to == pred) continue;
        int nxtColor = (was[to][1] ? 1 : 0);
        if (pp == -1) {
            pp = p ^ nxtColor;
        }
        add(v, to, pp);
        dfsRestore(to, nxtColor, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            conflict[i].clear();
            was[i][0] = was[i][1] = 0;
        }
        ans.clear();
        for (int i = 0; i < n - 1; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            g[x].emplace_back(y, z);
            g[y].emplace_back(x, z);
            if (z != -1) {
                int p = __builtin_popcount(z) % 2;
                conflict[x].emplace_back(y, p);
                conflict[y].emplace_back(x, p);
            }
        }
        for (int i = 0; i < m; ++i) {
            int a, b, p;
            cin >> a >> b >> p;
            conflict[a].emplace_back(b, p);
            conflict[b].emplace_back(a, p);
        }
        for (int i = 1; i <= n; ++i) {
            if (!was[i][0] && !was[i][1])
                dfs(i, 0);
        }
        bool good = true;
        for (int i = 1; i <= n; ++i) {
            if (was[i][0] && was[i][1])
                good = false;
        }
        if (!good) {
            cout << "NO\n";
        } else {
            dfsRestore(1, 0);
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) {
                for (auto [to, z] : g[i]) {
                    if (i < to) {
                        cout << i << ' ' << to << ' ' << ans[{i, to}] << '\n';
                    }
                }
            }
        }
    }
}