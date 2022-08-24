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

struct TRes {
    int mina;
    int gmx, lmx, rmx, smx;

    TRes operator+(TRes r) const {
        if (mina < r.mina) return {mina, max(gmx, r.gmx), lmx, max(rmx, r.gmx), smx};
        else if (mina > r.mina) return {r.mina, max(gmx, r.gmx), max(gmx, r.lmx), r.rmx, r.smx};
        else return {mina, max(gmx, r.gmx), lmx, r.rmx, smx + max(rmx, r.lmx) + r.smx};
    }
};

struct TNode {
    int L, R;
    int l, r;
    int val;
    TRes res;
};

const int maxn = 410000;
int tc = 0;
TNode t[maxn];
int n, q;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0, {0, 0, 0, 0, 0}};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void addval(int node, int val) {
    dn;
    n.val += val;
    n.res.mina += val;
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = 0;
}

void addseg(int node, int L, int R, int delta) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, delta);
        return;
    }
    push(node);
    addseg(n.l, L, R, delta);
    addseg(n.r, L, R, delta);
    n.res = t[n.l].res + t[n.r].res;
}

void changenum(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.res.lmx = n.res.gmx = x;
        return;
    }
    push(node);
    changenum(n.l, i, x);
    changenum(n.r, i, x);
    n.res = t[n.l].res + t[n.r].res;
}

int a[maxn];
set<int> occs[maxn];

int root;

void update_num(int x, bool undo) {
    if (occs[x].empty()) return;
    addseg(root, *occs[x].begin(), *occs[x].rbegin(), undo ? -1 : 1);
    changenum(root, *occs[x].begin(), undo ? 0 : occs[x].size());
}

void print(int node) {
    if (node == -1) return;
    dn;
    cerr << n.L << ' ' << n.R << ' ' << n.res.mina << ' ' << n.res.gmx << ' ' << n.res.lmx << ' ' << n.res.rmx << ' ' << n.res.smx << '\n';
    print(n.l);
    print(n.r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> q;
    for1(i, n) {
        cin >> a[i];
        occs[a[i]].insert(i);
    }
    root = buildTree(0, n + 2);
    forn(i, maxn) update_num(i, false);
    cout << n - t[root].res.smx << '\n';
//    print(root);
    forn(i, q) {
        int p, x;
        cin >> p >> x;
        if (x != a[p]) {
            update_num(x, true);
            update_num(a[p], true);
            occs[a[p]].erase(p);
            occs[x].insert(p);
            update_num(x, false);
            update_num(a[p], false);
            a[p] = x;
        }
        auto r = t[root].res;
        assert(r.mina == 0 && r.lmx == 0 && r.rmx == 0);
        cout << n - t[root].res.smx << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}