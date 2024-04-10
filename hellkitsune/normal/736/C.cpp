#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n, k;
vector<int> g[100];
int d[100][25], f[100][25];
int nd[25], nf[25];

void add(int &x, LL y) {
    x = (x + y) % MOD;
}

void dfs(int v, int par) {
    memset(d[v], 0, sizeof d[v]);
    memset(f[v], 0, sizeof f[v]);
    d[v][0] = 1;
    f[v][0] = 1;
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
        memset(nd, 0, sizeof nd);
        memset(nf, 0, sizeof nf);
//        cerr << "d:"; forn(i, k + 1) cerr << ' ' << d[v][i]; cerr << endl;
//        cerr << "f:"; forn(i, k + 1) cerr << ' ' << f[v][i]; cerr << endl;
//        cerr << "d:"; forn(i, k + 1) cerr << ' ' << d[to][i]; cerr << endl;
//        cerr << "f:"; forn(i, k + 1) cerr << ' ' << f[to][i]; cerr << endl;
        forn(i, k + 1) forn(j, k + 1) {
            if (j < k) {
                add(nd[max(i, j + 1)], (LL)d[v][i] * d[to][j]);
            }

            if (i + 1 + j <= k) {
                add(nf[j + 1], (LL)d[v][i] * f[to][j]);
            } else {
                add(nd[i], (LL)d[v][i] * f[to][j]);
            }

            if (i + 1 + j <= k) {
                add(nf[i], (LL)f[v][i] * d[to][j]);
            } else if (j < k) {
                add(nd[j + 1], (LL)f[v][i] * d[to][j]);
            }

            add(nf[min(i, j + 1)], (LL)f[v][i] * f[to][j]);
        }
        memcpy(d[v], nd, sizeof nd);
        memcpy(f[v], nf, sizeof nf);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to);
        --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    int ans = 0;
    forn(i, k + 1) {
        add(ans, f[0][i]);
    }
    cout << ans << endl;
    return 0;
}