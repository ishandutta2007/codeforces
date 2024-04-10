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

struct TNode {
    int L, R;
    int l, r;
    int sum;
};

const int maxn = 110000, LOG = 20;
TNode t[4 * LOG * maxn];

int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.sum = t[n.l].sum + t[n.r].sum;
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

int copyNode(int node) {
    int nnode = tc++;
    t[nnode] = t[node];
    return nnode;
}

int addi(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return node;
    int nnode = copyNode(node);
    if (n.R - n.L == 1) {
        t[nnode].sum += x;
        return nnode;
    }
    t[nnode].l = addi(n.l, i, x);
    t[nnode].r = addi(n.r, i, x);
    relax(nnode);
    return nnode;
}

int segsum(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return 0;
    if (L <= n.L && n.R <= R) return n.sum;
    return segsum(n.l, L, R) + segsum(n.r, L, R);
}

int roots[maxn];

vi e[maxn];
int tin[maxn], tout[maxn];
int up[LOG + 1][maxn];
int h[maxn];
int T = 0;

int rpath_at(int t, int v) {
    return segsum(roots[t], 0, tin[v] + 1);
}

void dfs0(int v, int p) {
    tin[v] = T++;
    up[0][v] = p;
    for (int u: e[v]) {
        h[u] = h[v] + 1;
        dfs0(u, v);
    }
    tout[v] = T;
}

int jmp(int v, int h) {
    forn(j, LOG) {
        if (!((h >> j) & 1)) continue;
        v = up[j][v];
    }
    return v;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(v, u);
    v = jmp(v, h[v] - h[u]);
    if (v == u) return v;
    ford(j, LOG) {
        int vv = up[j][v], uu = up[j][u];
        if (vv != uu) v = vv, u = uu;
    }
    return up[0][v];
}

int dist(int v, int u) {    
    int w = lca(v, u);
    return h[v] + h[u] - 2 * h[w];
}

int towards(int v, int u, int d) {
    int w = lca(v, u);
    int D = h[v] + h[u] - 2 * h[w];
    assert(d <= D);
    if (d <= h[v] - h[w]) return jmp(v, d);
    return jmp(u, D - d);
}

int attack_on_path(int t, int v, int u) {
    int w = lca(v, u);
    int ans = rpath_at(t, v) + rpath_at(t, u) - rpath_at(t, w);
    if (h[w]) ans -= rpath_at(t, up[0][w]);
    return ans;
}

int attack_on_path_between(int t1, int t2, int v, int u) {
    return attack_on_path(t2, v, u) - attack_on_path(t1, v, u);
}

struct TQuery {
    int type;
    int a, b, k, y;

    void read() {
        cin >> type;
        if (type == 1) cin >> a, --a;
        else {
            cin >> a >> b >> k >> y;
            --a; --b;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;

    int R = -1;
    forn(i, n) {
        int p;
        cin >> p;
        --p;
        if (p >= 0) e[p].pb(i);
        else R = i;
    }

    dfs0(R, R);
    forn(j, LOG) forn(v, n) up[j + 1][v] = up[j][up[j][v]];

    roots[0] = buildTree(0, n);

    int m;
    cin >> m;
    vector<TQuery> qs(m);
    forn(i, m) {
        qs[i].read();
        int &nr = roots[i + 1];
        nr = roots[i];
        if (qs[i].type == 1) {
            int v = qs[i].a;
            nr = addi(nr, tin[v], 1);
            nr = addi(nr, tout[v], -1);
        }
    }

    forn(i, m) {
        auto &q = qs[i];
        if (q.type == 1) continue;
        int v = q.a, u = q.b;
        int D = dist(v, u);
        if (D < 2) {
            cout << -1 << '\n';
            continue;
        }
        D -= 2;
        v = towards(v, u, 1);
        u = towards(u, v, 1);
        if (D + 1 - attack_on_path_between(q.y, i, v, u) < q.k) {
            cout << -1 << '\n';
            continue;
        }
        int L = -1, R = D;
        while (R - L > 1) {
            int M = (L + R) / 2;
            int w = towards(v, u, M);
            int fr = M + 1 - attack_on_path_between(q.y, i, v, w);
//            cerr << v << ' ' << u << ' ' << q.y << ' ' << i << ' ' << M << ' ' << fr << ' ' << q.k << '\n';
            (fr < q.k ? L : R) = M;
        }
//        cerr << R << '\n';
        cout << towards(v, u, R) + 1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}