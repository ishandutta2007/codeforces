#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL x[33], y[33];
LL dx[4] = {-1, 1, 0, 0};
LL dy[4] = {0, 0, -1, 1};

int n;
vector<int> g[33];

void dfs(int v, int par, int bdir, LL xx, LL yy, LL dist) {
    x[v] = xx;
    y[v] = yy;
    int dir = 0;
    for (int to : g[v]) if (to != par) {
        if (dir == bdir) ++dir;
        LL nx = xx + dx[dir] * dist;
        LL ny = yy + dy[dir] * dist;
        dfs(to, v, dir ^ 1, nx, ny, dist >> 1);
        ++dir;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n - 1) {
        int from, to;
        cin >> from >> to;
        --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, n) if (int(g[i].size()) > 4) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    dfs(0, -1, -1, 0, 0, 1ll << (n + 1));
    forn(i, n) {
        cout << x[i] << ' ' << y[i] << endl;
    }
    return 0;
}