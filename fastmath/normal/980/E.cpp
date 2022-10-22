#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;
const int LG = 21;

vector <int> g[MAXN];
bool used[MAXN];

int tin[MAXN], tout[MAXN], timer = 0;

vector <int> e;
int l[MAXN], r[MAXN];

int h[MAXN];

int go[MAXN][LG];

int tree[MAXN * 4];

void jfs(int u, int parent, int d) {
    go[u][0] = parent;
    for (int i = 1; i < LG; ++i) go[u][i] = go[go[u][i - 1]][i - 1];

    h[u] = d;

    l[u] = e.size();
    e.push_back(u);

    tin[u] = timer++;
    for (int v : g[u]) {
        if (v == parent) continue;
        jfs(v, u, d + 1);
    }

    tout[u] = timer++;
    r[u] = e.size() - 1;
}

bool ch(int u, int v) {
    return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int lca(int u, int v) {
    if (ch(u, v)) return u;
    for (int i = LG - 1; i >= 0; --i) {
        if (!ch(go[u][i], v)) u = go[u][i];
    }
    return go[u][0];
}
    
int getr(int u, int v) {
    int l = lca(u, v);
    return h[u] + h[v] - 2 * h[l];
}

void push(int v) {
    tree[v * 2 + 1] = max(tree[v * 2 + 1], tree[v]);
    tree[v * 2 + 2] = max(tree[v * 2 + 2], tree[v]);
}

void upd(int v, int tl, int tr, int l, int r, int x) {
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) {
        tree[v] = max(tree[v], x);
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, x);
    upd(v * 2 + 2, tm + 1, tr, l, r, x);
}

int get(int v, int tl, int tr, int p) {
    if (tl == tr) return tree[v];
    int tm = (tl + tr) / 2;
    push(v);
    if (p <= tm) return get(v * 2 + 1, tl, tm, p);
    else return get(v * 2 + 2, tm + 1, tr, p);
}

int root = -1;

int dist(int u, int n) {
    if (used[u]) return 0;
    if (root == -1) return 1;
    int d1 = get(0, 0, n - 1, l[u]);
    if (d1 != -1) return h[u] - d1;
    return getr(u, root);
}

void add(int u, int n) {
    used[u] = true;
    if (root == -1 || h[u] < h[root]) root = u;
    upd(0, 0, n - 1, l[u], r[u], h[u]);
}

void solve(int n, int k) {
    for (int i = n - 1; i >= 0; --i) {
        int d = dist(i, n);

        if (d <= k) {
            k -= d;
            if (used[i]) continue;
            if (root == -1) {
                add(i, n);
                continue;
            }
            if (get(0, 0, n - 1, l[i]) != -1) {
                int u = i;
                while (!used[u]) {
                    add(u, n);
                    if (u == 0) break;
                    else u = go[u][0];
                }
                continue;
            }

            int l = lca(i, root);

            int u = root;
            while (true) {
                add(u, n);
                if (u == l) break;
                else u = go[u][0];
            }

            u = i;
            while (true) {
                add(u, n);
                if (u == l) break;
                else u = go[u][0];
            }

            continue;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i < MAXN * 4; ++i) tree[i] = -1;

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    jfs(0, 0, 0);
    
    solve(n, n - k);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) cout << i + 1 << ' ';
    }
    cout << '\n';
    return 0;
}