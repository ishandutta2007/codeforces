#include <bits/stdc++.h>
using namespace std;

const int maxn = 150010;
int n, q, fa[maxn], dep[maxn], deg[maxn], len[maxn];
int C, sum[maxn], mx[maxn][26], up[maxn], up_ch[maxn], cnt[maxn][26];
char s[5], c[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d %s", &fa[i], s), c[i] = s[0];
        dep[i] = dep[fa[i]] + 1, deg[fa[i]]++;
    }
    for (int i = n; i > 1; i--) {
        if (len[fa[i]] && len[fa[i]] != len[i] + 1) {
            while (q--) puts("Fou");
            exit(0);
        }
        len[fa[i]] = len[i] + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[fa[i]] > 1 || fa[i] <= 1) {
            up[i] = fa[i], up_ch[i] = i;
        } else {
            up[i] = up[fa[i]], up_ch[i] = up_ch[fa[i]];
        }
        if (i > 1 && c[i] ^ '?') cnt[up_ch[i]][c[i] - 'a']++;
    }
    for (int i = n; i > 1; i--) if (deg[i] ^ 1) {
        for (int j = 0; j < 26; j++) {
            mx[up[i]][j] = max(mx[up[i]][j], mx[i][j] + cnt[up_ch[i]][j]);
        }
        G[up[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = accumulate(mx[i], mx[i] + 26, 0);
        if (sum[i] > len[i]) C++;
    }
    auto upd = [&](int v, int c) {
        for (; v; v = up[v]) {
            if (sum[v] > len[v]) C--;
            sum[v] -= mx[v][c], mx[v][c] = 0;
            for (int u : G[v]) {
                mx[v][c] = max(mx[v][c], mx[u][c] + cnt[up_ch[u]][c]);
            }
            if ((sum[v] += mx[v][c]) > len[v]) C++;
        }
    };
    while (q--) {
        int v, ans = 0;
        scanf("%d %s", &v, s);
        if (c[v] ^ '?') cnt[up_ch[v]][c[v] - 'a']--, upd(up[v], c[v] - 'a');
        c[v] = s[0];
        if (c[v] ^ '?') cnt[up_ch[v]][c[v] - 'a']++, upd(up[v], c[v] - 'a');
        if (C) { puts("Fou"); continue; }
        for (int i = 0; i < 26; i++) {
            ans += (i + 1) * (len[1] + mx[1][i] - sum[1]);
        }
        printf("Shi %d\n", ans);
    }
    return 0;
}