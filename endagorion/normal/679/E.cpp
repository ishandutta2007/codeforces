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

pii operator+(pii a, pii b) {
    if (a > b) swap(a, b);
    if (a.se == b.fi) a.se = b.se;
    return a;
}

struct TRes {
    i64 x;
    pii seg;

    TRes operator+(const TRes &r) {
        if (x != r.x) return x > r.x ? *this : r;
        return {x, seg + r.seg};
    }
};

struct TNode {
    int L, R;
    int l, r;
    TRes res;
    i64 val_assign, val_add;
};

const int maxn = 110000, LOG = 12;
TNode t[2 * maxn * LOG];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

void addval(int node, i64 assign, i64 add) {
    dn;
    if (assign != -1) {
        n.val_assign = assign;
        n.val_add = 0;
        n.res = {assign, {n.L, n.R}};
    } else {
        n.res.x += add;
        if (n.val_assign != -1) n.val_assign += add;
        else n.val_add += add;
    }
}

void push(int node) {
    dn;
    addval(n.l, n.val_assign, n.val_add);
    addval(n.r, n.val_assign, n.val_add);
    n.val_assign = -1;
    n.val_add = 0;
}

const i64 INF = 1e18;

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, TRes(), -1, 0};
    if (R - L == 1) {
        n.res = {-INF, {L, R}};
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void modify_seg(int node, int L, int R, i64 assign, i64 add) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, assign, add);
        return;
    }
    push(node);
    modify_seg(n.l, L, R, assign, add);
    modify_seg(n.r, L, R, assign, add);
    relax(node);
}

TRes query_max(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return {0LL, {-1, -1}};
    if (max(L, n.res.seg.fi) < min(R, n.res.seg.se)) {
        auto res = n.res;
        uax(res.seg.fi, L);
        uin(res.seg.se, R);
        return res;
    }
    if (L <= n.L && n.R <= R) return n.res;
    push(node);
    return query_max(n.l, L, R) + query_max(n.r, L, R);
}

int roots[LOG];
i64 pw42[LOG];

int root_id(i64 x) {
    return lower_bound(pw42, pw42 + LOG, x) - pw42 - 1;
}

void assign(int L, int R, i64 x) {
    forn(j, LOG) modify_seg(roots[j], L, R, -INF, 0);
    int k = root_id(x);
    modify_seg(roots[k], L, R, x, 0);
}

void repeat_add(int L, int R, i64 x) {
    while (1) {
        bool repeat = false;
        forn(j, LOG - 1) {
            while (1) {
                auto res = query_max(roots[j], L, R);
                auto [l, r] = res.seg;
                if (res.x <= 0 || res.x + x < pw42[j + 1]) break;
                if (res.x + x == pw42[j + 1]) {
//                    cerr << j << ' ' << l << ' ' << r << ' ' << res.x << ' ' << x << ' ' << pw42[j + 1] << '\n';
                    repeat = true;
                }
//                cerr << l << ' ' << r << ' ' << res.x << ' ' << pw42[j] << " -> " << pw42[j + 1] << '\n';
                modify_seg(roots[j], l, r, -INF, 0);
                modify_seg(roots[j + 1], l, r, res.x, 0);
            }
        }
        forn(j, LOG) modify_seg(roots[j], L, R, -1, x);
        if (!repeat) break;
//        cerr << "repeat\n";
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

    pw42[0] = 1;
    forn(i, LOG - 1) pw42[i + 1] = pw42[i] * 42;
//    cerr << pw42[LOG - 1] << '\n';

    int n, q;
    cin >> n >> q;
    forn(j, LOG) roots[j] = buildTree(0, n);

    forn(i, n) {
        int x;
        cin >> x;
        modify_seg(roots[root_id(x)], i, i + 1, x, 0);
    }

    forn(qi, q) {
/*        cerr << qi << '\n';
        forn(j, LOG) {
            forn(i, n) cerr << query_max(roots[j], i, i + 1).x << ' ';
            cerr << '\n';
        }*/
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            cin >> i;
            --i;
            vi64 ans;
            forn(j, LOG) {
                auto res = query_max(roots[j], i, i + 1);
                if (res.x > 0) {
//                    cerr << j << ' ' << res.x << '\n';
                    ans.pb(res.x);
                }
            }
            assert(ans.size() == 1);
            cout << ans[0] << '\n';
        } else {
            int L, R, x;
            cin >> L >> R >> x;
            --L;
            if (type == 2) assign(L, R, x);
            else repeat_add(L, R, x);
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}