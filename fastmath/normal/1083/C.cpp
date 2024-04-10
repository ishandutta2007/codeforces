#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-reorder-functions")
#pragma GCC optimize("profile-values")
#pragma GCC optimize("tracer")
#pragma GCC optimize("vpt")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int LG = 20;

int n;
vector <int> g[MAXN];
int per[MAXN];
void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> per[i];
    }   
    for (int i = 1; i < n; ++i) {
        int par;
        cin >> par;
        --par;
        g[par].push_back(i);
    }   
}

int tin[MAXN], tout[MAXN], t1 = 0, t2 = 0;
int go[MAXN][LG];
void dfs(int u, int parent) {
    go[u][0] = parent;
    for (int i = 1; i < LG; ++i) {
        go[u][i] = go[go[u][i - 1]][i - 1];
    }   
    tin[u] = t1++;
    for (int v : g[u]) {
        dfs(v, u);
    }   
    tout[u] = t2++;
}   

int mmin(int u, int v) {
    if (u == -1) return v;
    if (v == -1) return u;
    if (tout[u] < tout[v]) {
        return u;
    }   
    else {
        return v;
    }   
}   

int mn[MAXN << 2];
void updmin(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        mn[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) {
        updmin(v * 2 + 1, tl, tm, p, x);
    }   
    else {
        updmin(v * 2 + 2, tm + 1, tr, p, x);
    }   
    mn[v] = mmin(mn[v * 2 + 1], mn[v * 2 + 2]);
}   

int getmin(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -1;
    if (l <= tl && tr <= r) {
        //cout << "getmin " << tl << ' ' << tr << ' ' << mn[v] + 1 << '\n';
        return mn[v];
    }
    int tm = (tl + tr) >> 1;
    return mmin(getmin(v * 2 + 1, tl, tm, l, r), getmin(v * 2 + 2, tm + 1, tr, l, r));
}   

int mmax(int u, int v) {
    if (u == -1) return v;
    if (v == -1) return u;
    if (tin[u] > tin[v]) {
        return u;
    }   
    else {
        return v;
    }   
}   

int mx[MAXN << 2];
void updmax(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        mx[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) {
        updmax(v * 2 + 1, tl, tm, p, x);
    }   
    else {
        updmax(v * 2 + 2, tm + 1, tr, p, x);
    }   
    mx[v] = mmax(mx[v * 2 + 1], mx[v * 2 + 2]);
}   

int getmax(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -1;
    if (l <= tl && tr <= r) return mx[v];
    int tm = (tl + tr) >> 1;
    return mmax(getmax(v * 2 + 1, tl, tm, l, r), getmax(v * 2 + 2, tm + 1, tr, l, r));
}   

int mtin[MAXN << 2], mtout[MAXN << 2];
void updtin(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        mtin[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) {
        updtin(v * 2 + 1, tl, tm, p, x);
    }   
    else {
        updtin(v * 2 + 2, tm + 1, tr, p, x);
    }   
    mtin[v] = min(mtin[v * 2 + 1], mtin[v * 2 + 2]);
}   

int gettin(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return MAXN;
    if (l <= tl && tr <= r) return mtin[v];
    int tm = (tl + tr) >> 1;
    return min(gettin(v * 2 + 1, tl, tm, l, r), gettin(v * 2 + 2, tm + 1, tr, l, r));
}   

void updtout(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        mtout[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) {
        updtout(v * 2 + 1, tl, tm, p, x);
    }   
    else {
        updtout(v * 2 + 2, tm + 1, tr, p, x);
    }   
    mtout[v] = min(mtout[v * 2 + 1], mtout[v * 2 + 2]);
}   

int gettout(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return MAXN;
    if (l <= tl && tr <= r) return mtout[v];
    int tm = (tl + tr) >> 1;
    return min(gettout(v * 2 + 1, tl, tm, l, r), gettout(v * 2 + 2, tm + 1, tr, l, r));
}   

void rec(int u) {
    updmin(0, 0, n - 1, per[u], u);
    updmax(0, 0, n - 1, per[u], u);
    updtin(0, 0, n - 1, tin[u], per[u]);
    updtout(0, 0, n - 1, tout[u], per[u]);
}   

void prec() {
    dfs(0, 0);
    for (int i = 0; i < n; ++i) {
        rec(i);
    }   
}   

bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}   

int lca(int u, int v) {
    if (anc(u, v)) {
        return u;
    }   
    for (int i = LG - 1; i >= 0; --i) {
        if (!anc(go[u][i], v)) {
            u = go[u][i];
        }   
    }   
    return go[u][0];
}   

int getp(int u, int v) {
    for (int i = LG - 1; i >= 0; --i) {
        if (!anc(go[u][i], v)) {
            u = go[u][i];
        }   
    }   
    return u;    
}   

void upd(int u, int v) {
    swap(per[u], per[v]);
    rec(u); rec(v);
}

bool check(int pr) {
    int l = getmin(0, 0, n - 1, 0, pr);
    int r = getmax(0, 0, n - 1, 0, pr);
    if (l == r) {
        return 1;
    }   
    int ded = lca(l, r);
    int lp = getp(l, ded);
    int rp = getp(r, ded);
    if (gettin(0, 0, n - 1, 0, tin[ded] - 1) <= pr) return 0;
    if (gettout(0, 0, n - 1, tout[ded] + 1, n - 1) <= pr) return 0;
    return gettin(0, 0, n - 1, tin[l] + 1, tin[rp] - 1) > pr && gettout(0, 0, n - 1, tout[lp] + 1, tout[r] - 1) > pr;
}   

int get() {
    int l = 0;
    int r = n;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m)) {
            l = m;
        }   
        else {
            r = m;
        }   
    }   
    return r;
}   

void solve() {
    prec();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            upd(u, v);
        }   
        else {
            cout << get() << '\n';
        }   
    }   
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();

    #ifdef HOME
        cerr << (double)clock() / CLOCKS_PER_SEC << '\n';
    #endif

    return 0;
}