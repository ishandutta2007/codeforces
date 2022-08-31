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
    pii x;
};

const int maxn = 510000;
TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

int a[maxn], comp_until[maxn];

void relax(int node) {
    dn;
    n.x = max(t[n.l].x, t[n.r].x);
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) {
        n.x = {a[L], L};
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
//    cerr << L << ' ' << R << ' ' << n.x.fi << ' ' << n.x.se << '\n';
    return node;
}

pii segmax(int node, int L, int R) {
    dn;
//    cerr << L << ' ' << R << ' ' << n.L << ' ' << n.R << ' ' << n.x.fi << ' ' << n.x.se << '\n';
    if (max(L, n.L) >= min(R, n.R)) return {-1, -1};
    if (L <= n.L && n.R <= R) return n.x;
    return max(segmax(n.l, L, R), segmax(n.r, L, R));
}

void clear(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.x = {-1, -1};
        return;
    }
    clear(n.l, i);
    clear(n.r, i);
    relax(node);
}

int vis[maxn];
vi ord;
int root;

int n;

void dfs(int v) {
    if (v >= n || vis[v]) return;
    vis[v] = 1;
    clear(root, v);
    dfs(a[v]);
    while (1) {
        auto p = segmax(root, 0, comp_until[v]);
//        cerr << v << ' ' << p.fi << ' ' << p.se << '\n';
        if (p.fi <= v) break;
//        cerr << v << ' ' << p.se << '\n';
        dfs(p.se);
    }
    ord.pb(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif
    
    cin >> n;
    forn(i, n) comp_until[i] = n;
    forn(i, n) {
        cin >> a[i];
        --a[i];
        if (a[i] < 0) a[i] = n;
        if (a[i] < n) comp_until[a[i]] = i;
    }

    root = buildTree(0, n);
    forn(v, n) if (!vis[v]) dfs(v);
    
    reverse(all(ord));
    vi ans(n);
    forn(i, n) ans[ord[i]] = i;
    for (int x: ans) cout << x + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}