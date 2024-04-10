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
    int l, r;
    pii x;
    int y;
    int cut, sz;
    int lx, rx;
};

const int NOCUT = -2e9;

const int maxn = 410000;
TNode t[maxn];

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.sz = 1 + t[n.l].sz + t[n.r].sz;
    n.cut = NOCUT;
    n.lx = n.rx = n.x.fi;
    if (n.l) {
        n.lx = t[n.l].lx;
        if (t[n.l].cut != NOCUT) n.cut = t[n.l].cut;
        if (t[n.l].rx + 1 < n.x.fi) n.cut = n.x.fi - 1;
    }
    if (n.r) {
        n.rx = t[n.r].rx;
        if (t[n.r].cut != NOCUT) n.cut = t[n.r].cut;
        if (t[n.r].lx - 1 > n.x.fi) n.cut = n.x.fi + 1;
    }
}

int merge(int l, int r) {
    if (!l) return r;
    if (!r) return l;
    if (t[l].y < t[r].y) {
        t[l].r = merge(t[l].r, r);
        relax(l);
        return l;
    } else {
        t[r].l = merge(l, t[r].l);
        relax(r);
        return r;
    }
}

pii split(int node, pii x) {
    if (!node) return {0, 0};
    dn;
    pii res;
    if (n.x < x) {
        res = split(n.r, x);
        n.r = res.fi;
        res.fi = node;
    } else {
        res = split(n.l, x);
        n.l = res.se;
        res.se = node;
    }
    relax(node);
    return res;
}

int tc = 1;

void print(int node) {
    if (!node) return;
    dn;
    print(n.l);
    cerr << node << ' ' << n.x.fi << ' ' << n.x.se << ' ' << n.sz << ' ' << n.cut << '\n';
    print(n.r);
}

int newNode(pii p) {
    int node = tc++;
    dn;
    n = {0, 0, p, rand(), NOCUT, 1, p.fi, p.fi};
    return node;
}

int insert(int node, int n) {
//    print(n);
    pii res = split(node, t[n].x);
    return merge(res.fi, merge(n, res.se));
}

pii erase(int node, pii p) {
    pii r1 = split(node, p);
    ++p.se;
    pii r2 = split(r1.se, p);
    return mp(merge(r1.fi, r2.se), r2.fi);
}

pii opp(pii p) {
    swap(p.fi, p.se);
    return p;
}

void separate(int node, int &from, int &to) {
    if (!node) return;
    dn;
    pii p = opp(n.x);
    pii f1 = erase(from, p);
    from = f1.fi;
    to = insert(to, f1.se);
    separate(n.l, from, to);
    separate(n.r, from, to);
}


int comps(int rx, int ry) {
    if (!rx) return 0;
/*    print(rx);
    cerr << "---\n";
    print(ry);
    cerr << "---\n";*/
    forn(z, 2) {
        if (t[rx].cut != NOCUT) {
            pii hx = split(rx, mp(t[rx].cut, 0));
            if (t[hx.fi].sz > t[hx.se].sz) swap(hx.fi, hx.se);
            int oy = 0;
            separate(hx.fi, ry, oy);
            return comps(hx.fi, oy) + comps(hx.se, ry);
        }

        swap(rx, ry);
    }
    return 1;
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
    int rx = 0, ry = 0;
    forn(i, n) {
        pii p;
        cin >> p.fi >> p.se;
        rx = insert(rx, newNode(p));
        ry = insert(ry, newNode(opp(p)));
/*        print(rx);
        cerr << "---\n";
        print(ry);
        cerr << "---\n";*/
    }

    cout << comps(rx, ry) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}