#include <bits/stdc++.h>
using namespace std;

const int maxn = 810;
int T, n, m, fa[maxn], d[maxn], pre[maxn], lim[maxn], eid[22][22][2];
bool bad[maxn], mark[maxn], vis[maxn], in1[maxn], in2[maxn], ban[maxn];
vector<int> G[maxn];
char str[22][22], ans[42][42];

int id(int x, int y) {
    return (x - 1) * m + y;
}

int find(int x) {
    while (x ^ fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", str[i] + 1);
            for (int j = 1; j <= m; j++) ban[id(i, j)] = str[i][j] == 'X';
        }
        memset(mark, 0, sizeof(mark));
        memset(eid, -1, sizeof(eid));
        memset(lim, 0, sizeof(lim));
        memset(bad, 0, sizeof(bad));
        int cnt = 0;
        vector<array<int, 2>> E;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) if (str[i][j] == 'O') {
                cnt++, bad[id(i, j)] = (i + j + 1) % 2 && (i > 1 || j > 1);
                if (i < n && str[i + 1][j] == 'O') {
                    eid[i][j][0] = E.size(), E.push_back({id(i, j), id(i + 1, j)});
                    lim[id(i, j)]++, lim[id(i + 1, j)]++;
                }
                if (j < m && str[i][j + 1] == 'O') {
                    eid[i][j][1] = E.size(), E.push_back({id(i, j), id(i, j + 1)});
                    lim[id(i, j)]++, lim[id(i, j + 1)]++;
                }
            }
        }
        bool ok = 1;
        for (int i = 1; i <= n * m; i++) {
            if (bad[i] && (lim[i] -= 2) < 0) { ok = 0; break; }
        }
        if (!ok) { puts("NO"); continue; }
        while (count(mark, mark + E.size(), 0) >= cnt) {
            vector<int> I, J;
            for (int i = 0; i < E.size(); i++) {
                G[i].clear(), (mark[i] ? I : J).push_back(i);
            }
            for (int i : I) {
                fill(d + 1, d + n * m + 1, 0);
                for (int j : I) {
                    if (i ^ j) d[E[j][0]]++, d[E[j][1]]++;
                }
                for (int j : J) {
                    if (d[E[j][0]] < lim[E[j][0]] && d[E[j][1]] < lim[E[j][1]]) G[j].push_back(i);
                }
            }
            for (int i : J) {
                iota(fa + 1, fa + n * m + 1, 1);
                for (int j : J) {
                    if (i ^ j) fa[find(E[j][0])] = find(E[j][1]);
                }
                int num = 0;
                for (int j = 1; j <= n * m; j++) {
                    if (!ban[j] && j == find(j)) num++;
                }
                for (int j : I) {
                    if (num == 1 || num == 2 && find(E[j][0]) ^ find(E[j][1])) G[j].push_back(i);
                }
            }
            fill(in1, in1 + E.size(), 0);
            fill(in2, in2 + E.size(), 0);
            for (int i : J) {
                iota(fa + 1, fa + n * m + 1, 1);
                fill(d + 1, d + n * m + 1, 0);
                bool flag = 0;
                for (int j = 0; j < E.size(); j++) {
                    if (i ^ j && !mark[j]) fa[find(E[j][0])] = find(E[j][1]);
                    else if (++d[E[j][0]] > lim[E[j][0]] || ++d[E[j][1]] > lim[E[j][1]]) flag = 1;
                }
                int num = 0;
                for (int j = 1; j <= n * m; j++) {
                    if (!ban[j] && j == find(j)) num++;
                }
                in1[i] = num == 1, in2[i] = !flag;
            }
            fill(vis, vis + E.size(), 0);
            queue<int> Q;
            for (int i = 0; i < E.size(); i++) {
                if (in1[i]) Q.push(i), vis[i] = 1;
            }
            bool flag = 0;
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                if (in2[u]) {
                    while (1) {
                        mark[u] ^= 1;
                        if (in1[u]) break;
                        u = pre[u];
                    }
                    flag = 1; break;
                }
                for (int v : G[u]) if (!vis[v]) {
                    Q.push(v), vis[v] = 1, pre[v] = u;
                }
            }
            if (!flag) break;
        }
        if (count(mark, mark + E.size(), 0) >= cnt) {
            puts("NO"); continue;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans[2 * i - 1][2 * j - 1] = str[i][j];
                ans[2 * i][2 * j - 1] = ~eid[i][j][0] && mark[eid[i][j][0]] ? ' ' : 'O';
                ans[2 * i - 1][2 * j] = ~eid[i][j][1] && mark[eid[i][j][1]] ? ' ' : 'O';
                ans[2 * i][2 * j] = ' ';
            }
        }
        puts("YES");
        for (int i = 1; i < 2 * n; i++) {
            for (int j = 1; j < 2 * m; j++) putchar(ans[i][j]);
            putchar('\n');
        }
    }
    return 0;
}