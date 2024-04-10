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
    set<int> cover;
};

const int maxn = 410000;
TNode t[maxn];
int tc = 0;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void toggle_seg(int node, int L, int R, int id, bool add) {
    if (!node) {
//        cerr << (add ? '+' : '-') << ' ' << L << ' ' << R << ' ' << id << '\n';
    }
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        if (add) n.cover.insert(id);
        else n.cover.erase(id);
        return;
    }
    toggle_seg(n.l, L, R, id, add);
    toggle_seg(n.r, L, R, id, add);
}

int par[maxn], l[maxn], r[maxn];
int root(int v) {
    if (v == -1) return v;
    return v == par[v] ? v : par[v] = root(par[v]);
}

int unite(int u, int v) {
    u = root(u); v = root(v);
    if (u == -1) return v;
    if (v == -1) return u;
    if (u == v) return u;
    par[u] = v;
    uin(l[v], l[u]);
    uax(r[v], r[u]);
    return v;
}

int unite_point(int node, int x) {
    dn;
    if (x < n.L || x >= n.R) return -1;
    int res = -1;
    vi cover(all(n.cover));
    for (int id: cover) {
        toggle_seg(0, l[id], r[id], id, false);
        res = unite(id, res);
    }
    res = unite(res, unite_point(n.l, x));
    res = unite(res, unite_point(n.r, x));
    return res;
}

struct Query {
    int type;
    i64 l, r;
};

const i64 INF = 1e9;

template<class T>
int index(const vector<T> &v, const T &x) {
    return lower_bound(all(v), x) - v.begin();
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
    vi64 xs;
    vector<Query> qs(n);
    forn(i, n) {
        int type;
        i64 l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            l *= INF; r *= INF;
            l += n - i;
            r -= n - i;
            xs.pb(l); xs.pb(r);
        } else --l, --r;
        qs[i] = {type, l, r};
    }
    sort(all(xs));
    buildTree(0, xs.size());

    int id = 0;
    forn(i, n) {
        if (qs[i].type == 1) {
            int li = index(xs, qs[i].l);
            int ri = index(xs, qs[i].r);
//            cerr << i << ' ' << li << ' ' << ri << '\n';
            par[id] = id;
            l[id] = li;
            r[id] = ri;
            int comp = unite(id, unite(unite_point(0, li), unite_point(0, ri)));
            toggle_seg(0, l[comp], r[comp], comp, true);
            ++id;
        } else {
            int u = qs[i].l, v = qs[i].r;
            swap(u, v);
            u = root(u); v = root(v);
            cout << (l[u] <= l[v] && r[v] <= r[u] ? "YES" : "NO") << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}