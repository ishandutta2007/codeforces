#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
int n, k;
int a[N];
int to[N];
vector <int> g[N];
int ptr = 0;
int e[N];
int l[N], r[N];
void dfs(int u, int p) {
    l[u] = ptr;
    e[ptr++] = u;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }   
    }   
    r[u] = ptr;
}   
int tree[N << 2], add[N << 2];
void push(int v) {
    if (add[v]) {
        add[v * 2 + 1] += add[v];
        tree[v * 2 + 1] += add[v];
        add[v * 2 + 2] += add[v];
        tree[v * 2 + 2] += add[v];
        add[v] = 0;
        return;
    }   
}   
void upd(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        tree[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v);
    if (p <= tm) upd(v * 2 + 1, tl, tm, p, x);
    else upd(v * 2 + 2, tm + 1, tr, p, x);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
void addt(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        tree[v]++;
        add[v]++;
        return;
    }   
    int tm = (tl + tr) >> 1;
    addt(v * 2 + 1, tl, tm, l, r); addt(v * 2 + 2, tm + 1, tr, l, r);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
void addi(int i) {
    upd(0, 0, n, l[i], 0);
    addt(0, 0, n, l[i], r[i]);
}
void deli(int i) {
    upd(0, 0, n, l[i], -INF);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    a[n] = N - 1;
    vector <int> v;
    for (int i = 0; i <= n; ++i) {
        while (v.size() && a[v.back()] < a[i]) {
            to[v.back()] = i;
            v.pop_back();
        }   
        v.push_back(i);
    }   
    for (int i = 0; i < n; ++i) {
        g[to[i]].push_back(i);
        g[i].push_back(to[i]);
    }   
    dfs(n, n);
    for (int i = 0; i < (N << 2); ++i) tree[i] = -INF;
    for (int i = 0; i < k; ++i) {
        addi(i);
    }
    cout << tree[0] << ' ';
    for (int i = k; i < n; ++i) {
        addi(i);
        deli(i - k);
        cout << tree[0] << ' ';
    }   
    cout << '\n';
}