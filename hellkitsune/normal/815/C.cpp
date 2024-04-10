#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MX = int(1e9) + 123;

int n, have;
int a[5000], b[5000];
vector<int> g[5000];
int d[5000][2][5001], e[2][5001];
int sz[5000];

void solve(int v) {
    d[v][0][0] = 0;
    d[v][0][1] = a[v];
    d[v][1][0] = MX;
    d[v][1][1] = b[v];
    sz[v] = 1;
    for (int to : g[v]) {
        solve(to);
        forn(i, 2) forn(j, sz[v] + sz[to] + 1) {
            e[i][j] = MX;
        }
        forn(i, sz[v] + 1) forn(j, sz[to] + 1) {
            e[0][i + j] = min(e[0][i + j], d[v][0][i] + d[to][0][j]);
            e[1][i + j] = min(e[1][i + j], d[v][1][i] + min(d[to][0][j], d[to][1][j]));
        }
        forn(i, 2) forn(j, sz[v] + sz[to] + 1) {
            d[v][i][j] = e[i][j];
        }
        sz[v] += sz[to];
    }
}

int main() {
    scanf("%d%d", &n, &have);
    forn(i, n) {
        scanf("%d%d", a + i, b + i);
        b[i] = a[i] - b[i];
        if (i > 0) {
            int par;
            scanf("%d", &par), --par;
            g[par].pb(i);
        }
    }
    solve(0);
    int ans = 0;
    forn(i, n + 1) if (min(d[0][0][i], d[0][1][i]) <= have) {
        ans = i;
    }
    cout << ans << endl;
    return 0;
}