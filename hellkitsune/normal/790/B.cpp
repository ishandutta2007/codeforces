#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
vector<int> g[200000];
int mo[200000][5], save[200000][5];
LL sum[200000], ssum[200000];
int sz[200000], ssz[200000];
LL ans = 0;

inline int nx(int i) {
    return (i == k - 1) ? 0 : (i + 1);
}

void dfs(int v, int par) {
    forn(i, k) mo[v][i] = 0;
    mo[v][0] = 1;
    sum[v] = 0;
    sz[v] = 1;
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
        forn(i, k) {
            int j = nx(i);
            mo[v][j] += mo[to][i];
        }
        sz[v] += sz[to];
        sum[v] += sum[to] + sz[to];
    }
}

void solve(int v, int par) {
    LL cur = sum[v];
    for (int i = 1; i < k; ++i) {
        cur += LL(k - i) * mo[v][i];
    }
    assert(cur % k == 0);
    ans += cur / k;
    for (int to : g[v]) if (to != par) {
        forn(i, k) {
            save[v][i] = mo[v][i];
        }
        ssum[v] = sum[v];
        ssz[v] = sz[v];

        forn(i, k) {
            int j = nx(i);
            mo[v][j] -= mo[to][i];
        }
        sum[v] -= sum[to] + sz[to];
        sz[v] -= sz[to];
        forn(i, k) {
            int j = nx(i);
            mo[to][j] += mo[v][i];
        }
        sum[to] += sum[v] + sz[v];
        sz[to] += sz[v];

        solve(to, v);

        forn(i, k) {
            mo[v][i] = save[v][i];
        }
        sum[v] = ssum[v];
        sz[v] = ssz[v];
    }
}

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    solve(0, -1);
    assert(ans % 2 == 0);
    ans /= 2;
    cout << ans << endl;
    return 0;
}