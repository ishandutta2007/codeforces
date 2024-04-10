#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, q, tot, rt[maxn], rb[maxn], st[20][maxn], nxt[20][maxn], req[20][maxn];
vector<int> V[maxn];
struct node { int l, r, s; } t[maxn * 20];

#define mid ((l + r) >> 1)
void ins(int &k1, int k2, int l, int r, int p) {
    t[k1 = ++tot] = t[k2], t[k1].s++;
    if (l == r) return;
    if (mid >= p) ins(t[k1].l, t[k2].l, l, mid, p);
    else ins(t[k1].r, t[k2].r, mid + 1, r, p);
}

int query(int k1, int k2, int l, int r, int p) {
    if (t[k1].s == t[k2].s) return -1;
    if (l == r) return l;
    if (mid < p) {
        int v = query(t[k1].r, t[k2].r, mid + 1, r, p);
        return ~v ? v : query(t[k1].l, t[k2].l, l, mid, p);
    }
    return query(t[k1].l, t[k2].l, l, mid, p);
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l == r) continue;
        V[l].push_back(r), rb[l] = max(rb[l], r);
    }
    iota(st[0] + 1, st[0] + n + 1, 1);
    for (int k = 1; 1 << k <= n; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            int x = st[k - 1][i], y = st[k - 1][i + (1 << (k - 1))];
            st[k][i] = rb[x] > rb[y] ? x : y;
        }
    }
    auto qmax = [&](int l, int r) {
        int k = __lg(r - l + 1);
        int x = st[k][l], y = st[k][r - (1 << k) + 1];
        return rb[x] > rb[y] ? x : y;
    };
    for (int i = 1; i <= n; i++) {
        nxt[0][i] = req[0][i] = i, rt[i] = rt[i - 1];
        sort(V[i].begin(), V[i].end());
        for (int j : V[i]) {
            ins(rt[i], rt[i], 1, n, j);
            if (rb[qmax(i + 1, j)] > j && nxt[0][i] == i) {
                int l = i + 1, r = j, pos;
                while (l <= r) {
                    if (rb[qmax(i + 1, mid)] > j) r = (pos = mid) - 1;
                    else l = mid + 1;
                }
                assert(pos > i && pos <= j && rb[pos] > j);
                nxt[0][i] = pos, req[0][i] = j;
            }
        }
    }
    for (int k = 1; k < 20; k++) {
        for (int i = 1; i <= n; i++) {
            nxt[k][i] = nxt[k - 1][nxt[k - 1][i]];
            req[k][i] = max(req[k - 1][i], req[k - 1][nxt[k - 1][i]]);
        }
    }
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int cur = x;
        for (int i = 19; ~i; i--) {
            if (req[i][cur] <= y) cur = nxt[i][cur];
        }
        while (1) {
            int _cur = max(cur, query(rt[cur], rt[x - 1], 1, n, y));
            if (cur == _cur) break;
            cur = _cur;
        }
        printf("%d\n", cur);
    }
    return 0;
}