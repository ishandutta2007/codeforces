#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a, b, tot, rt, cnt, p[maxn], id[maxn], d[maxn * 40], head[maxn * 40];
bool vis[maxn * 40];
bitset<maxn * 70> ew;
struct node { int l, r; } t[maxn * 40];
struct edge { int v, nxt; } e[maxn * 70];

void add_edge(int i, int j, int w) {
    if (i && j) e[++cnt] = (edge){j, head[i]}, ew[cnt] = w, head[i] = cnt;
}

#define mid ((l + r) >> 1)
void upd(int &k1, int k2, int l, int r, int p) {
    t[k1 = ++tot] = t[k2];
    if (l == r) return void(k1 = l);
    if (mid >= p) upd(t[k1].l, t[k2].l, l, mid, p);
    else upd(t[k1].r, t[k2].r, mid + 1, r, p);
}

void link(int k, int l, int r, int ql, int qr, int id) {
    if (!k || l >= ql && r <= qr) return add_edge(id, k, 1);
    if (mid >= ql) link(t[k].l, l, mid, ql, qr, id);
    if (mid < qr) link(t[k].r, mid + 1, r, ql, qr, id);
}

void upd2(int &k1, int k2, int l, int r, int p) {
    t[k1 = ++tot] = t[k2];
    if (l == r) return void(k1 = l);
    if (mid >= p) upd2(t[k1].l, t[k2].l, l, mid, p);
    else upd2(t[k1].r, t[k2].r, mid + 1, r, p);
    add_edge(t[k1].l, k1, 0), add_edge(t[k1].r, k1, 0);
}

void link2(int k, int l, int r, int ql, int qr, int id) {
    if (!k || l >= ql && r <= qr) return add_edge(k, id, 1);
    if (mid >= ql) link2(t[k].l, l, mid, ql, qr, id);
    if (mid < qr) link2(t[k].r, mid + 1, r, ql, qr, id);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        fill(head + 1, head + tot + 1, cnt = 0);
        for (int i = 1; i <= tot; i++) {
            t[i] = (node){0, 0};
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
        }
        iota(id + 1, id + n + 1, 1);
        sort(id + 1, id + n + 1, [&](int i, int j) { return p[i] > p[j]; });
        tot = n, rt = 0;
        for (int $ = 1; $ <= n; $++) {
            int i = id[$];
            upd(rt, rt, 1, n, i);
            link(rt, 1, n, max(1, i - p[i]), min(n, i + p[i]), i);
        }
        int tot1 = tot;
        rt = 0;
        for (int $ = 1; $ <= n; $++) {
            int i = id[$];
            upd2(rt, rt, 1, n, i);
            link2(rt, 1, n, max(1, i - p[i]), min(n, i + p[i]), i);
        }
        deque<int> Q;
        fill(d + 1, d + tot + 1, 1e9);
        fill(vis + 1, vis + tot + 1, 0);
        Q.push_back(a), d[a] = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop_front();
            if (vis[u]) continue;
            vis[u] = 1;
            for (int i = head[u]; i; i = e[i].nxt) {
                if (d[e[i].v] > d[u] + ew[i]) {
                    d[e[i].v] = d[u] + ew[i];
                    if (!ew[i]) Q.push_front(e[i].v);
                    else Q.push_back(e[i].v);
                }
            }
            if (u > n && u <= tot1) {
                for (int i : {t[u].l, t[u].r}) {
                    if (d[i] > d[u]) {
                        d[i] = d[u], Q.push_front(i);
                    }
                }
            }
        }
        printf("%d\n", d[b]);
    }
    return 0;
}