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

map<int, int> en;

bool lucky(int x) {
    if (!x) return true;
    int d = x % 10;
    if (d != 4 && d != 7) return false;
    return lucky(x / 10);
}

int get_id(int x) {
    if (!en.count(x)) {
        int z = en.size();
        en[x] = z;
    }
    return en[x];
}

const int maxn = 110000;
int a[maxn];
vi pos[maxn];
vi allpos;

vi segs;

struct TRes {
    i64 len, pref, suf, seg;

    TRes()
        : len(0)
        , pref(0)
        , suf(0)
        , seg(0)
    {
    }

    TRes(i64 x)
        : len(x)
        , pref(x)
        , suf(x)
        , seg(x * (x + 1) / 2)
    {
    }

    TRes operator+(const TRes &r) const {
        TRes res;
        res.seg = seg + r.seg + suf * r.pref;
        res.len = len + r.len;
        res.pref = pref + (pref == len ? r.pref : 0LL);
        res.suf = r.suf + (r.suf == r.len ? suf : 0LL);
        return res;
    }

    void ban() {
        pref = suf = seg = 0;
    }
};

struct TNode {
    int L, R;
    int l, r;
    TRes res;
};

TNode t[10000];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

void ban_leaf(int node) {
    dn;
    assert(n.R - n.L == 1);
    n.res.ban();
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) {
//        cerr << L << '\n';
        n.res = TRes(segs[L]);
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void ban(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        ban_leaf(node);
        return;
    }
    ban(n.l, i);
    ban(n.r, i);
    relax(node);
}

TRes query(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return TRes();
    if (L <= n.L && n.R <= R) return n.res;
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

    int n;
    cin >> n;

    int C = 0;
    forn(i, n) {
        int x;
        cin >> x;
        if (lucky(x)) {
            a[i] = get_id(x);
            pos[a[i]].pb(C++);
            allpos.pb(i);
        } else a[i] = -1;
    }

    i64 ans = 0;
    {
        int fr = 0;
        ford(i, n) {
            if (a[i] == -1) ++fr;
            else fr = 0;
            ans += 1LL * i * (i + 1) / 2 * fr;
        }
    }

    {
        int fr = 0;
        forn(i, n) {
            if (a[i] == -1) ++fr;
            else {
                segs.pb(fr);
                segs.pb(1);
                fr = 0;
            }
        }
        segs.pb(fr);

//        for (int x: segs) cerr << x << ' ';
//        cerr << '\n';
    }

//    cerr << ans << '\n';

//    cerr << allpos.size() << ' ' << segs.size() << ' ' << en.size() << '\n';
    
    forn(l, allpos.size()) {
//        cerr << l << '\n';
        vi banned(en.size());
        tc = 0;
        int root = buildTree(0, segs.size());
        for (int r = l; r < allpos.size(); ++r) {
//            cerr << r << '\n';
            int x = a[allpos[r]];
//            cerr << allpos[r] << '\n';
//            cerr << x << ' ' << banned.size() << '\n';
            if (!banned[x]) {
                banned[x] = 1;
                for (int p: pos[x]) {
//                    cerr << "ban " << p << '\n';
                    ban(root, 2 * p + 1);
                }
            }
            TRes res = query(root, 0, 2 * l + 1);
            assert(2 * r + 2 < segs.size());
            i64 p = segs[2 * l], s = segs[2 * r + 2];
            i64 S = res.seg;
            i64 fp = res.suf;
            assert(fp >= p);
            S -= fp * (fp + 1) / 2;
            S *= (p + 1);
            i64 ex = (p + 1) * (p * p - p * (3 * fp + 1) + 3 * fp * (fp + 1));
            assert(ex % 6 == 0);
            ex /= 6;
            S += ex;
//            cerr << allpos[l] << ' ' << allpos[r] << ' ' << S << ' ' << s + 1 << ' ' << ex << '\n';
//            cerr << "res = " << res.len << ' ' << res.pref << ' ' << res.suf << ' ' << res.seg << '\n';

            ans += S * (s + 1);
        }
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}