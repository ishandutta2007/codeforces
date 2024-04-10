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
    int total, mx;
    int lg, rg;
    bool lout, rout;

    TRes(): total(0) {}

    TRes(bool lft) {
        total = 1;
        mx = 1;
        lg = rg = 1;
        lout = lft;
        rout = !lft;
    }
};

ostream &operator<<(ostream &out, const TRes &res) {
    return out << res.total << ' ' << res.mx << ' ' << res.lg << ' ' << res.lout << ' ' << res.rg << ' ' << res.rout;
}

TRes operator+(const TRes &l, const TRes &r) {
    if (!l.total) return r;
    if (!r.total) return l;
    TRes res;
    res.total = l.total + r.total;
    res.mx = max(l.mx, r.mx);
    res.lg = l.lg + (l.lg == l.total && (r.lout || l.rout) ? r.lg : 0);
    res.rg = r.rg + (r.rg == r.total && (r.lout || l.rout) ? l.rg : 0);
    if (res.lg == res.total) res.rg = res.total;
    if (res.rg == res.total) res.lg = res.total;
    uax(res.mx, res.lg); uax(res.mx, res.rg);
    res.lout = l.lout;
    res.rout = r.rout;
    if (l.rout || r.lout) uax(res.mx, l.rg + r.lg);
//    cerr << l << "\n+\n" << r << "\n+\n" << res << "\n---\n";;
    return res;
}

struct TNode {
    int L, R;
    int l, r;
    TRes res[2];
    int val;
};

const int maxn = 510000;
TNode t[2 * maxn];
string s;

int tc = 0;

#define dn TNode &n = t[node]

void addval(int node) {
    dn;
    swap(n.res[0], n.res[1]);
    n.val ^= 1;
}

void push(int node) {
    dn;
    if (!n.val) return;
    addval(n.l);
    addval(n.r);
    n.val = 0;
}

void relax(int node) {
    dn;
    forn(z, 2) n.res[z] = t[n.l].res[z] + t[n.r].res[z];
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {{}, {}}, 0};
    if (R - L == 1) {
        n.res[0] = TRes(s[L] == '<');
        n.res[1] = TRes(s[L] == '>');
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void segflip(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node);
        return;
    }
    push(node);
    segflip(n.l, L, R);
    segflip(n.r, L, R);
    relax(node);
}

TRes query(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return TRes();
    if (L <= n.L && n.R <= R) return n.res[0];
    push(node);
    return query(n.l, L, R) + query(n.r, L, R);
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
    cin >> n >> q >> s;
    int root = buildTree(0, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        segflip(root, l, r);
        auto res = query(root, l, r);
//        cerr << res.total << ' ' << res.mx << ' ' << res.lg << ' ' << res.lout << ' ' << res.rg << ' ' << res.rout << '\n';
        cout << res.mx << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}