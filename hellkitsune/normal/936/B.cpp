#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, s;
vector<int> g[200000];
bool used[200000][2];
int path[200005], cnt = 0;

bool mark(int v, int st) {
    path[cnt++] = v;
    used[v][st] = true;
    if (g[v].empty() && st == 1) {
        return true;
    }
    for (int to : g[v]) if (!used[to][st ^ 1]) {
        if (mark(to, st ^ 1)) {
            return true;
        }
    }
    --cnt;
    return false;
}

bool checkWin() {
    if (!mark(s, 0)) {
        return false;
    }
    printf("Win\n");
    forn(i, cnt) printf("%d ", path[i] + 1);
    puts("");
    return true;
}

int vis[200000];

bool dfs(int v) {
    vis[v] = 1;
    for (int to : g[v]) if (vis[to] == 1) {
        return true;
    } else if (vis[to] == 0) {
        if (dfs(to)) {
            return true;
        }
    }
    vis[v] = 2;
    return false;
}

bool checkDraw() {
    return dfs(s);
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        int cnt;
        scanf("%d", &cnt);
        forn(j, cnt) {
            int v;
            scanf("%d", &v), --v;
            g[i].pb(v);
        }
    }
    scanf("%d", &s), --s;
    if (checkWin()) {
        return 0;
    }
    if (checkDraw()) {
        printf("Draw\n");
    } else {
        printf("Lose\n");
    }
    return 0;
}