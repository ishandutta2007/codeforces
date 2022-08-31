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

const int LOG = 20, maxn = 210000;
pii hs[LOG + 1][2 * maxn];

int T = 0;
vi e[maxn];
int tin[maxn], tout[maxn];
int h[maxn];
int l2[2 * maxn];

void dfs(int v, int p, int h) {
    tin[v] = T;
    ::h[v] = h;
    hs[0][T++] = {h, v};
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v, h + 1);
        hs[0][T++] = {h, v};
    }
}

pii sparseQ(int L, int R) {
    int k = l2[R - L];
    return min(hs[k][L], hs[k][R - (1 << k)]);
}

int lca(int v, int u) {
    int tv = tin[v], tu = tin[u];
    if (tv > tu) swap(tv, tu);
    return sparseQ(tv, tu + 1).se;
}

int dist(int v, int u) {
    return h[v] + h[u] - 2 * h[lca(v, u)];
}

int closeP(int v, int u, int w) {
    int cands[] = {u, lca(v, u), lca(v, w), lca(u, w)};
    int res = v;
    forn(i, 4) {
        int c = cands[i];
        if (dist(v, c) + dist(c, u) == dist(v, u) && dist(w, c) < dist(w, res)) res = c;
    }
    return res;
}

bool interP(int a, int b, int c, int d) {
    int e = closeP(a, b, c);
    return dist(c, d) == dist(c, e) + dist(e, d);
}

struct TPathStuff {
    bool allInter;
    int v, u;
};

TPathStuff operator+(TPathStuff s1, TPathStuff s2) {
    if (s1.v == -1) return s2;
    if (s2.v == -1) return s1;
    if (!s1.allInter && !s2.allInter) {
        int cands[] = {s1.v, s1.u, s2.v, s2.u};
        int v1 = s1.v, v2 = s1.u;
        forn(i, 4) forn(j, i) {
            int u1 = cands[i], u2 = cands[j];
            if (dist(u1, u2) > dist(v1, v2)) v1 = u1, v2 = u2;
        }
        return {false, v1, v2};
    }
    if (s1.allInter && s2.allInter) {
        if (interP(s1.v, s1.u, s2.v, s2.u)) return {true, closeP(s1.v, s1.u, s2.v), closeP(s1.v, s1.u, s2.u)};
        else return {false, closeP(s2.v, s2.u, s1.v), closeP(s1.v, s1.u, s2.v)};
    }
    if (s1.allInter && !s2.allInter) swap(s1, s2);
    if (interP(s1.v, s1.u, s2.v, s2.u)) return s1;
    int cands[] = {s1.v, s1.u, closeP(s2.v, s2.u, s1.v)};
    int v = s1.v, u = s1.u;
    forn(i, 3) forn(j, i) {
        int vv = cands[i], uu = cands[j];
        if (dist(vv, uu) > dist(v, u)) v = vv, u = uu;
    }
    return {false, v, u};
}

vector<pii> ps;

struct TNode {
    int L, R;
    int l, r;
    TPathStuff res;
};

#define dn TNode &n = t[node]

TNode t[2 * maxn];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {true, -1, -1}};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

void change(int node, int i, TPathStuff s) {
    dn;
    if (n.L > i || n.R <= i) return;
    if (n.R - n.L == 1) {
        n.res = s;
        return;
    }
    change(n.l, i, s);
    change(n.r, i, s);
    relax(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif
    
    int n, q;
    cin >> n >> q;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(0, -1, 0);
    forn(j, LOG) forn(i, T - (1 << j)) hs[j + 1][i] = min(hs[j][i], hs[j][i + (1 << j)]);
    for1(i, T) {
        l2[i] = l2[i - 1];
        while ((2 << l2[i]) <= i) ++l2[i];
    }

    map<pii, vi> plst;
    vi type(q);
    vi id(q);
    forn(i, q) {
        cin >> type[i];
        if (type[i] == 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            if (u > v) swap(u, v);
            id[i] = ps.size();
            ps.pb({u, v});
            plst[{u, v}].pb(id[i]);
        } else if (type[i] == 2) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            if (u > v) swap(u, v);
            int toD = plst[{u, v}].back();
            plst[{u, v}].pop_back();
            id[i] = toD;
        } else cin >> id[i];
    }

    int root = buildTree(0, ps.size());

    forn(i, q) {
        if (type[i] == 3) {
            TPathStuff res = t[root].res;
            cout << (res.allInter || dist(res.v, res.u) <= 2 * id[i] ? "Yes" : "No") << '\n';
        } else change(root, id[i], type[i] == 1 ? TPathStuff({true, ps[id[i]].fi, ps[id[i]].se}) : TPathStuff({true, -1, -1}));
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}