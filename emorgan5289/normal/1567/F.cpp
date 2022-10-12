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

vector<array<int, 2>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int N = 505;
int a[N][N], c[N][N], v[N][N];
map<array<int, 2>, vector<array<int, 2>>> adj;
vector<array<array<int, 2>, 2>> e;

void dfs(int i, int j, int k) {
    v[i][j] = 1;
    a[i][j] = k;
    for (auto& [x, y] : adj[{i, j}])
        if (!v[x][y]) dfs(x, y, 5-k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            c[i][j] = x == 'X';
        }

    auto get = [&](int i, int j) {
        return m*i+j;
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            vector<array<int, 2>> p;
            if (c[i][j])
                for (auto& [di, dj] : d)
                    if (!c[i+di][j+dj])
                        p.pb({i+di, j+dj});
            if (p.size()%2 == 1) {
                cout << "NO\n";
                exit(0);
            }
            if (p.size() >= 2)
                e.pb({p[0], p[1]});
            if (p.size() >= 4)
                e.pb({p[2], p[3]});
        }

    for (auto& [p, q] : e)
        adj[p].pb(q), adj[q].pb(p);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!c[i][j] && !v[i][j]) dfs(i, j, 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (c[i][j])
                for (auto& [di, dj] : d)
                    if (!c[i+di][j+dj])
                        a[i][j] += a[i+di][j+dj];

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (c[i][j] && a[i][j]%5 != 0) {
                debug(i, j); assert(0);
            }
            cout << a[i][j] << " \n"[j == m-1];
        }
}