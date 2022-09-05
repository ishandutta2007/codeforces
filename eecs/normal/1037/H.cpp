#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, cnt, rt[maxn];
int tot = 1, lst = 1, ch[maxn][26], fa[maxn], len[maxn];
char s[maxn];
vector<int> G[maxn];
struct node { int l, r; } t[maxn * 100];

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

#define mid ((l + r) >> 1)
void ins(int &k, int l, int r, int p) {
    if (!k) k = ++cnt;
    if (l < r) mid >= p ? ins(t[k].l, l, mid, p) : ins(t[k].r, mid + 1, r, p);
}

int merge(int k1, int k2) {
    if (!k1 || !k2) return k1 | k2;
    int o = ++cnt;
    t[o].l = merge(t[k1].l, t[k2].l);
    t[o].r = merge(t[k1].r, t[k2].r);
    return o;
}

bool test(int k, int l, int r, int ql, int qr) {
    if (!k) return 0;
    if (l >= ql && r <= qr) return 1;
    if (mid >= ql && test(t[k].l, l, mid, ql, qr)) return 1;
    if (mid < qr && test(t[k].r, mid + 1, r, ql, qr)) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s + 1, n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        ins(s[i] - 'a'), ins(rt[lst], 1, n, i);
    }
    for (int i = 2; i <= tot; i++) {
        G[fa[i]].push_back(i);
    }
    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) {
            dfs(v), rt[u] = merge(rt[u], rt[v]);
        }
    };
    dfs(1);
    cin >> q;
    while (q--) {
        int l, r, ans = 0, pos = -1, foo;
        string t;
        cin >> l >> r >> t;
        auto chk = [&](int u, int len) {
            return u > 1 && r - l + 1 >= len && test(rt[u], 1, n, l + len - 1, r);
        };
        int cur = 1;
        for (int i = 0; i < t.size(); i++) {
            for (int c = t[i] - 'a' + 1; c < 26; c++) if (chk(ch[cur][c], i + 1)) {
                if (i > pos) pos = i, foo = c;
                ans = 1; break;
            }
            cur = ch[cur][t[i] - 'a'];
            if (!cur) break;
        }
        if (cur) {
            for (int i = 0; i < 26; i++) if (chk(ch[cur][i], t.size() + 1)) {
                if ((int)t.size() > pos) pos = t.size(), foo = i;
                ans = 1; break;
            }
        }
        if (!ans) ans = -1;
        if (!~ans) cout << "-1\n";
        else cout << string(t.begin(), t.begin() + pos) << char(foo + 'a') << "\n";
    }
    return 0;
}