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

constexpr i64 P = 1000000000 + 7;

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

struct TNode {
    int L, R;
    int l, r;
    i64 sum, sumc, sum2;
    i64 val;
    bool touch;
};

const int maxn = 210000;
TNode t[maxn];
i64 ps[maxn];
int tc = 0;

#define dn TNode &n = t[node]

void add(i64 &x, i64 y) {
    x += y; x %= P;
}

constexpr i64 LIM = 1e18;

void add2(i64 &x, i64 y) {
    x += y;
    if (x > LIM || x < LIM) x %= P;
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0, 0, 0, 0, 0};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void addval(int node, i64 x) {
    if (!x) return;
    dn;
    add(n.val, x);
    i64 len = n.R - n.L;
    add2(n.sum2, 2 * x * n.sum + len * x % P * x);
    add(n.sum, len * x);
    add2(n.sumc, x * (ps[n.R] - ps[n.L]));
    n.touch = 1;
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = 0;
}

inline i64 cut(i64 x) {
    return x % P;
}

void relax(int node) {
    dn;
    n.sum = cut(t[n.l].sum + t[n.r].sum);
    n.sum2 = cut(t[n.l].sum2 + t[n.r].sum2);
    n.sumc = cut(t[n.l].sumc + t[n.r].sumc);
    n.touch = t[n.l].touch || t[n.r].touch;
}

void clear(int node) {
    dn;
    if (!n.touch) return;
    clear(n.l);
    clear(n.r);
    n = {n.L, n.R, n.l, n.r, 0, 0, 0, 0, 0};
}

void addseg(int node, int L, int R, i64 x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, x);
        return;
    }
    push(node);
    addseg(n.l, L, R, x);
    addseg(n.r, L, R, x);
    relax(node);
}

vi e[maxn], ne[maxn];
int w[maxn];
int tin[maxn], tout[maxn];
int pord[maxn];
int T;

void dfs0(int v, int p) {
    w[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        ne[v].pb(u);
        dfs0(u, v);
        w[v] += w[u];
    }
    sort(all(ne[v]), [&](int x, int y){return w[x] > w[y];});
}

void dfs1(int v) {
    pord[T] = v;
    tin[v] = T++;
    for (int u: ne[v]) {
        dfs1(u);
    }
    tout[v] = T;
}

i64 ans = 0;
int root;

int l[maxn], r[maxn];
i64 invl[maxn];

void update_pord(int L, int R, int z) {
    fore(i, L, R - 1) {
        int v = pord[i];
        addseg(root, l[v], r[v], z * invl[v]);
    }
}

i64 Q = 1;
        
void dfs2(int v) {
    if (!ne[v].empty()) {
        ford(i, ne[v].size()) {
            int u = ne[v][i];
            dfs2(u);
            i64 res = t[root].sumc - t[root].sum2;
//            if (res < 0) res += P;
//            cerr << u << ' ' << res * Q % P << ' ' << t[root].sumc * Q % P << ' ' << t[root].sum2 * Q % P << '\n';
            add2(ans, res);
            if (i) clear(root);//update_pord(tin[u], tout[u], -1);
        }
        update_pord(tout[ne[v][0]], tout[v], 1);
    }
    addseg(root, l[v], r[v], invl[v]);
}

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
    forn(i, n) cin >> l[i] >> r[i], ++r[i];
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    forn(i, n) {
        (Q *= r[i] - l[i]) %= P;
        i64 ilen = deg(r[i] - l[i], -1);
        invl[i] = ilen;
        add(ps[l[i] + 1], ilen);
        add(ps[r[i] + 1], -ilen);
    }
    forn(z, 2) forn(i, 100001) add(ps[i + 1], ps[i]);
    dfs0(0, -1);
    dfs1(0);
    assert(T == n);
    root = buildTree(1, 100001);
    dfs2(0);
    ans %= P;
    (ans *= Q) %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}