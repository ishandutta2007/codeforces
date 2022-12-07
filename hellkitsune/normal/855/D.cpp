#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int par[17][100000];
int p1[17][100000], p2[17][100000];
int tin[100000], tout[100000], timer = 0;
int used[100000];
vector<int> g[100000];
int trnum[100000];
int curnum = 0;

void dfs(int v) {
    used[v] = 1;
    trnum[v] = curnum;
    tin[v] = timer++;
    for (int to : g[v]) if (!used[to]) {
        dfs(to);
    }
    tout[v] = timer++;
}

bool isParent(int par, int v) {
    return tin[par] <= tin[v] && tout[par] >= tout[v];
}

int main() {
    scanf("%d", &n);
    forn(i, n) {
        int ty;
        scanf("%d%d", par[0] + i, &ty);
        if (par[0][i] != -1) {
            --par[0][i];
            g[par[0][i]].pb(i);
        }
        if (ty == 0) {
            p1[0][i] = 1;
        } else if (ty == 1) {
            p2[0][i] = 1;
        }
    }
    forn(i, 16) forn(j, n) {
        if (par[i][j] == -1) {
            par[i + 1][j] = -1;
        } else {
            par[i + 1][j] = par[i][par[i][j]];
        }
        if (par[i + 1][j] != -1) {
            p1[i + 1][j] = p1[i][j] | p1[i][par[i][j]];
            p2[i + 1][j] = p2[i][j] | p2[i][par[i][j]];
        }
    }
    forn(i, n) if (!used[i]) {
        ++curnum;
        dfs(i);
    }
    int q;
    scanf("%d", &q);
    forn(_, q) {
        int qt, u, v;
        scanf("%d%d%d", &qt, &u, &v), --u, --v;
        if (u == v || trnum[u] != trnum[v]) {
            printf("NO\n");
            continue;
        }
        if (qt == 1) {
            if (!isParent(u, v)) {
                printf("NO\n");
                continue;
            }
            bool ok = true;
            for (int i = 16; i >= 0; --i) {
                if (par[i][v] != -1 && !isParent(par[i][v], u)) {
                    ok = ok && !p2[i][v];
                    v = par[i][v];
                }
            }
            ok = ok && !p2[0][v];
            if (ok) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            bool ok = true;
            int vv = v;
            if (!isParent(v, u)) {
                for (int i = 16; i >= 0; --i) {
                    if (par[i][v] != -1 && !isParent(par[i][v], u)) {
                        ok = ok && !p1[i][v];
                        v = par[i][v];
                    }
                }
                ok = ok && !p1[0][v];
            } else {
                ok = false;
            }
            v = vv;
            if (!isParent(u, v)) {
                for (int i = 16; i >= 0; --i) {
                    if (par[i][u] != -1 && !isParent(par[i][u], v)) {
                        ok = ok && !p2[i][u];
                        u = par[i][u];
                    }
                }
                ok = ok && !p2[0][u];
            }
            if (ok) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}