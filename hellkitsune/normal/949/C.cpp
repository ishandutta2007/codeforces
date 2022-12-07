#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, h;
vector<int> g[100000], rev[100000];
int u[100000];
vector<int> ord, cmp, save;
bool used[100000];
int mark[100000];
int col;

void dfs1(int v) {
    used[v] = true;
    for (int to : g[v]) if (!used[to]) {
        dfs1(to);
    }
    ord.pb(v);
}

void dfs2(int v) {
    used[v] = true;
    cmp.pb(v);
    for (int to : rev[v]) if (!used[to]) {
        dfs2(to);
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &h);
    forn(i, n) scanf("%d", u + i);
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        if ((u[from] + 1) % h == u[to]) {
            g[from].pb(to);
            rev[to].pb(from);
        }
        if ((u[to] + 1) % h == u[from]) {
            g[to].pb(from);
            rev[from].pb(to);
        }
    }
    forn(i, n) used[i] = false;
    forn(i, n) if (!used[i]) {
        dfs1(i);
    }
    forn(i, n) used[i] = false;
    reverse(ord.begin(), ord.end());
    for (int v : ord) if (!used[v]) {
        cmp.clear();
        dfs2(v);
        ++col;
        for (int x : cmp) {
            mark[x] = col;
        }
        bool ok = true;
        for (int x : cmp) for (int to : g[x]) {
            if (mark[to] != col) {
                ok = false;
            }
        }
        if (ok && (save.empty() || save.size() > cmp.size())) {
            save = cmp;
        }
    }
    printf("%d\n", (int)save.size());
    for (int x : save) {
        printf("%d ", x + 1);
    }
    puts("");
    return 0;
}