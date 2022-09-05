#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
ll m, ans;
char s[maxn];
int tot = 1, lst = 1, len[maxn], fa[maxn], ch[maxn][4], tr[4][4];
bool f[maxn], g[maxn];

void ins(int c) {
    int p = lst, np = lst = ++tot;
    len[np] = len[p] + 1;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p) { fa[np] = 1; return; }
    int q = ch[p][c];
    if (len[q] == len[p] + 1) {
        fa[np] = q;
    } else {
        int nq = ++tot; len[nq] = len[p] + 1;
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        fa[nq] = fa[q], fa[q] = fa[np] = nq;
        for (; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
    }
}

struct mat {
    ll a[4][4];

    mat operator * (const mat &o) const {
        mat A; memset(A.a, 0x3f, sizeof(A.a));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    A.a[i][k] = min(A.a[i][k], a[i][j] + o.a[j][k]);
                }
            }
        }
        return A;
    }
} A, B, pw[60];

int main() {
    scanf("%lld %s", &m, s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        ins(s[i] - 'A');
    }
    memset(tr, -1, sizeof(tr));
    for (int c = 0; c < 4; c++) {
        int cur = ch[1][c];
        if (!cur) { fill(tr[c], tr[c] + 4, 1); continue; }
        memset(f, 0, sizeof(f)), f[cur] = 1;
        for (int len = 1; ; len++) {
            memset(g, 0, sizeof(g));
            for (int i = 1; i <= tot; i++) if (f[i]) {
                for (int j = 0; j < 4; j++) {
                    if (!ch[i][j] && !~tr[c][j]) tr[c][j] = len;
                    else if (ch[i][j]) g[ch[i][j]] = 1;
                }
            }
            memcpy(f, g, sizeof(g));
            bool flag = 1;
            for (int i = 0; i < 4; i++) {
                if (!~tr[c][i]) {
                    flag = 0;
                } else {
                    for (int j = 0; j < 4; j++) {
                        if (!~tr[c][j]) tr[c][j] = len + 1;
                    }
                }
            }
            if (flag) break;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) B.a[i][j] = tr[i][j];
    }
    pw[0] = B;
    for (int i = 1; i < 60; i++) {
        pw[i] = pw[i - 1] * pw[i - 1];
    }
    memset(A.a, 0x3f, sizeof(A.a));
    memset(A.a[0], 0, sizeof(A.a[0]));
    for (int i = 59; ~i; i--) {
        mat C = A * pw[i];
        if (*min_element(C.a[0], C.a[0] + 4) >= m) continue;
        A = C, ans |= 1LL << i;
    }
    printf("%lld\n", ans + 1);
    return 0;
}