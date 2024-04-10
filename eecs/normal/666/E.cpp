#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010, maxm = 100010;
int n, m, q, num, rt[maxm], pos[maxn], mxl[maxn];
int tot = 1, lst, len[maxm], fa[maxm], ch[maxm][26], par[20][maxm];
char s[maxn], str[maxm];
struct node { int l, r; pair<int, int> mx; } t[maxm * 30];
pair<int, int> ans[maxn];
vector<int> G[maxm];
vector<tuple<int, int, int>> Q[maxm];

#define mid (l + r >> 1)
void ins(int &k, int l, int r, int p) {
    if (!k) k = ++num;
    if (l == r) { t[k].mx.first++, t[k].mx.second = -l; return; }
    mid >= p ? ins(t[k].l, l, mid, p) : ins(t[k].r, mid + 1, r, p);
    t[k].mx = max(t[t[k].l].mx, t[t[k].r].mx);
}

int merge(int k1, int k2, int l, int r) {
    if (!k1 || !k2) return k1 | k2;
    if (l == r) { t[k1].mx.first += t[k2].mx.first; return k1; }
    t[k1].l = merge(t[k1].l, t[k2].l, l, mid);
    t[k1].r = merge(t[k1].r, t[k2].r, mid + 1, r);
    t[k1].mx = max(t[t[k1].l].mx, t[t[k1].r].mx);
    return k1;
}

pair<int, int> query(int k, int l, int r, int ql, int qr) {
    if (!k || l >= ql && r <= qr) return t[k].mx;
    pair<int, int> ans(-1, 0);
    if (mid >= ql) ans = query(t[k].l, l, mid, ql, qr);
    if (mid < qr) ans = max(ans, query(t[k].r, mid + 1, r, ql, qr));
    return ans;
}

void extend(int c) {
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

int main() {
    scanf("%s %d", s + 1, &m), n = strlen(s + 1);
    for (int i = 1; i <= m; i++) {
        scanf("%s", str + 1);
        int len = strlen(str + 1);
        for (int j = lst = 1; j <= len; j++) {
            extend(str[j] - 'a'), ins(rt[lst], 1, m, i);
        }
    }
    for (int i = 1, cur = 1, l = 0; i <= n; i++) {
        int c = s[i] - 'a';
        while (cur && !ch[cur][c]) cur = fa[cur], l = len[cur];
        if (ch[cur][c]) cur = ch[cur][c], l++;
        else cur = 1, l = 0;
        pos[i] = cur, mxl[i] = l;
    }
    for (int i = 2; i <= tot; i++) {
        G[par[0][i] = fa[i]].push_back(i);
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 2; j <= tot; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int l, r, ql, qr;
        scanf("%d %d %d %d", &l, &r, &ql, &qr);
        ql = qr - ql + 1;
        if (mxl[qr] < ql) { ans[i].second = -l; continue; }
        qr = pos[qr];
        for (int j = 19; ~j; j--) {
            if (len[par[j][qr]] >= ql) qr = par[j][qr];
        }
        Q[qr].emplace_back(l, r, i);
    }
    function<void(int)> dfs = [&](int v) {
        for (int u : G[v]) {
            dfs(u), rt[v] = merge(rt[v], rt[u], 1, m);
        }
        for (auto p : Q[v]) {
            ans[get<2>(p)] = query(rt[v], 1, m, get<0>(p), get<1>(p));
            if (!ans[get<2>(p)].first) ans[get<2>(p)].second = -get<0>(p);
        }
    };
    dfs(1);
    for (int i = 1; i <= q; i++) {
        printf("%d %d\n", -ans[i].second, ans[i].first);
    }
    return 0;
}