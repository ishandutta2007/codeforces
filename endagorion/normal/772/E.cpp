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

const int maxn = 2100;
vi e[maxn];
int par[maxn];
int ban[maxn], w[maxn];
int root;

int vc;
int n;

char query(int a, int b, int c) {
    cout << a << ' ' << b << ' ' << c << endl;
    char res;
    cin >> res;
    return res;
}

void insert_above(int v, int u) {
    int node = vc++;
    if (par[u] == -1) root = node;
    else {
        for (int &x: e[par[u]]) if (x == u) x = node;
    }
    par[node] = par[u];
    par[u] = par[v] = node;
    e[node] = {v, u};
}

int any_leaf(int v) {
    if (v < n) return v;
    return any_leaf(e[v][0]);
}

int unbanned_root(int v) {
    if (v == root || ban[par[v]]) return v;
    return unbanned_root(par[v]);
}

vi subt;

int dfsw(int v) {
    if (ban[v]) return 0;
    w[v] = 1;
    subt.pb(v);
    for (int u: e[v]) w[v] += dfsw(u);
    return w[v];
}

int findp(int root, int leaf) {
    root = unbanned_root(root);
    subt.clear();
    dfsw(root);
//    cerr << leaf << ' ' << root << ' ' << subt.size() << '\n';
    if (subt.size() == 1) return root;
    int C = -1;
    for (int v: subt) {
        if (2 * (w[root] - w[v]) > w[root]) continue;
        bool ok = true;
        for (int u: e[v]) ok &= 2 * w[u] <= w[root];
        if (ok) C = v;
    }
    assert(C != -1);
    int a = any_leaf(e[C][0]), b = any_leaf(e[C][1]);
    char res = query(a, b, leaf);
    if (res == 'X') {
        for (int u: e[C]) ban[u] = 1;
        return findp(C, leaf);
    }
    if (res == 'Y') {
        ban[C] = 1;
        return findp(e[C][1], leaf);
    }
    if (res == 'Z') {
        ban[C] = 1;
        return findp(e[C][0], leaf);
    }
    assert(false);
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    vc = n + 1;
    par[1] = -1;
    root = 1;
    fore(i, 2, n) {
//        cerr << i << '\n';
//        cerr << "root = " << root << '\n';
//        forn(i, vc) if (!e[i].empty()) {
//            for (int j: e[i]) cerr << i << ' ' << j << '\n';
//        }
        forn(j, vc) ban[j] = 0;
        insert_above(i, findp(root, i));
    }
    cout << -1 << endl;
    for1(i, vc - 1) cout << par[i] << ' ';
    cout << endl;

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}