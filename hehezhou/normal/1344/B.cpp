#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1010][1010];
int dfn[1000010], low[1000010], sta[1000010], id[1000010], insta[1000010];
int top;
struct edge {
    int u, v, nxt;
} e[1000010 * 4];
int head[1000010], tot;
inline void addedge(int u, int v) {
    e[++tot] = edge{u, v, head[u]};
    head[u] = tot;
}
int idcnt;
inline void tarjan(int now) {
    static int dfsnow = 0;
    dfn[now] = low[now] = ++dfsnow;
    insta[now] = 1;
    sta[++top] = now;
    for (int i = head[now]; i; i = e[i].nxt) {
        if (!dfn[e[i].v]) tarjan(e[i].v);
        if (insta[e[i].v]) low[now] = min(low[now], low[e[i].v]);
    }
    if (low[now] == dfn[now]) {
        idcnt++;
        do {
            id[sta[top]] = idcnt;
            insta[sta[top]] = 0;
        } while (sta[top--] != now);
    }
}
int getid(int x, int y) {
    return x * m + y + 1;
}
int has[1010][1010];
int tag[1000010];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) has[i][j] = 1;
    for (int i = 0; i < n; i++) {
        int tag = -1;
        for (int j = 0; j < m; j++) {
            if (tag == -1 && s[i][j] == '#') tag = 0;
            if (tag == 0 && s[i][j] == '.') tag = 1;
            if (tag == 1) has[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int tag = -1;
        for (int j = m - 1; j >= 0; j--) {
            if (tag == -1 && s[i][j] == '#') tag = 0;
            if (tag == 0 && s[i][j] == '.') tag = 1;
            if (tag == 1) has[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int tag = -1;
        for (int j = 0; j < n; j++) {
            if (tag == -1 && s[j][i] == '#') tag = 0;
            if (tag == 0 && s[j][i] == '.') tag = 1;
            if (tag == 1) has[j][i] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int tag = -1;
        for (int j = n - 1; j >= 0; j--) {
            if (tag == -1 && s[j][i] == '#') tag = 0;
            if (tag == 0 && s[j][i] == '.') tag = 1;
            if (tag == 1) has[j][i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int tag = 0;
        for (int j = 0; j < m; j++) {
            tag |= has[i][j];
        }
        if (tag == 0) return puts("-1"), 0;
    }
    for (int i = 0; i < m; i++) {
        int tag = 0;
        for (int j = 0; j < n; j++) {
            tag |= has[j][i];
        }
        if (tag == 0) return puts("-1"), 0;
    }
    for (int i = 0; i < n; i++) {
        int tag = 0;
        for (int j = 0; j < m - 1; j++) {
            if (has[i][j]) tag = 1;
            if (s[i][j] == '#' && s[i][j + 1] == '#') addedge(getid(i, j + 1), getid(i, j));
        }
    }
    for (int i = 0; i < n; i++) {
        int tag = 0;
        for (int j = m - 1; j > 0; j--) {
            if (has[i][j]) tag = 1;
            if (s[i][j] == '#' && s[i][j - 1] == '#') addedge(getid(i, j - 1), getid(i, j));
        }
    }
    for (int i = 0; i < m; i++) {
        int tag = 0;
        for (int j = 0; j < n - 1; j++) {
            if (has[j][i]) tag = 1;
            if (s[j][i] == '#' && s[j + 1][i] == '#') addedge(getid(j + 1, i), getid(j, i));
        }
    }
    for (int i = 0; i < m; i++) {
        int tag = 0;
        for (int j = n - 1; j > 0; j--) {
            if (has[j][i]) tag = 1;
            if (s[j][i] == '#' && s[j - 1][i] == '#') addedge(getid(j - 1, i), getid(j, i));
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (!dfn[getid(i, j)] && s[i][j] == '#') tarjan(getid(i, j));
    for (int i = 1; i <= tot; i++) {
        if (id[e[i].u] != id[e[i].v]) tag[id[e[i].v]] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= idcnt; i++) if (tag[i] == 0) ans++;
    return cout << ans << endl, 0;
}