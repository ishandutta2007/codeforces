#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, ans;
int cnt, tim, tp, st[maxn], dfn[maxn], low[maxn], ind[maxn], bel[maxn];
char s[maxn], t[maxn];
vector<int> G[maxn];

int id(int x, int y) {
    return (x - 1) * m + y;
}

void tarjan(int v) {
    dfn[v] = low[v] = ++tim, st[++tp] = v;
    for (int u : G[v]) {
        if (!dfn[u]) tarjan(u), low[v] = min(low[v], low[u]);
        else if (!bel[u]) low[v] = min(low[v], dfn[u]);
    }
    if (dfn[v] == low[v]) {
        cnt++;
        for (int u = 0; u ^ v; ) u = st[tp--], bel[u] = cnt;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", t + 1);
        for (int j = 1; j <= m; j++) {
            s[id(i, j)] = t[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%*d");
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1, lst = 0; i <= n; i++) {
            if (s[id(i, j)] == '#') {
                if (lst) G[id(lst, j)].push_back(id(i, j));
                lst = i;
            }
            if (!lst) continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!x || x > n || !y || y > m || s[id(x, y)] == '.') continue;
                G[id(lst, j)].push_back(id(x, y));
            }
        }
    }
    for (int i = 1; i <= n * m; i++) if (s[i] == '#') {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n * m; i++) {
        for (int j : G[i]) if (bel[i] ^ bel[j]) {
            ind[bel[j]] = 1;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (!ind[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}