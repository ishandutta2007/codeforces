#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 110000, LOG = 20;
vi e[maxn];
int tin[maxn], tout[maxn];
int up[LOG + 1][maxn];
int h[maxn], sz[maxn];
int hst[maxn];

int T = 0;

void dfs0(int v, int p) {
    up[0][v] = p;
    sz[v] = 1;
    if (v) e[v].erase(find(all(e[v]), p));
    for (int u: e[v]) {
        h[u] = h[v] + 1;
        dfs0(u, v);
        sz[v] += sz[u];
    }
    sort(all(e[v]), [&](int u, int w){return sz[u] > sz[w];});
}

int ord[maxn];

void dfs_hld(int v) {
    tin[v] = T++;
    ord[tin[v]] = v;
    bool heavy = true;
    for (int u: e[v]) {
        hst[u] = (heavy ? hst[v] : u);
        dfs_hld(u);
        heavy = false;
    }
    tout[v] = T;
}

int jmp(int v, int h) {
    forn(k, LOG) {
        if (!((h >> k) & 1)) continue;
        v = up[k][v];
    }
    return v;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(v, u);
    v = jmp(v, h[v] - h[u]);
    if (v == u) return v;
    ford(k, LOG) {
        int vv = up[k][v], uu = up[k][u];
        if (vv != uu) v = vv, u = uu;
    }
    return up[0][v];
}

struct TNode {
    int L, R;
    int l, r;
    pi64 best;
    vector<pi64> lst;
    i64 val;
};

TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

void addval(int node, i64 x) {
    dn;
    n.best.fi += x;
    n.val += x;
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = 0;
}

void relax(int node) {
    dn;
    n.best = min(t[n.l].best, t[n.r].best);
}

void pop(int node) {
    dn;
    assert(n.R - n.L == 1);
    n.lst.pop_back();
    n.best = n.lst.back();
    n.best.fi += n.val;
}

vi init[maxn];
int vn[maxn];

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}, {}, 0};
    if (R - L == 1) {   
        for (int x: init[L]) n.lst.pb({x, x});
        n.lst.pb({1e18, -1});
        sort(rall(n.lst));
        n.best = n.lst.back();
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void seg_add(int node, int L, int R, i64 x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, x);
        return;
    }
    push(node);
    seg_add(n.l, L, R, x);
    seg_add(n.r, L, R, x);
    relax(node);
}

pi64 seg_best(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return {1e18, -1};
    if (L <= n.L && n.R <= R) return n.best;
    push(node);
    return min(seg_best(n.l, L, R), seg_best(n.r, L, R));
}

void pop_i(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        pop(node);
        return;
    }
    push(node);
    pop_i(n.l, i);
    pop_i(n.r, i);
    relax(node);
}

void push_path(int v, int lh, vector<pii> &p) {
    while (h[v] >= lh) {
//        cerr << v << ' ' << h[v] << ' ' << tin[v] << ' ' << hst[v] << ' ' << lh << '\n';
        int R = tin[v] + 1;
        int u = hst[v];
        int len = h[v] - max(h[u], lh) + 1;
        p.pb({R - len, R});
        v = ord[tin[v] - len + 1];
        if (!v) break;
        v = up[0][v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, q;
    cin >> n >> m >> q;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs0(0, 0);
    dfs_hld(0);
    forn(j, LOG) forn(v, n) up[j + 1][v] = up[j][up[j][v]];

    forn(i, m) {
        int v;
        cin >> v;
        --v;
        vn[i] = v;
        init[tin[v]].pb(i);
    }

    int root = buildTree(0, n);
    forn(qi, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int v, u, k;
            cin >> v >> u >> k;
            --v; --u;
            int w = lca(v, u);
            typedef pair<pi64, pii> Key;
            priority_queue<Key, vector<Key>, greater<Key> > q;
            vector<pii> segs;
            push_path(v, h[w], segs);
            push_path(u, h[w] + 1, segs);
            for (auto [L, R]: segs) {
//                cerr << L << ' ' << R << '\n';
                auto best = seg_best(root, L, R);
                if (best.fi > 1e17) continue;
                q.push({best, {L, R}});
            }

            vi ans;
            while ((int)ans.size() < k && !q.empty()) {
                auto [best, seg] = q.top();
                if (best.fi > 1e17) break;
                auto [L, R] = seg;
//                cerr << best.fi << ' ' << best.se << ' ' << L << ' ' << R << '\n';
                q.pop();
                ans.pb(best.se);
                pop_i(root, tin[vn[best.se]]);
                best = seg_best(root, L, R);
                if (best.fi > 1e17) continue;
                q.push({best, {L, R}});
            }
            cout << ans.size() << ' ';
            for (int x: ans) cout << x + 1 << ' ';
            cout << '\n';
        } else {
            int v, add;
            cin >> v >> add;
            --v;
            seg_add(root, tin[v], tout[v], add);
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}