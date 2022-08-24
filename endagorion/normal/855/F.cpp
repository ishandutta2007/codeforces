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

const int INF = 2e9;

struct TRes {
    int mx[2];
    i64 c0;
    i64 sum;

    TRes() {
        mx[0] = 0;
        mx[1] = -1;
        c0 = sum = 0;
    }

    TRes(int x) {
        mx[0] = x;
        mx[1] = -1;
        c0 = 1;
        sum = x;
    }
};

TRes operator+(const TRes &a, const TRes &b) {
    TRes c;
    c.mx[0] = max(a.mx[0], b.mx[0]);
    c.c0 = 0;
    c.mx[1] = 0;
    c.sum = a.sum + b.sum;
    for (const auto &r: {a, b}) forn(z, 2) {
        int x = r.mx[z];
        if (x < c.mx[0]) uax(c.mx[1], x);
        else c.c0 += r.c0;
    }
    return c;
}

void addmin(TRes &a, int x) {
    assert(x > a.mx[1]);
    if (x >= a.mx[0]) return;
    a.sum += (x - a.mx[0]) * a.c0;
    a.mx[0] = x;
}

struct TNode {
    int L, R;
    int l, r;
    TRes res;
    int val;
};

const int maxn = 110000;
TNode t[8 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

void addval(int node, int x) {
    dn;
    addmin(n.res, x);
    uin(n.val, x);
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = INF;
}

int buildTree(int L, int R, int def) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}, INF};
    if (R - L == 1) {
        n.res = TRes(def);
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M, def);
        n.r = buildTree(M, R, def);
        relax(node);
    }
    return node;
}

void segmin(int node, int L, int R, int x) {
    dn;
    if (max(L, n.L) >= min(R, n.R) || x >= n.res.mx[0]) return;
    if (L <= n.L && n.R <= R && x > n.res.mx[1]) {
        addval(node, x);
        return;
    }
    push(node);
    segmin(n.l, L, R, x);
    segmin(n.r, L, R, x);
    relax(node);
}

i64 summin(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return 0;
    if (L <= n.L && n.R <= R) return n.res.sum;
    push(node);
    return summin(n.l, L, R) + summin(n.r, L, R);
}

void setx(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.res = TRes(x);
        return;
    }
    push(node);
    setx(n.l, i, x);
    setx(n.r, i, x);
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

    int n = 100000;
    int rs[2], ars[2];
    forn(z, 2) rs[z] = buildTree(0, n, INF);
    forn(z, 2) ars[z] = buildTree(0, n, 0);

    vector<set<int>> byCov(4);
    forn(i, n) byCov[0].insert(i);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int L, R, y;
            cin >> L >> R >> y;
            --L; --R;
            int z = 0;
            if (y < 0) y = -y, z = 1;
            segmin(rs[z], L, R, y);
            segmin(ars[z], L, R, y);
            while (1) {
                auto it = byCov[0].lower_bound(L);
                if (it == byCov[0].end() || *it >= R) break;
                int x = *it;
                byCov[0].erase(x);
                byCov[1 << z].insert(x);
            }
            int m = 1 << (z ^ 1);
            while (1) {
                auto it = byCov[m].lower_bound(L);
                if (it == byCov[m].end() || *it >= R) break;
                int x = *it;
                byCov[m].erase(x);
                byCov[3].insert(x);

                forn(z, 2) {
                    int v = summin(rs[z], x, x + 1);
//                    cerr << z << ' ' << x << " = " << v << '\n';
                    setx(ars[z], x, v);
                }
            }

/*            forn(z, 2) {
                forn(i, 4) cerr << summin(rs[z], i, i + 1) << ' ';
                cerr << '\n';
            }*/
/*            forn(z, 2) {
                forn(i, 4) cerr << summin(ars[z], i, i + 1) << ' ';
                cerr << '\n';
            }*/
        } else {
            int L, R;
            cin >> L >> R;
            --L; --R;
            i64 ans = 0;
            forn(z, 2) ans += summin(ars[z], L, R);

            cout << ans << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}