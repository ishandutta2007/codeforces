#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int d[100000][3][11];
int n, m, k, x;
vector<int> g[100000];
int p[11], np[11];

void dfs(int v, int par) {
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
    }
    forn(i, 11) p[i] = 0;
    p[0] = k - 1;
    for (int to : g[v]) if (to != par) {
        forn(i, 11) np[i] = 0;
        forn(i, 11) forn(j, 11 - i) {
            np[i + j] = (np[i + j] + p[i] * ((LL)d[to][0][j] + d[to][1][j] + d[to][2][j])) % MOD;
        }
        forn(i, 11) p[i] = np[i];
    }
    forn(i, 11) d[v][0][i] = p[i];

    forn(i, 11) p[i] = 0;
    p[1] = 1;
    for (int to : g[v]) if (to != par) {
        forn(i, 11) np[i] = 0;
        forn(i, 11) forn(j, 11 - i) {
            np[i + j] = (np[i + j] + (LL)p[i] * d[to][0][j]) % MOD;
        }
        forn(i, 11) p[i] = np[i];
    }
    forn(i, 11) d[v][1][i] = p[i];

    forn(i, 11) p[i] = 0;
    p[0] = m - k;
    for (int to : g[v]) if (to != par) {
        forn(i, 11) np[i] = 0;
        forn(i, 11) forn(j, 11 - i) {
            np[i + j] = (np[i + j] + (LL)p[i] * (d[to][0][j] + d[to][2][j])) % MOD;
        }
        forn(i, 11) p[i] = np[i];
    }
    forn(i, 11) d[v][2][i] = p[i];
}

int main() {
    if (0) {
        mt19937 mt(123);
        n = 100000;
        m = 987654321;
        for (int i = 1; i < n; ++i) {
            int from = i;
            int to = mt() % i;
            g[from].pb(to);
            g[to].pb(from);
        }
        k = 333333333;
        x = 10;
    } else {
        scanf("%d%d", &n, &m);
        forn(i, n - 1) {
            int from, to;
            scanf("%d%d", &from, &to), --from, --to;
            g[from].pb(to);
            g[to].pb(from);
        }
        scanf("%d%d", &k, &x);
    }
    dfs(0, -1);
    int ans = 0;
    forn(i, x + 1) forn(j, 3) {
        ans = (ans + d[0][j][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}