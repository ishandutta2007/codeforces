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
    int val;
    pii mxs;
};

const int maxn = 610000;
TNode t[2 * maxn];
int tc = 0;

pii operator+(pii a, pii b) {
    if (a.fi != b.fi) return max(a, b);
    return {a.fi, a.se + b.se};
}

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.mxs = t[n.l].mxs + t[n.r].mxs;
}

void addval(int node, int x) {
    dn;
    n.val += x;
    n.mxs.fi += x;
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = 0;
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0, {-1e9, 1}};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

pii get_mxs(int node, int L, int R = -1) {
    if (R == -1) R = L + 1;
    dn;
    if (max(L, n.L) >= min(R, n.R)) return {-1e9, 0};
    if (L <= n.L && n.R <= R) return n.mxs;
    push(node);
    return get_mxs(n.l, L, R) + get_mxs(n.r, L, R);
}

void add_seg(int node, int L, int R, int x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, x);
        return;
    }
    push(node);
    add_seg(n.l, L, R, x);
    add_seg(n.r, L, R, x);
    relax(node);
}

void setx(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.val = 0;
        n.mxs = {x, 1};
        return;
    }
    push(node);
    setx(n.l, i, x);
    setx(n.r, i, x);
    relax(node);
}

vi e[maxn];
int par[maxn], rpar[maxn];
int tin[maxn], tout[maxn];
int T;

void dfs0(int v) {
    tin[v] = T++;
    for (int u: e[v]) dfs0(u);
    tout[v] = T;
}

int C = 0, V = 1;
int root;

void moveCto(int v) {
//    cerr << C << " -> " << v << '\n';
    assert(v != C);
    if (tin[C] <= tin[v] && tout[v] <= tout[C]) {
//        cerr << tin[C] << ' ' << tin[v] << '\n';
//        for (int u: e[C]) cerr << tin[u] << ' ';
//        cerr << '\n';
        int ch = *--upper_bound(all(e[C]), v, [&](int v, int u){return tin[v] < tin[u];});
        add_seg(root, 0, V, 1);
        add_seg(root, tin[ch], tout[ch], -2);
        C = ch;
    } else {
        add_seg(root, 0, V, -1);
        add_seg(root, tin[C], tout[C], 2);
        C = par[C];
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

    int n;
    cin >> n;
    V = 1;
    forn(i, n) {
        int p;
        cin >> p;
        --p; p *= 2;
        forn(z, 2) {
            e[p].pb(V);
            par[V] = p;
            p = V++;
        }
    }
    dfs0(0);
    root = buildTree(0, 2 * n + 1);
    setx(root, 0, 0);

    int mD = 0;
    for1(v, 2 * n) {
        setx(root, tin[v], get_mxs(root, tin[par[v]]).fi + 1);
        if (v % 2 == 0) {
            int D = get_mxs(root, tin[v]).fi;
//            cerr << v << ' ' << D << ' ' << mD << '\n';
            if (D > mD) moveCto(v), mD = get_mxs(root, 0, V).fi;
            cout << get_mxs(root, 0, V).se << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}