#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, pre[maxn][26], nxt[maxn][26], cnt[26][maxn], sum[26][maxn];
int f[maxn][26], g[maxn][26];
char s[maxn];
vector<array<int, 2>> V0[maxn], V1[maxn];

void add(int *c, int p, int v) {
    for (; p <= n; p += p & -p) c[p] ^= v;
}

int query(int *c, int p) {
    int s = 0;
    for (; p; p -= p & -p) s ^= c[p];
    return s;
}

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
        pre[i][s[i] - 'a'] = i;
    }
    for (int i = n; i; i--) {
        memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
        nxt[i][s[i] - 'a'] = i;
    }
    for (int c = 0; c < 26; c++) {
        for (int i = 1; i <= n; i++) {
            cnt[c][i] = cnt[c][i - 1] + (s[i] == c + 'a');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int c = 0; c < 26; c++) if (s[i] ^ (c + 'a')) {
            if (nxt[i][c]) V0[nxt[i][c] - i].push_back({i, c});
            if (pre[i][c]) V1[i - pre[i][c]].push_back({i, c});
        }
    }
    auto calc = [&](int l, int r) {
        static bool vis[32];
        memset(vis, 0, sizeof(vis));
        for (int c = 0; c < 26; c++) if (cnt[c][r] > cnt[c][l - 1]) {
            int s = query(sum[c], pre[r][c]) ^ query(sum[c], nxt[l][c]);
            vis[f[l][c] ^ g[r][c] ^ s] = 1;
        }
        int ans = 0;
        while (vis[ans]) ans++;
        return ans;
    };
    for (int i = 1; i <= n; i++) {
        for (auto &p : V0[i]) {
            int l = p[0], r = nxt[l][p[1]] - 1;
            f[l][p[1]] = calc(l, r);
            if (l > 1 && s[l - 1] == s[r + 1]) add(sum[s[l - 1] - 'a'], l, f[l][p[1]]);
        }
        for (auto &p : V1[i]) {
            g[p[0]][p[1]] = calc(pre[p[0]][p[1]] + 1, p[0]);
        }
    }
    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        puts(calc(l, r) ? "Alice" : "Bob");
    }
    return 0;
}