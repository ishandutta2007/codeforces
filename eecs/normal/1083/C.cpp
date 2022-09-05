#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, m, tim, p[maxn], q[maxn], c[maxn], dep[maxn];
int st[20][maxn], lg[maxn], id[maxn], tid[maxn];
struct node { bool ok; int u, v; } tmp, t[maxn << 1];
vector<int> G[maxn];

int lca(int u, int v) {
    if (tid[u] > tid[v]) swap(u, v);
    int l = tid[u], r = tid[v], k = lg[r - l + 1];
    return id[min(st[k][l], st[k][r - (1 << k) + 1])];
}

bool on(int u, int v, int l, int x) {
    if (u == x || v == x) return 1;
    if (u == v) return u == x;
    if (dep[x] < dep[l]) return 0;
    if (lca(u, x) == x) return 1;
    if (lca(v, x) == x) return 1;
    return 0;
}

node merge(node A, node B) {
    if (!A.ok) return A;
    if (!B.ok) return B;
    if (!A.u) return B;
    node C; C.ok = 0;
    static vector<int> V;
    V = {A.u, A.v, B.u, B.v};
    sort(V.begin(), V.end());
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            bool foo = 1;
            int t = lca(V[i], V[j]);
            for (int k : V) if (!on(V[i], V[j], t, k)) { foo = 0; break; }
            if (foo) { C.u = V[i], C.v = V[j], C.ok = 1; return C; }
        }
    }
    return C;
}

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) { t[k].ok = 1, t[k].u = t[k].v = q[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k] = merge(t[ls], t[rs]);
}

void upd(int k, int l, int r, int p1, int p2) {
    if (!(p1 >= l && p1 <= r) && !(p2 >= l && p2 <= r)) return;
    if (l == r) { t[k].ok = 1, t[k].u = t[k].v = q[l]; return; }
    upd(ls, l, mid, p1, p2), upd(rs, mid + 1, r, p1, p2);
    t[k] = merge(t[ls], t[rs]);
}

int query(int k, int l, int r) {
    if (l == r && !merge(tmp, t[k]).ok) return l - 1;
    if (l == r) return l;
    node foo = merge(tmp, t[ls]);
    if (!foo.ok) return query(ls, l, mid);
    tmp = foo; return query(rs, mid + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]), q[++p[i]] = i;
    }
    for (int i = 2; i <= 2 * n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 2, fa; i <= n; i++) {
        scanf("%d", &fa);
        G[fa].push_back(i);
        dep[i] = dep[fa] + 1;
    }
    function<void(int)> dfs = [&](int v) {
        id[tid[v] = ++tim] = v;
        for (int u : G[v]) {
            dfs(u), id[++tim] = v;
        }
    };
    dfs(1);
    for (int i = 1; i < 2 * n; i++) {
        st[0][i] = tid[id[i]];
    }
    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j + (1 << i) - 1 < 2 * n; j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    build(1, 1, n), scanf("%d", &m);
    while (m--) {
        int type, i, j; scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d", &i, &j);
            swap(q[p[i]], q[p[j]]), swap(p[i], p[j]);
            upd(1, 1, n, p[i], p[j]);
        } else {
            tmp.ok = 1, tmp.u = 0;
            printf("%d\n", query(1, 1, n));
        }
    }
    return 0;
}