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
    bool any;
    i64 L, R;
    i64 lset, rx;
    i64 sumb, minb;
};

TRes setv0(TRes res, i64 v0) {
    i64 L = (res.any ? res.lset : res.R) - res.L;
    if (!res.any) res.rx = v0;
    res.lset = res.L;
    res.any = true;
    res.sumb += L * v0;
    res.minb = min(0LL, res.minb + L * v0);
    return res;
}

TRes operator+(const TRes &a, TRes b) {
    if (!a.any) {
        TRes res = b;
        res.L = a.L;
        return res;
    }
    b = setv0(b, a.rx);
    return {
        true,
        a.L,
        b.R,
        a.lset,
        b.rx,
        a.sumb + b.sumb,
        min(a.minb, a.sumb + b.minb)
    };
}

struct TNode {
    int L, R;
    int l, r;
    TRes res;
};

const int maxn = 310000;
TNode t[2 * maxn];

int tc = 0;
vi64 xs;
vector<TRes> ress, emptys;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) {
        n.res = {false, xs[L], xs[R], 0, 0, 0, 0};
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void setres(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.res = ress[i];
        return;
    }
    setres(n.l, i);
    setres(n.r, i);
    relax(node);
}

bool query(int node, int L, int R, i64 &b0, i64 &v0, ld &ans) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return false;
    if (L <= n.L && n.R <= R) {
        TRes res = setv0(n.res, v0);
        if (b0 + res.minb > 0) {
            b0 += res.sumb;
            v0 = res.rx;
            return false;
        }
    }
    if (n.R - n.L == 1) {
        TRes res = setv0(n.res, v0);
        assert(b0 + res.minb <= 0);
        ans = res.L - (b0 ? 1.0 * b0 / res.rx : 0.0);
        return true;
    }
    if (query(n.l, L, R, b0, v0, ans)) return true;
    if (query(n.r, L, R, b0, v0, ans)) return true;
    return false;
}

struct TQuery {
    int type;
    i64 L, R;
    i64 v;
};

int index(i64 x) {
    return lower_bound(all(xs), x) - xs.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int Q;
    cin >> Q;
    vector<TQuery> qs(Q);
    for (auto &q: qs) {
        cin >> q.type;
        if (q.type == 1) {
            cin >> q.L >> q.v;
            xs.pb(q.L);
        }
        if (q.type == 2) {
            cin >> q.L;
            xs.pb(q.L);
        }
        if (q.type == 3) {
            cin >> q.L >> q.R >> q.v;
            xs.pb(q.L); xs.pb(q.R);
        }
    }

    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    xs.pb(2e9);

    ress.resize(xs.size() - 1);
    emptys.resize(xs.size() - 1);
    
    forn(i, xs.size() - 1) {
        ress[i] = emptys[i] = {
            false,
            xs[i],
            xs[i + 1],
            0, 0, 0, 0
        };
    }

    int root = buildTree(0, xs.size() - 1);
    for (auto &q: qs) {
//        cerr << q.type << ' ' << q.L << '\n';
        if (q.type == 1) {
            int i = index(q.L);
            ress[i] = setv0(emptys[i], q.v);
            setres(root, i);
        }
        if (q.type == 2) {
            int i = index(q.L);
            ress[i] = emptys[i];
            setres(root, i);
        }
        if (q.type == 3) {
            i64 b0 = q.v;
            i64 v0 = 0;
            ld ans;
            if (!b0) {
                cout << q.L << '\n';
                continue;
            }
            if (query(root, index(q.L), index(q.R), b0, v0, ans)) {
                assert(!isnan(ans) && !isinf(ans));
                cout << ans << '\n';
            }
            else cout << -1 << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}